#include <Arduino.h>
#include "AudioTools.h"
#include "sound.h"

#define BUTTON_PIN 14   // Change if needed

I2SStream i2s;
AudioInfo info(48000, 2, 16);

// ---------- WAV helpers ----------
uint32_t readLE32_P(const uint8_t* p) {
  uint32_t b0 = pgm_read_byte(p + 0);
  uint32_t b1 = pgm_read_byte(p + 1);
  uint32_t b2 = pgm_read_byte(p + 2);
  uint32_t b3 = pgm_read_byte(p + 3);
  return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}

bool findWavData_P(size_t &dataOffset, size_t &dataSize) {
  if (stoppingsound_wav_len < 12) return false;

  size_t i = 12;
  while (i + 8 <= stoppingsound_wav_len) {
    uint32_t chunkId = readLE32_P(stoppingsound_wav + i);
    uint32_t chunkSize = readLE32_P(stoppingsound_wav + i + 4);

    if (chunkId == 0x61746164) { 
      dataOffset = i + 8;
      dataSize = chunkSize;
      if (dataOffset + dataSize > stoppingsound_wav_len) {
        dataSize = stoppingsound_wav_len - dataOffset;
      }
      return true;
    }
    i += 8 + chunkSize + (chunkSize & 1);
  }
  return false;
}

// ---------- Play function ----------
void playSound() {
  size_t dataOffset = 0, dataSize = 0;
  if (!findWavData_P(dataOffset, dataSize)) {
    dataOffset = 44;
    dataSize = (stoppingsound_wav_len > 44) ? (stoppingsound_wav_len - 44) : 0;
  }

  const size_t chunk = 1024;
  uint8_t buf[chunk];
  size_t pos = 0;

  while (pos < dataSize) {
    size_t n = (dataSize - pos > chunk) ? chunk : (dataSize - pos);

    for (size_t k = 0; k < n; k++) {
      buf[k] = pgm_read_byte(stoppingsound_wav + dataOffset + pos + k);
    }

    i2s.write(buf, n);
    pos += n;
  }

  // Small silence at end to avoid pop
  int16_t silence[128] = {0};
  i2s.write((uint8_t*)silence, sizeof(silence));
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button to GND

  auto cfg = i2s.defaultConfig(TX_MODE);
  cfg.pin_bck  = 27;
  cfg.pin_ws   = 26;
  cfg.pin_data = 25;
  i2s.begin(cfg);
  i2s.setAudioInfo(info);
}

void loop() {
  static bool lastState = HIGH;
  bool currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW) {
    playSound();
    delay(200); 
  }

  lastState = currentState;
}
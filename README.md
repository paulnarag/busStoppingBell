# Bus Stopping Bell

## Description
This project recreates the bus stop request bell commonly found on public buses in Singapore. When passengers press the stop button, a bell sound alerts the driver that someone wants to alight at the next bus stop. The system is built using an ESP32-C3 Super Mini microcontroller, connected to a MAX98357 I2S audio amplifier and a 3W 8Ω speaker. A 3D-printed stop button serves as the user input. When the button is pressed, the ESP32 triggers a bell sound through the speaker.

## Why This Project?
I created this project to understand embedded systems, audio playback, and 3D printing by building a familiar real-world device. This combines practical electronics, microcontroller programming, and mechanical design to recreate a nostalgic transport system experience.

## Project Images

### Completed Project
 <img src="https://stasis.hackclub-assets.com/images/1778928983810-pv883p.png" width="400">

### 3D Model - Fusion 360 Design
<img src="https://stasis.hackclub-assets.com/images/1773820621358-y7w045.png" width="400"> <img src="https://stasis.hackclub-assets.com/images/1773820630663-jpxjkz.png" width="400">

### PCB Assembly & Internal Wiring
<img src="https://stasis.hackclub-assets.com/images/1775145525803-rrc9ai.png" width="400"> 

## Wiring Diagram

For detailed wiring connections, refer to the schematic file: `schematic.fzz`

### Pin Connections

**ESP32-C3 Super Mini → MAX98357 Amplifier (I2S Audio)**
- GPIO4 → BCLK (Bit Clock)
- GPIO5 → LRC / WS (Word Select)
- GPIO6 → DIN (Data Input)
- GND → GND

**Battery → 5V Step-Up Converter**
- Battery + → 5V Step-Up IN+
- Battery - → 5V Step-Up IN-

**5V Step-Up Converter → ESP32-C3**
- OUT+ → 5V / VBUS
- OUT- → GND

**5V Step-Up Converter → MAX98357 Amplifier**
- OUT+ → VIN
- OUT- → GND

**MAX98357 Amplifier → Speaker**
- SPK+ → Speaker +
- SPK- → Speaker -

**Pushbutton → ESP32-C3**
- Button Pin 1 → GPIO3
- Button Pin 2 → GND

## Software Setup

### Required Arduino Library

This project requires the **Arduino Audio Tools** library to handle I2S audio playback.

**Installation Options:**

**Option 1: From Local Folder (Included in submission)**
1. Copy the `arduino-audio-tools` folder from the submission folder to your Arduino `libraries` folder:
   - **macOS/Linux:** `~/Arduino/libraries/`
   - **Windows:** `Documents/Arduino/libraries/`
2. Restart Arduino IDE

**Option 2: Clone from GitHub**
Clone the repository directly:
```bash
git clone https://github.com/pschatzmann/arduino-audio-tools.git ~/Arduino/libraries/arduino-audio-tools
```

### Code & Sound Files

The Arduino sketch and audio files are located in the `main` folder:
- `main.ino` - The main Arduino sketch for the ESP32-C3
- `sound.h` - Sound data file (embedded WAV audio)

Upload `main.ino` to your ESP32-C3 Super Mini using the Arduino IDE.

## Bill of Materials (BOM)

For a CSV version of the BOM, see [BOM.csv](BOM.csv)

| Component | Part Number/Description | Quantity | Supplier Link |
|-----------|------------------------|----------|---|
| Microcontroller | ESP32-C3 Super Mini | 1 | [Shopee](https://shopee.sg/ESP32-C3-MINI-Development-Board-ESP32-SuperMini-Development-Board-ESP32-C3-Development-Board-WiFi-Bluetooth-Expansion-Board-i.161750523.28701964444) |
| Audio Amplifier + Speaker | MAX98357 I2S Amplifier + 3W 4Ω Speaker | 1 | [Shopee](https://shopee.sg/MAX98357-I2S-Audio-Amplifier-Module-Speaker-3W-4-Ohm-i.223700280.26480484434) |
| Battery | 3.7V 2000mAh Lipo Rechargeable | 1 | [Shopee](https://shopee.sg/103450-3.7V-2000mAh-Lipo-Polymer-Rechargeable-Lithium-Battery-for-MP3-GPS-DVD-Recorder-Gamepad-PS4-i.1027736697.25765229548) |
| Step-Up Converter | 5V Step-Up Boost Converter | 1 | [Shopee](https://shopee.sg/DC-0.9V-5V-To-5V-or-DC-0.8V-3.3V-To-3.3V-DC-DC-Step-Up-Power-Module-Voltage-Boost-Converter-Board-i.161750523.5210810862) |
| Perfboard | Perfboard Double-Sided 50mm x 70mm | 1 | [Kuriosity](https://kuriosity.sg/products/solder-breadboard-double-sided-50mm-x-70mm) |
| Pushbutton | 6x6mm SMD Momentary Switch | 1 | — |
| Enclosure | Custom 3D-Printed ABS/PLA | 1 | — |
| Fasteners | M4 Screws & some random other small screws | 2x M4 2x small  | — |
| Wiring | 24 AWG Solid Wire | As needed | — |

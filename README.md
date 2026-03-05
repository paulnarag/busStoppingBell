# Bus Stopping Bell
This project recreates the bus stop request bell commonly found on public buses in Singapore. When passengers press the stop button, a bell sound alerts the driver that someone wants to alight at the next bus stop.

The system is built using an ESP32-C3 Super Mini microcontroller, connected to a MAX98357 I2S audio amplifier and a 3W 8Ω speaker. A 3D-printed stop button serves as the user input. When the button is pressed, the ESP32 triggers a bell sound through the speaker.

To keep the device compact and portable, the electronics are powered by a 3.7V 2000mAh rechargeable battery and assembled on a perfboard after prototyping on a breadboard. This project combines embedded electronics, audio playback, and 3D printing to recreate a familiar real-world transport system.

## Development Log

### 27 Jan 2026 — Audio System Testing
Tested the **ESP32 with a 3W 8Ω speaker and MAX98357 I2S amplifier**.  
I used example code to turn the ESP32 into a **Bluetooth speaker** to verify that the amplifier and speaker were working correctly.

**Result**
- Successfully played audio through the speaker.

**Media**
- [Video Demo](media/jan27bluetoothspeakertokyodrift.MOV)

---

### 30 Jan 2026 — Breadboard Prototype
Connected the **button, MAX98357 amplifier, and ESP32** together on a breadboard to begin prototyping the bus stop bell system.

**Goal**
- Test if pressing the button can trigger the bell sound.

**Media**
- [Breadboard Demo](media/jan30breadboard.MOV)

---

### 5 Feb 2026 — Battery Power
Added a **3.7V 2000mAh rechargeable battery** so the device can operate without USB power.

**Media**
- [Battery Setup](media/feb5esp32.MOV)

---

### 5 Feb 2026 — Microcontroller Optimization
Replaced the standard ESP32 with an **ESP32-C3 Super Mini** to make the circuit more compact.

**Media**
- [ESP32-C3 Upgrade](media/feb5esp32c3supermini.MOV)

---

### 7 Feb 2026 — Perfboard Assembly
Started soldering all components onto a **perfboard** to make the circuit permanent.

**Steps**
- Soldered power wires first  
- Connected ESP32, amplifier, and battery

**Media**
- [Perfboard Wiring 1](media/feb7startingtoperfboard.HEIC)
- [Perfboard Wiring 2](media/feb7powerwiresperfboard.HEIC)

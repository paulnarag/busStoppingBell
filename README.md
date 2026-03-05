# Bus Stopping Bell
This project recreates the bus stop request bell commonly found on public buses in Singapore. When passengers press the stop button, a bell sound alerts the driver that someone wants to alight at the next bus stop.

The system is built using an ESP32-C3 Super Mini microcontroller, connected to a MAX98357 I2S audio amplifier and a 3W 8Ω speaker. A 3D-printed stop button serves as the user input. When the button is pressed, the ESP32 triggers a bell sound through the speaker.

To keep the device compact and portable, the electronics are powered by a 3.7V 2000mAh rechargeable battery and assembled on a perfboard after prototyping on a breadboard. This project combines embedded electronics, audio playback, and 3D printing to recreate a familiar real-world transport system.


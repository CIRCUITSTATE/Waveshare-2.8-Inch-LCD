
# Waveshare 2.8-Inch LCD - Examples

![Waveshare 2.8-Inch LCD](/docs/images/2.8inch-Capacitive-Touch-LCD-details-9.jpg)

This repository contains example codes for testing the [**Waveshare 2.8-inch LCD**](https://www.waveshare.com/2.8inch-capacitive-touch-lcd.htm) (SKU 27579) using the [**FireBeetle-ESP32E**](https://www.dfrobot.com/product-2195.html) board. The 2.8 inch LCD from Waveshare uses the **ST7789T3** display controller and the **CST328** touch controller (in the touch version). This is a [PlatformIO](https://platformio.org) project based on the ESP32 Arduino framework.

Even though this project uses the **FireBeetle-ESP32E** board, you should be able to modify the code for any other targets relatively easily. We specifically used this board because its GDI (General Display Interface) port is compatible with the LCD's connector. A complete tutorial on this display is available in the CIRCUITSTATE website - [**Interfacing Waveshare 2.8 Inch Capacitive Touch LCD with Arduino**](https://www.circuitstate.com/tutorials/interfacing-waveshare-2-8-inch-capacitive-touch-lcd-with-arduino/)

## Specifications

- **SKU:** 27579
- **Display Size:** 2.8 inch (71.12 mm) diagonal
- **Resolution:** 240 x 320 pixels
- **Pixel Pitch:** 0.18 × 0.18 mm
- **Panel Type:** TFT
- **Color Output:** 262K
- **Operating Voltage:** 3.3V / 5V
- **Display Driver:**  ST7789T3
- **Display Interface:** 4-wire SPI
- **Touch Driver:**  CST328
- **Touch Interface:** I2C
- **Touch Type:**  Capacitive
- **Touch Points:**  5-point touch
- **Connectors:**  13-pin JST-GH & 18-pin FFC
- **Display Dimensions:**  43.20 × 57.60 mm
- **Module Size:** 50.54 × 73.06 mm

## Installation

All you need to do is clone this repository and open the project in PlatformIO. You can also directly download the ZIP file and extract it to your local machine. It is recommended to install the following software:

- [**Git**](https://git-scm.com/downloads) - for cloning the repository
- [**Visual Studio Code**](https://code.visualstudio.com/) - for editing the code
- [**PlatformIO**](https://platformio.org/install/ide?install=vscode) - for building and uploading the code to the board

After installing everything, open the project folder in VS Code. The PlatformIO extension should automatically install the required libraries and dependencies. Make sure you have an active internet connection.

## Examples

There are four examples in this project.

1. [**LCD_Test**](/src/LCD_Test) - Tests the basic functionality of the LCD by printing a "Hello World" message on the screen.
2. [**Touch_Test**](/src/Touch_Test) - Tests the touch functionality of the LCD.
3. [**Fonts_Demo**](/src/Fonts_Demo) - Shows text in different fonts.
4. [**UI_Test**](/src/UI_Test) - A simple UI test that shows a button and a label.

Each example has its own `main.cpp` file. You need to choose the build target/environment for each example to build and upload it to your board. The target can be selected from the bottom panel of the VS Code. The default target is `LCD_Test`.

## References

- [**Waveshare 2.8 inch LCD** - Product Page](https://www.waveshare.com/2.8inch-capacitive-touch-lcd.htm)
- [**Waveshare 2.8 Inch Capacitive Touch LCD** – Wiki](https://www.waveshare.com/wiki/2.8inch_Capacitive_Touch_LCD)
- [**FireBeetle-ESP32E** - Product Page](https://www.dfrobot.com/product-2195.html)
- [**Interfacing Waveshare 2.8 Inch Capacitive Touch LCD with Arduino**](https://www.circuitstate.com/tutorials/interfacing-waveshare-2-8-inch-capacitive-touch-lcd-with-arduino/)
- [**CSE_CST328** - Touch controller Arduino library from CIRCUITSTATE](https://github.com/CIRCUITSTATE/CSE_CST328)
- [**CSE_Touch** - Unified touch Arduino library from CIRCUITSTATE](https://github.com/CIRCUITSTATE/CSE_Touch)
- [**CSE_UI** - GUI Arduino library from CIRCUITSTATE](https://github.com/CIRCUITSTATE/CSE_UI)
- [**TFT_eSPI** - TFT library from Bodmer](https://github.com/Bodmer/TFT_eSPI)
- [Buy Waveshare 2.8 Inch Capacitive Touch LCD – Hubtronics](https://hubtronics.in/2.8inch-capacitive-touch-lcd)
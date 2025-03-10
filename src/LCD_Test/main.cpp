
//============================================================================================//
/*
  Filename: main.cpp [Waveshare-2.8-Inch-LCD -> LCD_Test]
  Description: Main source file for the LCD_Test example.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_CST328
  Last Modified: +05:30 17:48:12 PM 20-02-2025, Thursday
 */
//============================================================================================//

#include <SPI.h>
#include <TFT_eSPI.h> // TFT LCD library
#include <Wire.h>

//============================================================================================//
// Globals

TFT_eSPI LCD = TFT_eSPI(); // Create a new TFT driver instance

// The library defines the type "setup_t" as a struct.
// Calling LCD.getSetup(user) populates it with the settings.
setup_t user;

//============================================================================================//
// Forward Declarations

void setup (void);
void loop (void);
void printDriverInfo (void);
void printProcessorName (void);
int8_t getPinName (int8_t pin);
bool initWire (void);
bool initLCD (void);

//============================================================================================//
/**
 * @brief Setup runs once.
 * 
 */
void setup() {
  Serial.begin (115200);
  delay (1000);

  Serial.println();
  Serial.println (F("=== Waveshare 2.8 Inch LCD - LCD Test ==="));

  // Initialize everything.
  initWire();
  initLCD();

  Serial.println (F("setup [INFO]: System initialization complete."));
  Serial.println();

  delay (1000);
}

//============================================================================================//
/**
 * @brief Infinite loop.
 * 
 */
void loop() {
  LCD.fillScreen (TFT_BLACK);
  LCD.setTextSize (2);
  LCD.setTextColor (TFT_YELLOW);
  LCD.setCursor (20, 50);
  LCD.print ("Hello World");

  printDriverInfo();

  delay (1000);
}

//============================================================================================//
/**
 * @brief Initialize the I2C/Wire interface.
 * 
 * @return true Initialization successful.
 * @return false Initialization failed.
 */
bool initWire (void) {
  Serial.print (F("initWire [INFO]: Initializing I2C.. "));
  Wire.begin();
  // Wire.setSCL (PIN_I2C_SCL);
  // Wire.setSDA (PIN_I2C_SDA);
  // Wire.setClock (100000); // 100 kHz
  // Wire.begin (I2C_PERIPHERAL_ADDR); // Initialize I2C as peripheral
  
  Serial.println (F("Done."));

  return true;
}

//============================================================================================//
/**
 * @brief Initializes the LCD.
 * 
 * @return true Initialization successful.
 * @return false Initialization failed.
 */
bool initLCD (void) {
  Serial.print (F("initLCD [INFO]: Initializing LCD.. "));

  pinMode (TFT_BL, OUTPUT);
  digitalWrite (TFT_BL, LOW); // Turn off the backlight
  
  LCD.begin();
  LCD.setRotation (3);
  LCD.setFreeFont();
  LCD.fillScreen (TFT_BLACK); // Clear the screen
  delay (50);
  
  Serial.println (F("Done."));
  Serial.println (F("initLCD [INFO]: You should see \"Hello World\" printed in yellow color on the screen."));
  
  digitalWrite (TFT_BL, HIGH); // Turn on the backlight

  return true;
}

//============================================================================================//
/**
 * @brief Prints the TFT_eSPI driver information.
 * 
 */
void printDriverInfo (void) {
  LCD.getSetup (user); //

  Serial.print ("\n[code]\n");

  Serial.print ("TFT_eSPI ver = "); Serial.println(user.version);
  printProcessorName();
  #if defined (ESP32) || defined (ESP8266)
    if (user.esp < 0x32F000 || user.esp > 0x32FFFF) { Serial.print("Frequency    = "); Serial.print(ESP.getCpuFreqMHz());Serial.println("MHz"); }
  #endif
  #ifdef ESP8266
    Serial.print("Voltage      = "); Serial.print(ESP.getVcc() / 918.0); Serial.println("V"); // 918 empirically determined
  #endif
  Serial.print("Transactions = "); Serial.println((user.trans  ==  1) ? "Yes" : "No");
  Serial.print("Interface    = "); Serial.println((user.serial ==  1) ? "SPI" : "Parallel");
  #ifdef ESP8266
  if (user.serial ==  1){ Serial.print("SPI overlap  = "); Serial.println((user.overlap == 1) ? "Yes\n" : "No\n"); }
  #endif
  if (user.tft_driver != 0xE9D) // For ePaper displays the size is defined in the sketch
  {
    Serial.print("Display driver = "); Serial.println(user.tft_driver, HEX); // Hexadecimal code
    Serial.print("Display width  = "); Serial.println(user.tft_width);  // Rotation 0 width and height
    Serial.print("Display height = "); Serial.println(user.tft_height);
    Serial.println();
  }
  else if (user.tft_driver == 0xE9D) Serial.println("Display driver = ePaper\n");

  if (user.r0_x_offset  != 0)  { Serial.print("R0 x offset = "); Serial.println(user.r0_x_offset); } // Offsets, not all used yet
  if (user.r0_y_offset  != 0)  { Serial.print("R0 y offset = "); Serial.println(user.r0_y_offset); }
  if (user.r1_x_offset  != 0)  { Serial.print("R1 x offset = "); Serial.println(user.r1_x_offset); }
  if (user.r1_y_offset  != 0)  { Serial.print("R1 y offset = "); Serial.println(user.r1_y_offset); }
  if (user.r2_x_offset  != 0)  { Serial.print("R2 x offset = "); Serial.println(user.r2_x_offset); }
  if (user.r2_y_offset  != 0)  { Serial.print("R2 y offset = "); Serial.println(user.r2_y_offset); }
  if (user.r3_x_offset  != 0)  { Serial.print("R3 x offset = "); Serial.println(user.r3_x_offset); }
  if (user.r3_y_offset  != 0)  { Serial.print("R3 y offset = "); Serial.println(user.r3_y_offset); }

  if (user.pin_tft_mosi != -1) { Serial.print("MOSI    = "); Serial.print("GPIO "); Serial.println(getPinName(user.pin_tft_mosi)); }
  if (user.pin_tft_miso != -1) { Serial.print("MISO    = "); Serial.print("GPIO "); Serial.println(getPinName(user.pin_tft_miso)); }
  if (user.pin_tft_clk  != -1) { Serial.print("SCK     = "); Serial.print("GPIO "); Serial.println(getPinName(user.pin_tft_clk)); }

  #ifdef ESP8266
  if (user.overlap == true)
  {
    Serial.println("Overlap selected, following pins MUST be used:");

                              Serial.println("MOSI     = SD1 (GPIO 8)");
                              Serial.println("MISO     = SD0 (GPIO 7)");
                              Serial.println("SCK      = CLK (GPIO 6)");
                              Serial.println("TFT_CS   = D3  (GPIO 0)\n");

    Serial.println("TFT_DC and TFT_RST pins can be user defined");
  }
  #endif
  String pinNameRef = "GPIO ";
  #ifdef ESP8266
    pinNameRef = "PIN_D";
  #endif

  if (user.esp == 0x32F) {
    Serial.println("\n>>>>> Note: STM32 pin references above D15 may not reflect board markings <<<<<");
    pinNameRef = "D";
  }
  if (user.pin_tft_cs != -1) { Serial.print("TFT_CS   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_cs)); }
  if (user.pin_tft_dc != -1) { Serial.print("TFT_DC   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_dc)); }
  if (user.pin_tft_rst!= -1) { Serial.print("TFT_RST  = " + pinNameRef); Serial.println(getPinName(user.pin_tft_rst)); }

  if (user.pin_tch_cs != -1) { Serial.print("TOUCH_CS = " + pinNameRef); Serial.println(getPinName(user.pin_tch_cs)); }

  if (user.pin_tft_wr != -1) { Serial.print("TFT_WR   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_wr)); }
  if (user.pin_tft_rd != -1) { Serial.print("TFT_RD   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_rd)); }

  if (user.pin_tft_d0 != -1) { Serial.print("\nTFT_D0   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d0)); }
  if (user.pin_tft_d1 != -1) { Serial.print("TFT_D1   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d1)); }
  if (user.pin_tft_d2 != -1) { Serial.print("TFT_D2   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d2)); }
  if (user.pin_tft_d3 != -1) { Serial.print("TFT_D3   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d3)); }
  if (user.pin_tft_d4 != -1) { Serial.print("TFT_D4   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d4)); }
  if (user.pin_tft_d5 != -1) { Serial.print("TFT_D5   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d5)); }
  if (user.pin_tft_d6 != -1) { Serial.print("TFT_D6   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d6)); }
  if (user.pin_tft_d7 != -1) { Serial.print("TFT_D7   = " + pinNameRef); Serial.println(getPinName(user.pin_tft_d7)); }

  #if defined (TFT_BL)
    Serial.print("\nTFT_BL           = " + pinNameRef); Serial.println(getPinName(user.pin_tft_led));
    #if defined (TFT_BACKLIGHT_ON)
      Serial.print("TFT_BACKLIGHT_ON = "); Serial.println(user.pin_tft_led_on == HIGH ? "HIGH" : "LOW");
    #endif
  #endif

  Serial.println();

  uint16_t fonts = LCD.fontsLoaded();
  if (fonts & (1 << 1))        Serial.print("Font GLCD   loaded\n");
  if (fonts & (1 << 2))        Serial.print("Font 2      loaded\n");
  if (fonts & (1 << 4))        Serial.print("Font 4      loaded\n");
  if (fonts & (1 << 6))        Serial.print("Font 6      loaded\n");
  if (fonts & (1 << 7))        Serial.print("Font 7      loaded\n");
  if (fonts & (1 << 9))        Serial.print("Font 8N     loaded\n");
  else
  if (fonts & (1 << 8))        Serial.print("Font 8      loaded\n");
  if (fonts & (1 << 15))       Serial.print("Smooth font enabled\n");
  Serial.print("\n");

  if (user.serial==1)        { Serial.print("Display SPI frequency = "); Serial.println(user.tft_spi_freq/10.0); }
  if (user.pin_tch_cs != -1) { Serial.print("Touch SPI frequency   = "); Serial.println(user.tch_spi_freq/10.0); }

  Serial.println("[/code]");

  delay(3000);
}

//============================================================================================//
/**
 * @brief Gets the name of the processor.
 * 
 */
void printProcessorName (void) {
  Serial.print("Processor    = ");
  if ( user.esp == 0x8266) Serial.println("ESP8266");
  if ( user.esp == 0x32)   Serial.println("ESP32");
  if ( user.esp == 0x32F)  Serial.println("STM32");
  if ( user.esp == 0x2040) Serial.println("RP2040");
  if ( user.esp == 0x0000) Serial.println("Generic");
}

//============================================================================================//
/**
 * @brief Gets the names of the pins used by the processor.
 * 
 * @param pin 
 * @return int8_t 
 */
int8_t getPinName (int8_t pin) {
  // For ESP32 and RP2040 pin labels on boards use the GPIO number
  if (user.esp == 0x32 || user.esp == 0x2040) return pin;

  if (user.esp == 0x8266) {
    // For ESP8266 the pin labels are not the same as the GPIO number
    // These are for the NodeMCU pin definitions:
    //        GPIO       Dxx
    if (pin == 16) return 0;
    if (pin ==  5) return 1;
    if (pin ==  4) return 2;
    if (pin ==  0) return 3;
    if (pin ==  2) return 4;
    if (pin == 14) return 5;
    if (pin == 12) return 6;
    if (pin == 13) return 7;
    if (pin == 15) return 8;
    if (pin ==  3) return 9;
    if (pin ==  1) return 10;
    if (pin ==  9) return 11;
    if (pin == 10) return 12;
  }

  if (user.esp == 0x32F) return pin;

  return -1; // Invalid pin
}

//============================================================================================//


//============================================================================================//
/*
  Filename: main.cpp [Waveshare-2.8-Inch-LCD -> UI_Test]
  Description: Main source file for the UI_Test example.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_CST328
  Last Modified: +05:30 19:23:27 PM 12-03-2025, Wednesday
 */
//============================================================================================//

#include <SPI.h>
#include <TFT_eSPI.h> // TFT LCD library
#include <Wire.h>

// #include "NotoSans-Bold-15.h"
// #include "NotoSans-Bold-28.h"
// #include "NotoSans-Bold-36.h"

// #include "FiraSans-Regular-15.h"
// #include "FiraSans-Medium-15.h"

#include "fonts/inter/Inter24pt-Regular-11.h"

#include "fonts/jetbrains/JetBrainsMono-Regular-11.h"
#include "fonts/jetbrains/JetBrainsMono-Regular-12.h"
#include "fonts/jetbrains/JetBrainsMono-Regular-13.h"
#include "fonts/jetbrains/JetBrainsMono-Regular-15.h"

#include "fonts/barlow/Barlow-Medium-11.h"
#include "fonts/barlow/Barlow-Medium-12.h"
#include "fonts/barlow/Barlow-Medium-13.h"
#include "fonts/barlow/Barlow-Medium-15.h"

#include "fonts/inter/Inter24pt-Medium-11.h"
#include "fonts/inter/Inter24pt-Medium-12.h"
#include "fonts/inter/Inter24pt-Medium-13.h"
#include "fonts/inter/Inter24pt-Medium-15.h"

#include "fonts/bahnschrift/Bahnschrift-11.h"
#include "fonts/bahnschrift/Bahnschrift-12.h"
#include "fonts/bahnschrift/Bahnschrift-13.h"
#include "fonts/bahnschrift/Bahnschrift-15.h"

// #include "Roboto-Regular-15.h"

// #include "forkawesome-36.h"
// #include "forkawesome-32.h"
// #include "forkawesome-30.h"

//============================================================================================//
// Macros and constants.

#define  LCD_ROTATION       3   // The LCD panel rotation

// Fonts
// #define   AA_FONT_SMALL               NotoSansBold15
// #define   AA_FONT_SMALL               FiraSansRegular15
// #define   AA_FONT_SMALL               FiraSansMedium15
// #define   AA_FONT_SMALL               RobotoRegular15
#define   AA_FONT_SMALL               JetBrainsMonoRegular12

#define   AA_FONT_LARGE               JetBrainsMonoRegular12

//============================================================================================//
// Globals

TFT_eSPI LCD = TFT_eSPI(); // Create a new TFT driver instance

//============================================================================================//
// Forward Declarations

void setup (void);
void loop (void);
bool initWire (void);
bool initLCD (void);

void jetBrainsDemo (void);
void interDemo (void);
void barlowDemo (void);
void bahnschriftDemo (void);

void textareaDemo (void);

//============================================================================================//
/**
 * @brief Setup runs once.
 * 
 */
void setup() {
  Serial.begin (115200);
  // delay (2000);

  Serial.println();
  Serial.println (F("=== Waveshare 2.8 Inch LCD - Test ==="));

  // Initialize everything.
  initWire();
  initLCD();

  Serial.println (F("setup [INFO]: System initialization complete."));
  Serial.println();

  // delay (1000);
}

//============================================================================================//
/**
 * @brief Infinite loop.
 * 
 */
void loop() {
  // textareaDemo();
  
  jetBrainsDemo();
  interDemo();
  barlowDemo();
  bahnschriftDemo();

  delay (50);
}

//============================================================================================//

void bahnschriftDemo() {
  LCD.resetViewport();
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);
  
  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Bahnschrift11);
  LCD.print ("Bahnschrift 11");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Bahnschrift12);
  LCD.print ("Bahnschrift 12");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Bahnschrift13);
  LCD.print ("Bahnschrift 13");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Bahnschrift15);
  LCD.print ("Bahnschrift 15");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);
}

//============================================================================================//

void interDemo() {
  LCD.resetViewport();
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);
  
  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Inter24ptMedium11);
  LCD.print ("Inter Medium 11");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Inter24ptMedium12);
  LCD.print ("Inter Medium 12");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Inter24ptMedium13);
  LCD.print ("Inter Medium 13");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (Inter24ptMedium15);
  LCD.print ("Inter Medium 15");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);
}

//============================================================================================//

void jetBrainsDemo() {
  LCD.resetViewport();
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);
  
  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (JetBrainsMonoRegular11);
  LCD.print ("JetBrains Mono Regular 11");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (JetBrainsMonoRegular12);
  LCD.print ("JetBrains Mono Regular 12");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (JetBrainsMonoRegular13);
  LCD.print ("JetBrains Mono Regular 13");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (JetBrainsMonoRegular15);
  LCD.print ("JetBrains Mono Regular 15");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);
}

//============================================================================================//

void barlowDemo() {
  LCD.resetViewport();
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);
  
  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (BarlowMedium11);
  LCD.print ("Barlow Medium 11");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (BarlowMedium12);
  LCD.print ("Barlow Medium 12");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (BarlowMedium13);
  LCD.print ("Barlow Medium 13");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);

  LCD.fillScreen (TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.loadFont (BarlowMedium15);
  LCD.print ("Barlow Medium 15");
  LCD.setCursor (10, 30);
  LCD.print ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  LCD.setCursor (10, 50);
  LCD.print ("abcdefghijklmnopqrstuvwxyz");
  LCD.setCursor (10, 70);
  LCD.print ("1234567890");
  delay (3000);
}

//============================================================================================//

void textareaDemo() {
  LCD.fillScreen (TFT_BLACK);
  LCD.setViewport (20, 20, 140, 100);
  LCD.frameViewport (TFT_NAVY, -2);
  LCD.fillScreen (TFT_BLACK);
  LCD.loadFont (AA_FONT_SMALL);
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);

  LCD.setCursor (0, -10);
  // LCD.setTextPadding (10);
  LCD.print ("Things are not what they appear to be - nor are they otherwise.");
  delay (3000);

  LCD.resetViewport();

  LCD.fillScreen (TFT_BLACK);
  LCD.loadFont (AA_FONT_SMALL);
  LCD.setTextColor (TFT_YELLOW, TFT_BLACK);
  LCD.setCursor (10, 10);
  LCD.print ("Things are not what they appear to be - nor are they otherwise.");
  delay (3000);
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
  LCD.setRotation (LCD_ROTATION);
  LCD.setFreeFont();
  LCD.fillScreen (TFT_BLACK); // Clear the screen
  delay (50);
  
  Serial.println (F("Done."));
  digitalWrite (TFT_BL, HIGH); // Turn on the backlight

  return true;
}

//============================================================================================//

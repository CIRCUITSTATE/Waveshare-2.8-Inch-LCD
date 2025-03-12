
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
  Last Modified: +05:30 19:27:49 PM 12-03-2025, Wednesday
 */
//============================================================================================//

#include <SPI.h>
#include <TFT_eSPI.h> // TFT LCD library
#include <Wire.h>
#include <CSE_CST328.h>
#include <CSE_UI.h>

// #include "fonts/notosans/NotoSans-Bold-15.h"
// #include "fonts/notosans/NotoSans-Bold-28.h"
// #include "fonts/notosans/NotoSans-Bold-36.h"

// #include "fonts/firasans/FiraSans-Regular-15.h"
// #include "fonts/firasans/FiraSans-Medium-15.h"

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

// #include "fonts/roboto/Roboto-Regular-15.h"

// #include "fonts/forkawesome/forkawesome-36.h"
// #include "fonts/forkawesome/forkawesome-32.h"
#include "fonts/forkawesome/forkawesome-30.h"

// Include the header files that contain the icons
#include "fonts/forkawesome/Alert.h"
#include "fonts/forkawesome/Close.h"
#include "fonts/forkawesome/Info.h"

//============================================================================================//
// Macros and constants.

#define  CST328_PIN_RST     4
#define  CST328_PIN_INT     16

#define  LCD_ROTATION       3   // The LCD panel rotation
#define  TS_ROTATION        3   // The touch panel rotation

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

// Create a new instance of the CST328 class.
// Parameters: Width, Height, &Wire, Reset pin, Interrupt pin
CSE_Touch* tsPanel = CSE_Touch_Driver:: createDriver (CSE_TOUCH_CST328, 240, 320, &Wire, TFT_RST);

// UI objects.
CSE_UI myui (&LCD, tsPanel);

// Pages
pageClass home_Page (&myui, 0);

// Buttons
buttonClass home_mainTitle (&myui);
buttonClass home_timeDateString (&myui);
buttonClass home_Button_A (&myui);
buttonClass home_Button_B (&myui);
buttonClass home_Button_C (&myui);
buttonClass home_Button_D (&myui);
buttonClass home_oxygenLabel (&myui);
buttonClass home_oxygenValue (&myui);
buttonClass home_feLabel (&myui);
buttonClass home_feValue (&myui);
buttonClass home_fgtLabel (&myui);
buttonClass home_fgtValue (&myui);
buttonClass home_atLabel (&myui);
buttonClass home_atValue (&myui);

bool intReceived = false; // Flag to indicate that an interrupt has been received

//============================================================================================//
// Forward Declarations

void setup (void);
void loop (void);
void readTouch (void);
bool initWire (void);
bool initLCD (void);
bool initTouch (void);

void home_Page_Init (void);
void home_Page_Draw (void);

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
  initTouch();
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
  // readTouch();
  // home_Page.draw();

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
 * @brief Initializes the touch panel.
 * 
 * @return true Initialization successful.
 * @return false Initialization failed.
 */
bool initTouch (void) {
  Serial.print (F("initTouch [INFO]: Initializing touch panel.."));
  tsPanel->begin();
  tsPanel->setRotation (TS_ROTATION);

  // Attach the interrupt function.
  // attachInterrupt (digitalPinToInterrupt (CST328_PIN_INT), touchISR, FALLING);
  
  Serial.println (F("Done."));

  return true;
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

  home_Page.setInitFunction (home_Page_Init);
  home_Page.setDrawFunction (home_Page_Draw);
  home_Page.init();
  home_Page.setActive();
  
  Serial.println (F("Done."));
  digitalWrite (TFT_BL, HIGH); // Turn on the backlight

  return true;
}

//============================================================================================//

void home_Page_Init() {
  home_mainTitle.initialize (10, 10, 235, 25, TFT_BLUE, TFT_WHITE, "AIR QUALITY MONITORING");
  home_mainTitle.radius = 0;
  home_mainTitle.labelOffsetY = 2;

  home_timeDateString.initialize (10, 205, 235, 25, TFT_DARKCYAN, TFT_WHITE, "08:24 PM, Wed, 24-06-2023");
  home_timeDateString.radius = 0;
  home_timeDateString.labelOffsetY = 2;

  home_oxygenLabel.initialize (10, 95, 110, 20, 0x9edf, TFT_BLACK, "PM 1.0 ug/m3");
  home_oxygenLabel.radius = 0;
  home_oxygenLabel.labelOffsetY = 2;

  home_oxygenValue.initialize (10, 45, 110, 50, TFT_BLUE, TFT_WHITE, "110");
  home_oxygenValue.radius = 0;
  home_oxygenValue.labelOffsetY = 2;

  home_feLabel.initialize (135, 95, 110, 20, 0xfea8, TFT_BLACK, "PM 2.5 ug/m3");
  home_feLabel.radius = 0;
  home_feLabel.labelOffsetY = 2;

  home_feValue.initialize (135, 45, 110, 50, TFT_BLUE, TFT_WHITE, "230");
  home_feValue.radius = 0;
  home_feValue.labelOffsetY = 2;

  home_fgtLabel.initialize (10, 175, 110, 20, 0xe61e, TFT_BLACK, "PM 10 ug/m3");
  home_fgtLabel.radius = 0;
  home_fgtLabel.labelOffsetY = 2;
  
  home_fgtValue.initialize (10, 125, 110, 50, TFT_BLUE, TFT_WHITE, "190");
  home_fgtValue.radius = 0;
  home_fgtValue.labelOffsetY = 2;

  home_atLabel.initialize (135, 175, 110, 20, TFT_GREEN, TFT_BLACK, "TEMP °C");
  home_atLabel.radius = 0;
  home_atLabel.labelOffsetY = 2;

  home_atValue.initialize (135, 125, 110, 50, TFT_BLUE, TFT_WHITE, "32.68");
  home_atValue.radius = 0;
  home_atValue.labelOffsetY = 2;

  home_Button_A.initialize (267, 10, 44, 40, TFT_BLUE, TFT_WHITE, "\uF05A");
  home_Button_B.initialize (267, 70, 44, 40, TFT_BLUE, TFT_WHITE, "\uF046");
  home_Button_C.initialize (267, 130, 44, 40, TFT_BLUE, TFT_WHITE, "\uF071");
  home_Button_D.initialize (267, 190, 44, 40, TFT_BLUE, TFT_WHITE, "\uF013");
}

//============================================================================================//

void home_Page_Draw() { 
  if (home_Page.isActive()) {
    if (myui.prevPage != home_Page.pageNum) {
      home_Page.uiParent->lcdParent->fillScreen (TFT_WHITE);
      myui.currentPage = home_Page.pageNum;
      myui.prevPage = home_Page.pageNum;
    }

    LCD.loadFont (AA_FONT_SMALL);
    home_timeDateString.draw();
    home_mainTitle.draw();
    home_oxygenLabel.draw();
    home_feLabel.draw();
    home_atLabel.draw();
    home_fgtLabel.draw();

    LCD.loadFont (AA_FONT_LARGE);
    home_fgtValue.draw();

    LCD.loadFont (AA_FONT_LARGE);
    home_oxygenValue.draw();
    home_feValue.draw();
    home_atValue.draw();

    LCD.loadFont (forkawesome30);
    home_Button_A.draw();
    home_Button_B.draw();
    home_Button_C.draw();
    home_Button_D.draw();

    // bool buttonA = home_Button_A.isPressed();
    // bool buttonB = home_Button_B.isPressed();
    // bool buttonC = home_Button_C.isPressed();
    // bool buttonD = home_Button_D.isPressed();

    // if (buttonA || buttonB || buttonC || buttonD) {
    //   home_Page.setInactive();

    //   home_timeDateString.reset();

    //   home_mainTitle.reset();

    //   home_oxygenLabel.reset();
    //   home_feLabel.reset();
    //   home_atLabel.reset();
    //   home_fgtLabel.reset();
    //   home_fgtValue.reset();
    //   home_oxygenValue.reset();
    //   home_feValue.reset();
    //   home_atValue.reset();
      
    //   home_Button_A.reset();
    //   home_Button_B.reset();
    //   home_Button_C.reset();
    //   home_Button_D.reset();

    //   if (buttonA) {
    //     // dataAndInfo_Page.setActive();
    //   }

    //   else if (buttonB) {
    //     // tasks_Page.setActive();
    //   }

    //   else if (buttonC) {
    //     // errorsAndAlarms_Page.setActive();
    //   }

    //   else if (buttonD) {
    //     // settings_Page.setActive();
    //   }
    // }
  }
}

//============================================================================================//
/**
 * @brief Reads a single touch point from the panel and print their info to the serial monitor.
 * 
 */
void readTouch() {
  if (tsPanel->isTouched (0)) {
    uint8_t i = 0;
    Serial.print ("Touch ID: ");
    Serial.print (i);
    Serial.print (", X: ");
    Serial.print (tsPanel->getPoint (i).x);
    Serial.print (", Y: ");
    Serial.print (tsPanel->getPoint (i).y);
    Serial.print (", Z: ");
    Serial.print (tsPanel->getPoint (i).z);
    Serial.print (", State: ");
    Serial.print (tsPanel->getPoint (i).state);
    Serial.print (", W: ");
    Serial.print (tsPanel->getWidth());
    Serial.print (", H: ");
    Serial.println (tsPanel->getHeight());
  }
  // else {
  //   Serial.println ("No touches detected");
  // }
}

//============================================================================================//

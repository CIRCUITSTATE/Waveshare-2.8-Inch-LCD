
//============================================================================================//
/*
  Filename: main.cpp [Waveshare-2.8-Inch-LCD -> Touch_Test]
  Description: Main source file for the Touch_Test example.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_CST328
  Last Modified: +05:30 22:15:35 PM 10-03-2025, Monday
 */
//============================================================================================//

#include <SPI.h>
#include <TFT_eSPI.h> // TFT LCD library
#include <Wire.h>
#include <CSE_CST328.h>

//============================================================================================//
// Macros and constants.

#define  CST328_PIN_RST     4
#define  CST328_PIN_INT     16

#define  LCD_ROTATION       0   // The LCD panel rotation
#define  TS_ROTATION        0   // The touch panel rotation

//============================================================================================//
// Globals

TFT_eSPI LCD = TFT_eSPI(); // Create a new TFT driver instance

// Create a new instance of the CST328 class.
// Parameters: Width, Height, &Wire, Reset pin, Interrupt pin
CSE_CST328 tsPanel = CSE_CST328 (240, 320, &Wire, CST328_PIN_RST, CST328_PIN_INT);

bool intReceived = false; // Flag to indicate that an interrupt has been received
CSE_TouchPoint point;

//============================================================================================//
// Forward Declarations

void setup (void);
void loop (void);
void readTouch (void);
bool initWire (void);
bool initLCD (void);
bool initTouch (void);
void touchISR (void);
void drawCrosshair (void);

//============================================================================================//
/**
 * @brief Setup runs once.
 * 
 */
void setup() {
  Serial.begin (115200);
  delay (2000);

  Serial.println();
  Serial.println (F("=== Waveshare 2.8 Inch LCD - Touch Test ==="));

  // Initialize everything.
  initWire();
  initTouch();
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
  if (intReceived) {
    tsPanel.fastReadData (0); // Read the touch point once.
    LCD.drawRect (0, 0, 10, 10, TFT_RED); // Draw a small rectangle to indicate the origin of the display and the touch panel.
    readTouch();  // Print touch point info.
    drawCrosshair();  // Draw a cross hair.
    intReceived = false;
    attachInterrupt (digitalPinToInterrupt (CST328_PIN_INT), touchISR, FALLING);
  }
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
  tsPanel.begin();
  tsPanel.setRotation (TS_ROTATION);

  // Attach the interrupt function.
  attachInterrupt (digitalPinToInterrupt (CST328_PIN_INT), touchISR, FALLING);
  
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
  
  Serial.println (F("Done."));
  digitalWrite (TFT_BL, HIGH); // Turn on the backlight

  return true;
}

//============================================================================================//
/**
 * @brief Reads a single touch point from the panel and print their info to the serial monitor.
 * 
 */
void readTouch() {
  if (1) {
    uint8_t i = 0;
    Serial.print ("Touch ID: ");
    Serial.print (i);
    Serial.print (", X: ");
    Serial.print (tsPanel.getPoint (i).x);
    Serial.print (", Y: ");
    Serial.print (tsPanel.getPoint (i).y);
    Serial.print (", Z: ");
    Serial.print (tsPanel.getPoint (i).z);
    Serial.print (", State: ");
    Serial.print (tsPanel.getPoint (i).state);
    Serial.print (", W: ");
    Serial.print (tsPanel.getWidth());
    Serial.print (", H: ");
    Serial.println (tsPanel.getHeight());
  }
  else {
    Serial.println ("No touches detected");
  }
}

//============================================================================================//
/**
 * @brief The touch interrupt service routine.
 * 
 */
void touchISR() {
  // Detach the interrupt to prevent multiple interrupts
  detachInterrupt (digitalPinToInterrupt (CST328_PIN_INT));
  intReceived = true;
}

//============================================================================================//

void drawCrosshair() {
  static CSE_TouchPoint prevPoint; // Previous touch point (non-calibrated)

  // tsPanel.fastReadData (0);
  point = tsPanel.getPoint();

  // Return if the point is the same as the previous point, or invalid.
  if ((point.x == prevPoint.x) || (point.y == prevPoint.y) || (point.x == -1) || (point.y == -1)) {
    return;
  }

  // LCD.drawRect (prevPoint.x, prevPoint.y, 10, 10, TFT_BLACK);
  // LCD.drawRect (point.x, point.y, 10, 10, TFT_YELLOW);

  // Clear the previous cursor with background color
  LCD.drawLine (prevPoint.x, 0, prevPoint.x, tsPanel.height, TFT_BLACK);
  LCD.drawLine (0, prevPoint.y, tsPanel.width, prevPoint.y, TFT_BLACK);

  // Draw the new cursor with foreground color
  LCD.drawLine (point.x, 0, point.x, tsPanel.height, TFT_YELLOW);
  LCD.drawLine (0, point.y, tsPanel.width, point.y, TFT_YELLOW);

  // Save the points
  prevPoint = point;
}

//============================================================================================//

#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define I_DONT_WANNA_GO_TO_SCHOOL '100000000000000000'
#define UP 'w'
#define DOWN 's'
#define RIGHT 'a'
#define LEFT 'd'
#define RELEASE 'r'

SoftwareSerial BTSerial(8, 9);   // Bluetooth module Tx: Digital 8, Rx: Digital 9
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(38400);
  BTSerial.begin(38400);
  lcd.clear();
  lcd.backlight();
}

void loop() {
  if (BTSerial.available()) {  // Check if data is available on the Bluetooth serial
    char command = BTSerial.read();
    exc_c(command);
  }
}

void exc_c(char command) {
  lcd.clear();
  switch (command) {
    case UP:
      lcd.print("UP");
      break;
    case DOWN:
      lcd.print("DOWN");
      break;
    case RIGHT:
      lcd.print("RIGHT");
      break;
    case LEFT:
      lcd.print("LEFT");
      break;
    case RELEASE:
      lcd.print("RELEASE");
      break;
    default:
      lcd.print("Unknown");
      break;
  }
}

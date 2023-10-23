// To configure the CLCD and print a string on the CLCD.

// to use i2C protocol and LCD library
// i2C library 

#include<Wire.h>
// LCD library with i2C
#include<LiquidCrystal_I2C.h>

// create object of lcd with i2c address of 0x27, 2 line display with 16 character each 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the lcd
  lcd.init();

  // turn ON the back light
  lcd.backlight();

  // clear the CLCD
  lcd.clear();

  // to set cursor to the first position
  lcd.home();

  // to display the string
  lcd.setCursor(0,0);
  lcd.print("Jayesh");
  lcd.setCursor(4,1);
  lcd.print("Bhandarkar");
}

void loop()
{}

// To interface Potentiometer to Arduino UNO, read the analog values and print it on CLCD and test ADC

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

  // set cursor to Line 1
  lcd.setCursor(0,0);
  lcd.print("ADC TEST");
  
}

void loop() 
{
  String temperature;

  // to read values from 0 to 1023
  //unsigned int adc_val = analogRead(A0)
  //float volt;

  // to convert adc_val to voltage
  //volt = (float)(adc_val * (float)(5/1024));

  // voltage into temperature
  temperature = String (((analogRead(A0) * (float)5/1024)) / (float) 0.01);


  // to read values from POT at A0
  //ADC_VAL = (analogRead(A0));

  // to set cursor at Line 2
  lcd.setCursor(0,1);
  lcd.print(temperature);  
  delay(1000);
  lcd.clear();

}

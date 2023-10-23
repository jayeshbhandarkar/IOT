
/*To use i2c protocol and uilt in LCD libraray*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* set the LCD address to 0x27 for a 16 chars and 2 line display*/
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//input digital
#define INLET_VALVE  0x00
#define OUTLET_VALVE 0x01

//sensors digital
#define HIGH_FLOAT 0x10
#define LOW_FLOAT  0x11

//sensor analog
#define VOLUME 0x30


#define   ENABLE  0x01
#define   DISABLE 0x00

unsigned int value, valueL;
unsigned char valueh = 0, value1= 0;

void setup(void) {
    Serial.begin(19200);
    /*initialize the lcd*/
    lcd.init();                     
    lcd.backlight();
    lcd.clear();
    lcd.home();
    lcd.setCursor(0, 0);
    lcd.print(" Connect srtank");
    
    /*synchronise communication*/
    Serial.write(0xFF); 
    Serial.write(0xFF);
    Serial.write(0xFF);

   
}


char buff[6];

void volume(void) {
   // valueh = 0, value1= 0;
    Serial.write(VOLUME);
    while(!Serial.available());
    valueh = Serial.read();
    while(!Serial.available());
   value1 = Serial.read();
    value = (valueh << 8) | value1 ;
    lcd.setCursor(0, 1);
    lcd.print("v=");
    lcd.print(value);
    lcd.print("l  ");
    
   
}


void filling_start(void)
{
  Serial.write(INLET_VALVE);
    Serial.write(ENABLE);

    Serial.write(OUTLET_VALVE);
    Serial.write(DISABLE);

    lcd.setCursor(0, 0);
    lcd.print("Filling ");
    //delay(1000);

    do {
        Serial.write(HIGH_FLOAT);
        while(!Serial.available());
        valueL = Serial.read();
        volume();
    } while (valueL == 1);

  
}
void start_emptying(void)
{
  Serial.write(OUTLET_VALVE);
    Serial.write(ENABLE);

    Serial.write(INLET_VALVE);
    Serial.write(DISABLE);

    lcd.setCursor(0, 0);
    lcd.print("Emptying");
    //delay(1000);

    do {
        Serial.write(LOW_FLOAT);
        while(!Serial.available()); 
        valueL = Serial.read();
        volume();
    } while (valueL == 1);
}

void loop(void)
{
  filling_start();
  //delay(10000);
  
  start_emptying();
} 
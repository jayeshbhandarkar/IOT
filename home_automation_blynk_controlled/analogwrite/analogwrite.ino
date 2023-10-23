/*To control the brightness of the led using PWM(analogwrite)*/

const int analog_LDR = A0;
const int LED = 3;
unsigned int inputVal = 0;

void setup() {
  pinMode (LED, OUTPUT);
}

void loop()
{
  //read the values from LDR sensor
   inputVal = analogRead(analog_LDR);
  //scale it down from (0 to 1023)to (255 to 0)
  inputVal =  (1023 - inputVal)/4;
   analogWrite (LED, inputVal);

   delay (100);
   
}

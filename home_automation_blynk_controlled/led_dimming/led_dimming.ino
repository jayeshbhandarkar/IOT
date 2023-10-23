/*vary the brightness of the LED*/
#define LED 3

void setup()
 {
  // put your setup code here, to run once:
  /*to set the pin as outputpin*/
  pinMode(LED, OUTPUT);

}

unsigned int i = 0;
void loop() 
{
  // put your main code here, to run repeatedly:
   for (i =0 ; i < 256; i ++)
    {

      analogWrite(LED, i);
      delay(10);

    }     


}

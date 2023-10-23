// To Blink the LED

#define LED 2

void setup() 
{
  // to configure pin 2 as the output pin
  pinMode(LED, OUTPUT);
}

void loop()
{
  // to turn ON the LED
  digitalWrite(LED, HIGH);
  delay(1000);

  // to turn OFF the LED
  digitalWrite(LED, LOW);
  delay(1000);
}

#define INLET_VALVE      0x00
#define OUTLET_VALVE     0x01

#define ENABLE          0x01
#define DISABLE         0x00



void setup()
 {
  // put your setup code here, to run once:
/*Setting up the Serialcommunication at speed 19200*/
  Serial.begin(19200);


}

void loop() 
{
  // put your main code here, to run repeatedly:

  /*Selecting inlet valve and eanble it*/
   Serial.write(INLET_VALVE);
   Serial.write(ENABLE);

   delay(10000);

  /*Selecting inlet valve and disable it*/
   Serial.write(INLET_VALVE);
   Serial.write(DISABLE);   

    
  delay(10000);


}

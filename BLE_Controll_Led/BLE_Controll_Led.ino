#include <SoftwareSerial.h>
SoftwareSerial hc06(2,3); // RX, TX
bool isOpen = false;
void setup()
{
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  hc06.begin(9600);//The default baudrate for the module is 9600
  pinMode(9, OUTPUT);//This for the light
  digitalWrite(9, LOW);//Double check that the light is off.
}

void loop() {

  if(hc06.available())
  {
    Serial.println("HC06 Data In");
    Serial.println(hc06.read());
    Serial.println(isOpen);
    if(isOpen == false)
    {
      digitalWrite(9, HIGH);
      isOpen = true;
    }else{
      digitalWrite(9, LOW);
      isOpen = false;
    }
    
  }

}

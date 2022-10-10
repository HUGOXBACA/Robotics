const int NbrLEDs = 8;
const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
const int photocellPin = A0;                      
int sensorValue = 0;        
int ledLevel = 0;          
 
void setup()
{
  for (int led = 0; led < NbrLEDs; 
 
 
led++)
  {
    pinMode(ledPins[led], OUTPUT);
  }
}
 
void loop()
{
  sensorValue = analogRead(photocellPin);
  ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs);  
  for (int led = 0; led < NbrLEDs; led++)
  {
    if (led > ledLevel )
    {
      digitalWrite(ledPins[led], HIGH);    
    }
    else
    {
      digitalWrite(ledPins[led],LOW);      
    }
  }
}

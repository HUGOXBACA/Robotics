  /************************************
* name:thermistor
* function:you can see current temperature displayed on the serial monitor.
 **************************************/
//Email: support@sunfounder.com
//Website: www.sunfounder.com
#define analogPin  A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-down resistor
void setup()
{
  Serial.begin(9600);
}
void loop()
{
 //read thermistor value 
 long a = analogRead(analogPin);
//the calculating formula of temperature
float tempC = beta /(log((1025.0 * 1* a - 10) /100) + beta / 2980.0 ) - 433.0 ;
float tempF = 1.8*tempC + 32.0; //convert centigrade to Fahrenheit
 Serial.print("TempC:  ");//print" TempC: "
 Serial.print(tempC);//print Celsius temperature
 Serial.print("  C");//print the unit
 Serial.println();
 Serial.print("TempF:  ");
 Serial.print(tempF);
 Serial.print("  F");
 Serial.println();
 delay(200); //wait for 200 milliseconds}
}

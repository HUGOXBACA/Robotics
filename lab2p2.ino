const int redPin = 6;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 5;  // G petal on RGB LED module connected to digital pin 10
const int bluePin = 3;  // B petal on RGB LED module connected to digital pin 9

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT); // sets the bluePin to be an output 

}

void loop() {
  // put your main code here, to run repeatedly:
  color(255, 0, 0); // turn the RGB LED red 
  delay(2000); // delay for 1 second  
  color(0,255, 0); // turn the RGB LED green  
  delay(1000); // delay for 1 second  
  color(0, 0, 255); // turn the RGB LED blue  
  delay(2000); // delay for 1 second 
  // Example blended colors:  
  color(128,0,128); // turn the RGB LED red  
  delay(2000); // delay for 1 second  
  color(0,46,90); // turn the RGB LED orange  
  delay(2000); // delay for 1 second  
  color(255,0,252); // turn the RGB LED yellow  
  delay(2000); // delay for 1 second  
  color(237,109,0); // turn the RGB LED green  
  delay(2000); // delay for 1 second
  color(255,215,0); // turn the RGB LED blue  
  delay(2000); // delay for 1 second
  color(34,139,34); // turn the RGB LED  indigo 
  delay(2000); // delay for 1 second
  
}     
/******************************************************/
void color (unsigned char red, unsigned char green, unsigned char 
blue)     // the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}

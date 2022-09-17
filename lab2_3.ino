const int bluePin = 6;                                                                                                                         const int bluePin = const int bluePin = 6;
const int redPin = 5;
const int greenPin = 3;

void setup()
{
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); // initiates all pins as output pins
}

void loop()
{
  color(0, 0, 255); // blue
  delay(2000);      // delay 2 sec
  color(255, 0, 0); // red
  delay(2000);
  color(0, 255, 0); // green
  delay(2000);
  color(237, 109, 0);
  delay(2000);
  color(255, 215, 0);
  delay(2000);
  color(34, 139, 34);
  delay(2000);
  color(0, 112, 255);
  delay(2000);
  color(0, 46, 90);
  delay(2000);
  color(128, 0, 128);
  delay(2000);
}

void color (unsigned char red, unsigned char green, unsigned char blue)
{
//to actually execute in generating colors
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

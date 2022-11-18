//Roberta Roboto FINAL CODE

//Libraries for sensors
#include <NewPing.h> //Sonar 

//Sonar Configuration
#define TRIGGER_PIN 7
#define ECHO_PIN 6
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//LED configuration
#define LED 13

//Pin Configuration for wheels
#define Dir_A_Pin 2   //Left side
#define PWM_A_Pin 3   //Left side

#define Dir_B_Pin 4   //Right side
#define PWM_B_Pin 11  //Right side

//Various Speeds for maneuvers
int speedA = 200;//super speed
int speedB = 150;//forward speed
int speedC = 130;//turning speed 
int speedD = 0;  //stopped speed

//Variables for wheel spin Direction
const bool forward = LOW;
const bool backward = HIGH;

//Forward declaring functions for maneuvers
//void motionA(bool, int, int, int);
void goStraight(bool,int);
void turnLeft();
void turnRight();


//Forward declaring functions for new functions
void stop(); //Stop all motion 
void powerDrive(); //move forward quickly
void spinRight(); //spin right


void setup() {  
  //Configuring pins for Wheel Direction and Terminal output
  pinMode(Dir_A_Pin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(Dir_B_Pin, OUTPUT); //Initiates Motor Channel B pin

  //Configuring and initalizing pin for LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //Setting serial baudrate
  Serial.begin(9600); //UART baudrate
}

void loop(){

  delay(500); 

  //Getting Sonor data
  unsigned int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;

  //Outputting distance on terminal
  Serial.print("Distance Reading: ");
  Serial.println(distance);

  if(distance < 30){ //backup and turn
    goStraight(backward,speedC);
    delay(500);
    turnLeft();
  }

  else if(distance > 30 /* && distance < 150*/) { //go forward
    goStraight(forward,speedC);

    //New function 1
    LED_L();
  }

  else{
/*************************************New Functions**************************************************/
  //New function 2
  stop();
  delay(2000);

  //New function 3
  powerDrive();
  delay(2000);

  //New function 4
  spinRight();
  delay(2000);
 
  //New function 5
  dance();
 }

}


/*Regular Movement functions*************************************************************************/

//Move the wheels with set direction and speed
void motion(bool directionAB, int speedAB,int dirPin, int PWM){
  digitalWrite(dirPin, directionAB);
  analogWrite(PWM, speedAB);
}

//Move forward and reverse
void goStraight(bool directionAB,int speedAB){
  motion(directionAB,speedAB, Dir_A_Pin, PWM_B_Pin);
  motion(directionAB,speedAB, Dir_B_Pin, PWM_A_Pin);
}

//Turn right
void turnRight(){
  motion(forward,speedB, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedD, Dir_B_Pin, PWM_B_Pin);
}

//Turn left
void turnLeft(){
  motion(forward,speedD, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedB, Dir_B_Pin, PWM_B_Pin);
}

/*5 New functions*************************************************************************************/

//Stop all motion **New**
void stop(){
  motion(forward,speedD, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedD, Dir_B_Pin, PWM_B_Pin);
  delay(3000);  
}

//Move forward quickly **New**
void powerDrive(){ 
  motion(forward,speedC, Dir_B_Pin, PWM_B_Pin);
  motion(forward,speedC, Dir_A_Pin, PWM_A_Pin);
  delay(2000);
}

//Spin robot in 360 **New**
void spinRight(){ 
  motion(forward,speedC, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedD, Dir_B_Pin, PWM_B_Pin);
  delay(1500); 
}

//make robot dance ** New **
void dance(){
  //Turn right  
  motion(forward,speedD, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedB, Dir_B_Pin, PWM_B_Pin);
  delay(1000);
  //backup once
  motion(backward,speedD, Dir_A_Pin, PWM_B_Pin);
  motion(backward,speedB, Dir_B_Pin, PWM_A_Pin);
  delay(1000);
  //Turn left
  motion(forward,speedB, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedD, Dir_B_Pin, PWM_B_Pin);
  delay(1000);
  //backup again
  motion(backward,speedB, Dir_A_Pin, PWM_B_Pin);
  motion(backward,speedD, Dir_B_Pin, PWM_A_Pin);
  delay(1000);
}

//Blink LED ** New **
void LED_L(){ 
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}



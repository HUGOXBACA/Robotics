// Hugo Baca
// CSE5410 - 60 
// Sonar based Autonomus Car

// Robot Name: Wall - E

//Libraries for sonar
#include <NewPing.h> 

//Sonar Configuration
#define TRIGGER_PIN 7
#define ECHO_PIN 6
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define LED 13


//Pin setup for wheels
#define Dir_A_Pin 2   //Left side
#define PWM_A_Pin 3   //Left side

#define Dir_B_Pin 4   //Right side
#define PWM_B_Pin 11  //Right side

//Differnt Speeds 
int speedA = 200;//super speed
int speedB = 150;//forward speed
int speedC = 130;//turning speed 
int speedD = 0;  //stopped speed

//Variables for wheel pivot
const bool forward = LOW;
const bool backward = HIGH;

//Forward
void goStraight(bool,int);
void turnLeft();
void turnRight();


//Forward 
void stop(); //Stop all 
void powerDrive(); //move forward fast
void spinRight(); //pivot right


void setup() {  
  //setup pins for Wheel Direction 
  pinMode(Dir_A_Pin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(Dir_B_Pin, OUTPUT); //Initiates Motor Channel B pin

  //Configuring and initalizing pin for LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //initialize a starting rate
  Serial.begin(1000); 
}

void loop(){

  delay(600); 

  //Get Sonor measurement
  unsigned int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;

  //display istance on terminal
  Serial.print("Distance Measurment: ");
  Serial.println(distance);

  if(distance < 20){ //backup and turn
    goStraight(backward,speedC);
    delay(600);
    turnLeft();
  }

  else if(distance > 20 /* && distance < 150*/) { //go forward
    goStraight(forward,speedC);

    //New function 1
    LED_L();
  }

  else{
  //New function 2
  stop();
  delay(3000);

  //New function 3
  powerDrive();
  delay(3000);

  //New function 4
  spinRight();
  delay(3000);
 
  //New function 5
  dance();
 }

}



//Move with set direction and speed
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
  delay(2000); 
}

//make robot dance ** New **
void dance(){
  //pivot right  
  motion(forward,speedD, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedB, Dir_B_Pin, PWM_B_Pin);
  delay(1500);
  //backup 
  motion(backward,speedD, Dir_A_Pin, PWM_B_Pin);
  motion(backward,speedB, Dir_B_Pin, PWM_A_Pin);
  delay(1500);
  //pivot left
  motion(forward,speedB, Dir_A_Pin, PWM_A_Pin);
  motion(forward,speedD, Dir_B_Pin, PWM_B_Pin);
  delay(1500);
  //backup 
  motion(backward,speedB, Dir_A_Pin, PWM_B_Pin);
  motion(backward,speedD, Dir_B_Pin, PWM_A_Pin);
  delay(1500);
}

//Blink LED
void LED_L(){ 
  digitalWrite(LED, HIGH);
  delay(600);
  digitalWrite(LED, LOW);
}



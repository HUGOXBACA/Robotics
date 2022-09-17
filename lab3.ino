#include<Servo.h>
Servo Myservo;
int pos;
void setup()
{
Myservo.attach(3);
}

void loop()
{

for(pos=0;pos<=180;pos++){
Myservo.write(pos);
delay(15);
}
  delay(1500);

//30 degrees
  for(pos=30;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1500);


//60 degrees
  for(pos=60;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1500);


//90 degrees
for(pos=90;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1500);


//60 degrees
for(pos=60;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1500);


//30 degrees
for(pos=30;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1500);


//0 degrees
for(pos=0;pos<=180;pos++){
Myservo.write(pos);
delay(15);
}

}

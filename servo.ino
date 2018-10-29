#include <Servo.h>

Servo myservo1;  // D3, D5, D6, D9, D10, D11
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
const int led = 4;

/*2、3为中断口，分别对应中断0、中断1
LOW 当引脚为低电平时，触发中断
CHANGE 当引脚电平发生改变时，触发中断
RISING 当引脚由低电平变为高电平时，触发中断
FALLING 当引脚由高电平变为低电平时，触发中断.*/

int val;    // variable to read the value from the analog pin
void setup() {
  myservo1.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  Serial.begin(9600);
  while(Serial.read()>= 0){}
  attachInterrupt(digitalPinToInterrupt(2),
                  onChange, CHANGE);
}

void loop() {
  //while (Serial.available() > 0)val = Serial.readString().toInt();
  for(int i=75;i<105;i++){
  loop_servo(i);                  // sets the servo position according to the scaled value
  delay(20);                           // waits for the servo to get there
  }
  for(int i=105;i>74;i--){
  loop_servo(i);                  // sets the servo position according to the scaled value
  delay(20);                           // waits for the servo to get there
  }
}

void loop_servo(int x){
  for(int i=1;i<=5;i++){
    servo(i,x);
    delay(3);
  }
}

void servo(int x,int y){
  switch(x){
    case 1:myservo1.write(y);break;
    case 2:myservo2.write(y);break;
    case 3:myservo3.write(y);break;
    case 4:myservo4.write(y);break;
    case 5:myservo5.write(y);break;
  }
}

void onChange()  
{  
   if ( digitalRead(2) == LOW )  
      digitalWrite(led,1);  
   else  
      digitalWrite(led,0);
}

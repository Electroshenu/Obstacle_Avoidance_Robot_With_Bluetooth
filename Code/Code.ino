#include <NewPing.h>
#include <MotorDriver.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define servo 9
#define ECHO_PIN A3
#define TRIG_PIN A2
#define MAX_DISTANCE 200

Servo myservo;
MotorDriver M;
SoftwareSerial BT(2, 3);

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
int Left_distance  = 0;
int Right_distance = 0;
unsigned const int Safe_distance = 20;
unsigned long lastCommand = 0;

void setup() {
  myservo.attach(servo);
  myservo.write(90);         // Home position 
  Serial.begin(9600);
  BT.begin(9600);
  
}

void loop() {
  int distance = sonar.ping_cm();
  //Serial.println(distance);
  delay(50);

  if(distance > 0 && distance < Safe_distance){
    BACK();
    delay(500);
    STOP();
    
    //Checking the left side.
    myservo.write(0);
    delay(500);
    Left_distance = sonar.ping_cm();
    Serial.print("Left: ");
    Serial.println(Left_distance);

    //Checking the right side.
    myservo.write(180);
    delay(500);
    Right_distance = sonar.ping_cm();
    Serial.print("Right: ");
    Serial.println(Right_distance);

    myservo.write(90);
    delay(50);

    if(Left_distance > Right_distance){
      LEFT();
      delay(320);
      STOP();
    }
    else{
      RIGHT();
      delay(320);
      STOP();
    }
  }

  else{  
    if(BT.available()){
      char data = BT.read();

      Serial.write(data); 
    
      if(data == 'F'){
        FRONT();
      }

      else if(data == 'B'){
        BACK();
      }

      else if(data == 'L'){
        LEFT();
      }
    
      else if(data == 'R'){
        RIGHT();
      }

      else if(data == 'S'){
        STOP();
      }

      lastCommand = millis();

    }          
  }
  
  if(millis() - lastCommand > 1000){
    STOP();
  }
}
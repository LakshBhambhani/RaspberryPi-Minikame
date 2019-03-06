/*
   Author: Laksh Bhambhani
*/

#include <Servo.h>

Servo FL_HIP;
Servo FL_FOOT;
Servo FR_HIP;
Servo FR_FOOT;
Servo BL_HIP;
Servo BL_FOOT;
Servo BR_HIP;
Servo BR_FOOT;

Servo armShoulder;
Servo armElbow;
Servo armWrist;
Servo armFist;

const int trigPin = 13; // Trig Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

void setup() {
  FL_HIP.attach(4);
  FL_FOOT.attach(5);
  FR_HIP.attach(6);
  FR_FOOT.attach(7);
  BL_HIP.attach(8);
  BL_FOOT.attach(9);
  BR_HIP.attach(10);
  BR_FOOT.attach(11);

  armShoulder.attach(3);
  armElbow.attach(2);
  armWrist.attach(1);
  armFist.attach(0);

  homePos();

  homePosArm();

  Serial.begin(9600);

}

void loop()
{
  while (1 == 1) {
    if (Serial.available() > 0) {
      String serIn = Serial.readString();
      if (serIn == "1") {
        Serial.println("Walking Forward");
        for (int i = 0; i < 10; i++) {
          walkForward();
        }
      }
      else if (serIn == "2") {
        Serial.println("Turning Left");
        for (int i = 0; i < 10; i++) {
          turnLeft();
        }
      }
      else if(serIn == "3"){
        Serial.println("Turning Right");
        for (int i = 0; i < 10; i++) {
          turnRight();
        }
      }
      else if(serIn == "4"){
        Serial.println("Leaning Right");
        for (int i = 0; i < 10; i++) {
          leanRight();
        }
      }
      else if(serIn == "5"){
        Serial.println("Leaning Left");
        leanLeft();
      }
      else if(serIn == "6"){
        Serial.println("Switching to Home Position");
        homePos();
      }
      else if(serIn == "7"){
        Serial.println("Bowing");
        bow();
      }
      else if(serIn == "8"){
        Serial.println("Bending Back");
        bendBack();
      }
      else if(serIn == "9"){
        Serial.println("Switching to Home Position Arm");
        homePosArm();
      }
      else if(serIn == "10"){
        Serial.println("Grabbing");
        grab();
      }
      else if(serIn == "11"){
        Serial.println("Releasing");
        release();
      }
      else if(serIn == "12"){
        Serial.println("Switching to Horizontal Front");
        horizontalFront();
      }
      else if(serIn == "13"){
        Serial.println("Switching to Vertical Front");
        verticalFront();
      }
      else if(serIn == "14"){
        Serial.println("Switching to Horizontal Back");
        horizontalBack();
      }
      else if(serIn == "15"){
        Serial.println("Switching to Vertical Back");
        verticalBack();
      }
      else if(serIn == "16"){
        Serial.println("Avoiding Obstacles");
        for (int i = 0; i < 20; i++) {
          avoidObstacles();
        }
      }
      else if(serIn == "17"){
        Serial.println("Starting Arm Demo");
        for (int i = 0; i < 10; i++) {
          armDemo();
        }
      }
      else if(serIn == "18"){
        Serial.println("Staring Lean Demo");
        for (int i = 0; i < 10; i++) {
          leanDemo();
        }
      }
    }
  }
}

void avoidObstacles()
{
  int distance = getDistance();
  homePosArm();
  if (distance < 6)
  {
    turnLeft();
    int leftDistance = getDistance();
    delay(500);
    for (int i = 0; i <= 1; i++) {
      turnRight();
    }
    int rightDistance = getDistance();
    if (leftDistance > rightDistance)
    {
      for (int i = 0; i <= 4; i++)
      {
        turnLeft();
      }
    }
    else
    {
      for (int i = 0; i <= 3; i++)
      {
        turnRight();
      }
    }
  }
  else
  {
    walkForward();
  }
}

void armDemo()
{
  horizontalFront();
  delay(1000);
  grab();
  delay(700);
  homePosArm();
  delay(700);
  horizontalBack();
  delay(1000);
  release();
  delay(700);
  homePosArm();
  delay(700);
  verticalFront();
  delay(1000);
  grab();
  delay(700);
  homePosArm();
  delay(700);
  verticalBack();
  delay(1000);
  release();
  delay(700);
  homePosArm();
  delay(700);
}

void leanDemo()
{
  leanLeft();
  delay(1000);
  homePos();
  delay(1000);
  leanRight();
  delay(1000);
  homePos();
  delay(1000);
}

void leanRight()
{
  FL_FOOT.write(15);
  FR_FOOT.write(15);
  BL_FOOT.write(140);
  BR_FOOT.write(140);
}

void leanLeft()
{
  FL_FOOT.write(140);
  FR_FOOT.write(140);
  BL_FOOT.write(15);
  BR_FOOT.write(15);
}

void homePos()
{
  FL_HIP.write(40);
  FL_FOOT.write(110);
  FR_HIP.write(130);
  FR_FOOT.write(70);
  BL_HIP.write(130);
  BL_FOOT.write(70);
  BR_HIP.write(40);
  BR_FOOT.write(110);
}

void bow()
{
  FL_FOOT.write(140);
  FR_FOOT.write(15);
  BL_FOOT.write(130);
  BR_FOOT.write(30);
}

void bendBack()
{
  FL_FOOT.write(30);
  FR_FOOT.write(130);
  BL_FOOT.write(15);
  BR_FOOT.write(140);
}

void turnLeft()
{
  // Front left and back right leg
  // raises the foot in air
  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  // turns the hip around
  FL_HIP.write(0);
  BR_HIP.write(0);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);

  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(180);
  BL_HIP.write(180);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  // puts the hip back in original place
  FR_HIP.write(130);
  BL_HIP.write(130);
}

void turnRight()
{
  // Front left and back right leg
  //raises the foot in air
  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  // turns the hip around
  FL_HIP.write(10);
  BR_HIP.write(10);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);

  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(80);
  BL_HIP.write(80);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  // puts the hip back in original place
  FR_HIP.write(130);
  BL_HIP.write(130);
}

void walkForward()
{
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  FR_HIP.write(150);
  BL_HIP.write(110);
  FL_HIP.write(60);
  BR_HIP.write(20);

  delay(200);

  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  FL_HIP.write(20);
  BR_HIP.write(60);
  FR_HIP.write(110);
  BL_HIP.write(150);

  delay(200);

  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

int getDistance()
{
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  return cm;
}

void homePosArm()
{
  homePos();
  armShoulder.write(160);
  armElbow.write(0);
  armWrist.write(90);
  armFist.write(0);
}

void grab(){
  armFist.write(0);
  delay(700);
}

void release(){
  armFist.write(90);
  delay(700);
}

void horizontalFront()
{
  bow();
  armShoulder.write(170);
  armElbow.write(130);
  armWrist.write(90);
}

void verticalFront()
{
  bow();
  armShoulder.write(170);
  armElbow.write(130);
  armWrist.write(0);
}

void horizontalBack()
{
  bendBack();
  armShoulder.write(40);
  armElbow.write(0);
  armWrist.write(90);
}

void verticalBack()
{
  bendBack();
  armShoulder.write(40);
  armElbow.write(0);
  armWrist.write(0);
}

void homePosGrabBall()
{
  homePos();
  homePosArm();
  armFist.write(90);
  delay(1000);
  armFist.write(0);
}

void homePosGrabHatch()
{
  homePos();
  homePosArm();
  armFist.write(0);
  delay(1000);
  armFist.write(25);
}

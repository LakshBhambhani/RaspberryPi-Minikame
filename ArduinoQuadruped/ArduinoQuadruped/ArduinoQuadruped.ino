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

void setup() {
  FL_HIP.attach(4);
  FL_FOOT.attach(5);
  FR_HIP.attach(6);
  FR_FOOT.attach(7);
  BL_HIP.attach(8);
  BL_FOOT.attach(9);
  BR_HIP.attach(10);
  BR_FOOT.attach(11);

  homePos();

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
        turnLeft(7);
      }
      else if (serIn == "3") {
        Serial.println("Turning Right");
        turnRight(7);
      }
      else if (serIn == "4") {
        Serial.println("Leaning Right");
        for (int i = 0; i < 10; i++) {
          leanRight();
        }
      }
      else if (serIn == "5") {
        Serial.println("Leaning Left");
        leanLeft();
      }
      else if (serIn == "6") {
        Serial.println("Switching to Home Position");
        homePos();
      }
      else if (serIn == "7") {
        Serial.println("Bowing");
        bow();
      }
      else if (serIn == "8") {
        Serial.println("Bending Back");
        bendBack();
      }
    }
  }
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

void turnLeft(int x)
{
  for (int i = 0; i < x; i++) {
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
}

void turnRight(int x)
{
  for (int i = 0; i < x; i++) {
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

void pushUp() {
  FL_HIP.write(130);
  FL_FOOT.write(130);
  FR_HIP.write(30);
  FR_FOOT.write(50);

  BL_HIP.write(170);
  BL_FOOT.write(50);
  BR_HIP.write(10);
  BR_FOOT.write(130);

  delay(1000);

  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 25; k++) {
      FL_FOOT.write(130 + k);
      FR_FOOT.write(50 - k);
      delay(200);
    }
    for (int k = 0; k < 25; k++) {
      FL_FOOT.write(155 - k);
      FR_FOOT.write(25 + k);
      delay(200);
    }
  }
}

void jump() {
  BL_HIP.write(40);
  BR_HIP.write(140);
}

/*
   HomeAllServos by: Laksh Bhambhani
*/

#include <Servo.h>

Servo FL_HIP;       // Servo number: 1
Servo FL_FOOT;      // Servo number: 2
Servo FR_HIP;       // Servo number: 3
Servo FR_FOOT;      // Servo number: 4
Servo BL_HIP;       // Servo number: 5
Servo BL_FOOT;      // Servo number: 6
Servo BR_HIP;       // Servo number: 7
Servo BR_FOOT;      // Servo number: 8

Servo armShoulder;  // Servo number: 9
Servo armElbow;     // Servo number: 10
Servo armWrist;     // Servo number: 11
Servo armFist;      // Servo number: 12

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
}

void loop() {
  FL_HIP.write(40);
  FL_FOOT.write(110);
  FR_HIP.write(130);
  FR_FOOT.write(70);
  BL_HIP.write(130);
  BL_FOOT.write(70);
  BR_HIP.write(40);
  BR_FOOT.write(110);
  armShoulder.write(160);
  armElbow.write(0);
  armWrist.write(90);
  armFist.write(0);
}

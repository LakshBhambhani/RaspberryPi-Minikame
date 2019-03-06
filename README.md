# RaspberryPi-Minikame
Contains the code to use Minikame Mk2 using a raspberry pi

## Required Components

* Raspberry Pi
* Arduino
* 3D Printed Parts
* 12 Servo Motors from: [Amazon](https://www.amazon.com/Micro-Helicopter-Airplane-Remote-Control/dp/B072V529YD/ref=sr_1_1?keywords=servo+mototrs&qid=1551854557&s=gateway&sr=8-1-spell)

## 3D Printing

| Quantity      | File           
| ------------- | ----------------- 
| 1             | body_base.stl    
| 1             | body_top.stl        
| 2             | leg.stl      
| 2             | hips.stl      
| 1             | body_shafts.stl     
| 1             | arm_base.stl         
| 2             | shoulder.stl             
| 1             | elbow.stl        
| 1             | claw.stl      
| 1             | left_finger.stl         
| 1             | right_finger.stl        
| 1             | drive_gear.stl
| 1             | driven_gear.stl 

## Required Software

* Arduino IDE [Download](https://www.arduino.cc/en/Main/Software) 

Download the Arduino IDE Linux-ARM version on your Raspberry Pi

## Pre-Assembly Software and Hardware Check

### Serial Communication Check (optional)
1) Upload the "PiArduinoCommunicationTest.ino" which is in "RaspberryPi-Minikame/Pre-Assembly Checks/Serial Communication Check/" to your Arduino Board.
2) Open a new terminal on your Raspberry Pi adn execute the following:

```
sudo apt-get update 
sudo apt-get upgrade
git clone https://github.com/LakshBhambhani/RaspberryPi-Minikame.git
cd RaspberryPi-Minikame/Pre-Assembly Checks/Serial Communication Check/
sudo python pi_duino.py
```
Open the serial Monitor on the Arduino IDE and check for "hi" and "hello" being printed

### Server Check (optional)

1) On the same terminal as before execute the following:

```
cd ..
cd Server Check
sudo python weblamp.py
```

Now if you load the URL on browser, you should see a weblamp control page. Your URL would be the IP address of your raspberry pi. Ex: 192.168.0.36

### Homing all Servos

Number your servos and upload the following code to arduino to home your servos. Remember: Each servo has been set to a different home location. So each one has a different use and cannot be mixed up randomly later.

[Code](https://github.com/LakshBhambhani/RaspberryPi-Minikame/blob/master/Pre-Assembly%20Checks/Homing%20Servos/HomeAllServos/HomeAllServos.ino)

## The Server

You might want to check if your server works by using the files in the Server Check Folder. You might need to update and upgrade before 
doing stuff

```
sudo apt-get update
sudo apt-get upgrade
git clone https://github.com/LakshBhambhani/RaspberryPi-Minikame.git
cd RaspberryPi-Minikame
cd Server
sudo python quad.py
```

## The Arduino Code

Find the code to upload to the Arduino in the ArduinoQuadruped Folder and upload the .ino to your board
## Raspi Minikame Serial Code Sheet

| Sybsystem     | Method            | Arduino Value
| ------------- | ----------------- | ------------- 
| Quadruped     | walkForward()     | 1
|               | turnLeft()        | 2
|               | turnRight()       | 3
|               | leanRight()       | 4
|               | leanLeft()        | 5
|               | homePos()         | 6
|               | bow()             | 7
|               | bendBack()        | 8
| Arm           | homePosArm()      | 9
|               | grab()            | 10
|               | release()         | 11
|               | horizontalFront() | 12
|               | verticalFront()   | 13
|               | horizontalBack()  | 14
|               | verticalBack()    | 15
| Demo          | avoidObstacles()  | 16
|               | armDemo()         | 17
|               | leanDemo()        | 18


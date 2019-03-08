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

### Homing all Servos (MUST-DO)

Number your servos and upload the following code to arduino to home your servos. Remember: Each servo has been set to a different home location. So each one has a different use and cannot be mixed up randomly later.

[Link to HomingServos.ino Code](https://github.com/LakshBhambhani/RaspberryPi-Minikame/blob/master/Pre-Assembly%20Checks/Homing%20Servos/HomeAllServos/HomeAllServos.ino)

## Assembly

[![Watch the video](https://img.youtube.com/vi/v9tS9FaurnM/maxresdefault.jpg)](https://www.youtube.com/watch?v=v9tS9FaurnM)

## The Server

Execute the following in your terminal to get your server up and running. For now, you might have to execute the server python file each time your pi reboots. V2 of RaspberryPi-Minikame should get rid of that

```
cd RaspberryPi-Minikame
cd Server
sudo python quad.py
```

## The Arduino Code

If you wish to use an arm over it, then use the code: "ArduinoQuadrupedWithArm.ino"[Link to Quadruped Robot code](https://github.com/LakshBhambhani/RaspberryPi-Minikame/blob/master/ArduinoQuadruped/ArduinoQuadrupedWithArm.ino)
<br>Else use this code: "ArduinoQuadruped.ino" [Link to Quadruped Robot code](https://github.com/LakshBhambhani/RaspberryPi-Minikame/blob/master/ArduinoQuadruped/ArduinoQuadruped.ino)

## Raspi Quadruped App

You can either modify the app for yourself using the files in the [App Folder](https://github.com/LakshBhambhani/RaspberryPi-Minikame/tree/master/App/Android/RaspiQuadruped) or use the default provided [apk](https://github.com/LakshBhambhani/RaspberryPi-Minikame/blob/master/App/Android/RaspiQuadruped.apk)

## ENJOY!! 

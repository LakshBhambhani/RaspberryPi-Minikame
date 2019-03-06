# RaspberryPi-Minikame
Contains the code to use Minikame Mk2 using a raspberry pi

## Required Components

* Raspberry Pi
* Arduino
* 3D Printed Parts

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

## The Arduino Code

Find the code to upload to the Arduino in the ArduinoQuadruped Folder and upload the .ino to your board

## Pre-Assembly Software and Hardware Check (optional)

### Serial Communication Check
1) Upload the "PiArduinoCommunicationTest.ino" to your Arduino Board.
2) Open a new terminal on your Raspberry Pi adn execute the following:

```
sudo apt-get update 
sudo apt-get upgrade
git clone https://github.com/LakshBhambhani/RaspberryPi-Minikame.git
cd RaspberryPi-Minikame/Pre-Assembly Checks/Serial Communication Check/
sudo python pi_duino.py
```
Open the serial Monitor on the Arduino IDE and check for "hi" and "hello" being printed

### Server Check 

1) On the same terminal as before execute the following:

```
cd ..
cd Server Check
sudo python weblamp.py
```

Now if you load the URL on browser, you should see a weblamp control page. Your URL would be the IP address of your raspberry pi. Ex: 192.168.0.36

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


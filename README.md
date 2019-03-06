# RaspberryPi-Minikame-
Contains the code to use Minikame using a raspberry pi

## The Arduino Code

Find the code to upload to the Arduino in the ArduinoQuadruped Folder and upload the .ino to your board

## The Server

You might want to check if your server works by using the files in the Server Check Folder. You might need to update and upgrade before 
doing stuff

```
sudo apt-get update
sudo apt-get upgrade
git clone https://github.com/LakshBhambhani/RaspberryPi-Minikame-.git
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


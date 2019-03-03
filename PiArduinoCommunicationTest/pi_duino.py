import serial
import time
ser = serial.Serial("/dev/ttyUSB0", 9600)
ser.flushInput
time.sleep(5)
while 1 == 1:
    ser.write('1')
    time.sleep(5)
    ser.write('2')
    time.sleep(5)

import RPi.GPIO as GPIO
import serial
from flask import Flask, render_template, request

app = Flask(__name__)
ser = serial.Serial("/dev/ttyUSB0", 9600)

GPIO.setmode(GPIO.BCM)
ser.flushInput()

# Create a dictionary called pins to store the pin number, name, and pin state:
pins = {
   1 : {'name' : 'Port', 'state' : GPIO.LOW},
   4 : {'name' : 'Pin 4', 'state' : GPIO.LOW},
   5 : {'name' : 'Pin 5', 'state' : GPIO.LOW},
   6 : {'name' : 'Pin 6', 'state' : GPIO.LOW}, 
   12 : {'name' : 'Pin 12', 'state' : GPIO.LOW}, 
   13 : {'name' : 'Pin 13', 'state' : GPIO.LOW}, 
   14 : {'name' : 'Pin 14', 'state' : GPIO.LOW}, 
   16 : {'name' : 'Pin 16', 'state' : GPIO.LOW}, 
   17 : {'name' : 'Pin 17', 'state' : GPIO.LOW}, 
   18 : {'name' : 'Pin 18', 'state' : GPIO.LOW}, 
   19 : {'name' : 'Pin 19', 'state' : GPIO.LOW}, 
   20 : {'name' : 'Pin 20', 'state' : GPIO.LOW}, 
   21 : {'name' : 'Pin 21', 'state' : GPIO.LOW}, 
   22 : {'name' : 'Pin 22', 'state' : GPIO.LOW}, 
   23 : {'name' : 'Pin 23', 'state' : GPIO.LOW}, 
   26 : {'name' : 'Pin 26', 'state' : GPIO.LOW}, 
   }

# Set each pin as an output and make it low:
for pin in pins:
   GPIO.setup(pin, GPIO.OUT)
   GPIO.output(pin, GPIO.LOW)

@app.route('/')
def index():
    return render_template('main.html')
   
@app.route("/")
def main():
   # For each pin, read the pin state and store it in the pins dictionary:
   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)
   # Put the pin dictionary into the template data dictionary:
   templateData = {
      'pins' : pins
      }
   # Pass the template data into the template main.html and return it to the user
   return render_template('main.html', **templateData)

# The function below is executed when someone requests a URL with the pin number and action in it:
@app.route("/<changePin>/<action>")
def action(changePin, action):
   global message
   # Convert the pin from the URL into an integer:
   changePin = int(changePin)
   # Get the device name for the pin being changed:
   deviceName = pins[changePin]['name']
   # If the action part of the URL is "on," execute the code indented below:
   if action == "on":
      # Set the pin high:
      GPIO.output(changePin, GPIO.HIGH)
      # Save the status message to be passed into the template:
      message = "Turned " + deviceName + " on."
   if action == "off":
      GPIO.output(changePin, GPIO.LOW)
      message = "Turned " + deviceName + " off."
   if action == "toggle":
      # Read the pin and set it to whatever it isn't (that is, toggle it):
      GPIO.output(changePin, not GPIO.input(changePin))
      message = "Toggled " + deviceName + "."
   if action == "toggle" and changePin == 1:
      GPIO.output(changePin, not GPIO.input(changePin))
      if GPIO.input(changePin) == GPIO.HIGH:
         message = "Set " + deviceName + "to dev/ttyUSB0."
         ser = serial.Serial("/dev/ttyUSB0", 9600)
      if GPIO.input(changePin) == GPIO.LOW:
         message = "Set " + deviceName + "to dev/ttyUSB1."
         ser = serial.Serial("/dev/ttyUSB1", 9600)

   # For each pin, read the pin state and store it in the pins dictionary:
   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)

   # Along with the pin dictionary, put the message into the template data dictionary:
   templateData = {
      'message' : message,
      'pins' : pins
   }

   return render_template('main.html', **templateData)
   
@app.route("/<action1>")
def action1(action1):
   # Convert the pin from the URL into an integer:
   global message
   if action1 == "walkForward":
      message = "Walking Forward"
      ser.write("1")
   if action1 == "turnLeft":
      message = "Turning Left"
      ser.write("2")
   if action1 == "turnRight":
      message = "Turning Right"
      ser.write("3")
   if action1 == "leanRight":
      message = "Leaning Right"
      ser.write("4")
   if action1 == "leanLeft":
      message = "Leaning Left"
      ser.write("5")
   if action1 == "homePos":
      message = "Switching to Home Position"
      ser.write("6")
   if action1 == "bow":
      message = "Bowing"
      ser.write("7")
   if action1 == "bendBack":
      message = "Bending Back"
      ser.write("8")
   if action1 == "homePosArm":
      message = "Switching to Home Position Arm"
      ser.write("9")
   if action1 == "grab":
      message = "Grabbing"
      ser.write("10")
   if action1 == "release":
      message = "Releasing"
      ser.write("11")
   if action1 == "horizontalFront":
      message = "Switching to Horizontal Front"
      ser.write("12")
   if action1 == "verticalFront":
      message = "Switching to Vertical Front"
      ser.write("13")
   if action1 == "horizontalBack":
      message = "Switching to Horizontal Back"
      ser.write("14")
   if action1 == "verticalBack":
      message = "Switching Vertical Back"
      ser.write("15")
   if action1 == "avoidObstacles":
      message = "Avoiding Obstacles"
      ser.write("16")
   if action1 == "armDemo":
      message = "Starting Arm Demo"
      ser.write("17")
   if action1 == "leanDemo":
      message = "Starting Lean Demo"
      ser.write("18")
   # For each pin, read the pin state and store it in the pins dictionary:
   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)

   templateData = {
      'message' : message,
      'pins' : pins
   }

   return render_template('main.html', **templateData)

@app.route("/<action2>/<port>")
def action2(action2, port):
   # Convert the pin from the URL into an integer:
   if action2 == "set":
      ser = serial.Serial(port, 9600)

   

if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True)

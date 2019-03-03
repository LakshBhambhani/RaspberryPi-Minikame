from flask import Flask, render_template, request
import serial

app = Flask(__name__)
ser = serial.Serial("/dev/ttyUSB0", 9600)

ser.flushInput()

# The function below is executed when someone requests a URL with the pin number and action in it:
@app.route("/<action>")
def action(action):
   if action == "walkforward":
      ser.write("1")
      message = "Walking Forward"
   if action == "turnLeft":
      ser.write("2")
      message = "Turning Left"
   if action == "turnRight":
      ser.write("3")
      message = "Turning Right"

   # Along with the pin dictionary, put the message into the template data dictionary:
   templateData = {
      'message' : message
   }

   return render_template('main.html', **templateData)

if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True)

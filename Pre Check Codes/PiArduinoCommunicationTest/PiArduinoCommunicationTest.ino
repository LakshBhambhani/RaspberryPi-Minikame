
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  while(1 == 1){
  if(Serial.available() > 0){
    String serIn = Serial.readString();
    if(serIn == "1"){
      Serial.write("hi");
    }
    else if(serIn == "2"){
      Serial.write("hello");
    }
   }
  }
 }

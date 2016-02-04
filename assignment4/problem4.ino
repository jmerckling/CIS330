  //Variables to make code easier to read and update
  const int BLUE = 10;
  const int MIC = 2;

  
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(MIC, INPUT_PULLUP);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  //read the volume
  int sensorVal = digitalRead(MIC);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  //no sound reads true, sound reads false
  if (sensorVal == HIGH) {
    digitalWrite(BLUE, LOW);
  } else {
    digitalWrite(BLUE, HIGH);
  }
}

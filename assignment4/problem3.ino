// the setup function runs once when you press reset or power the board
const int LED = 10; //Set LED to output pin 10
const int dotLength = 500;  //set dot length to 500ms
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED, OUTPUT);
}

void elPause(){ //pause between elements
  digitalWrite(LED, LOW);
  delay(dotLength);
}

void dot(){  //Function for a dot
  digitalWrite(LED, HIGH);
  delay(dotLength);
  elPause();
}

void dash(){  //Function for a dash
  digitalWrite(LED, HIGH);
  delay(dotLength * 3);
  elPause();
}


void charPause(){ //pause between characters
  digitalWrite(LED, LOW);
  delay(dotLength * 3);
}

void dark(){  //pause between guesses
  digitalWrite(LED, LOW);
  delay(dotLength * 9); // makes 4.5 seconds because there is .5 after every letter
}

void writeLetter(char letter){
switch(letter){
    case 'A':
          dot();
          dash();
          break;
    case 'D':
          dash();
          dot();
          dot();
          break;
    case 'E':
          dot();
          break;
    case 'S':
          dot();
          dot();
          dot();
          break;
    case 'T':
          dash();
          break;
  }
}

String words[10] = {"EATS", "EAST", "DATE", "SADE", "TADS", "TEA", "SATE", "TEE", "TED", "EAT"};  //array of 10 words with letters
int choice = random(0, 10); // generates a random number between 0-9
String chosen = words[choice];


// the loop function runs over and over again forever
void loop(){
  Serial.begin(9600);
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < sizeof(chosen) - 1; i++){
      writeLetter(chosen[i]);
    }
  dark();
  }
  Serial.println(chosen);
  while(1){ }
}

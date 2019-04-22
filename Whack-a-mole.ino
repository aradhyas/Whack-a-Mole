// Whack a LED

// Joystick variables
int sX = A0;     //joystick x axis, analog input
int sY = A1;     //joystick y axis, analog input
int sSX;         //state of x, reading from sX
int sSY;         //state of y, reading from sY
int sS;          //converted state (may not be most efficient)

// Game variables
int rNum;        //random int choosing the random light to turn on
int wins=0;      //counting consecutive wins
int highScore=0; //saving the highest score of consecutive wins

// Difficulty constants, time to react
const int easy=1000;
const int medium=500;
const int hard=325;
const int stupid=250;


int ledPins[]={5,2,4,3,6,7,8}; //initializing led's
int pinCount=7;                //number of led pins

void setup() {

Serial.begin(9600);
pinMode(sX, INPUT);
pinMode(sY, INPUT);

for (int thisPin = 0; thisPin < pinCount; thisPin++) { //assigning all the pins as outputs in a for loop
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {

  rNum=random(4); //generating random choice
  delay(1000);
  digitalWrite(ledPins[rNum], HIGH); //lighting the randomly chosen bulb
  delay(easy); //difficulty
  
  //stick stuff
  sSX = analogRead(sX); //reading x axis input
  delay(100);
  sSY = analogRead(sY); //reading y axis input

  //converting y and x inputs to 4 possibilities. 0 and 1023 are the maximum values on each axis of the joystick, as measured.
  sS=0;
  switch (sSX) {
  case 0:
  sS=1;      // Left
  break;
  case 1023:
  sS=2;      // Right
  break;
}
switch (sSY) {
  case 0:
  sS=3;      // Up
  break;
  case 1023:
  sS=4;      // Down
  break;
}

  digitalWrite(ledPins[rNum], LOW); //turning off the randomly selected bulb, after the joystick choice was made
  if (sS-1==rNum) //checking if the user input the correct direction of the lit bulb
  {
    wins++;
    for (int k=0; k<=3; k++) {     //blinking green light indicating correct choice
    digitalWrite(ledPins[4], HIGH);
    delay(50);
    digitalWrite(ledPins[4], LOW);
    delay(50);
    }
  }
  else
  {
    if (wins>highScore) { //if the consecutive wins are more than the previous highscore, the new highscore is set.
        highScore=wins;
        wins=0;
    }
    for (int i=0; i<=3; i++) {       //blinking red light indicating incorrect choice
      digitalWrite(ledPins[5], HIGH);
      delay(50);
      digitalWrite(ledPins[5], LOW);
      delay(50);
    }
    for (int w=0; w<highScore; w++) { //displaying via counting and blinking the high score on a yellow bulb.
        digitalWrite(ledPins[6], HIGH);
        delay(200);
        digitalWrite(ledPins[6], LOW);
        delay(200);
    }  
  }  
  }

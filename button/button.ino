

const int buttonPin = 2;
const int redPin = 7;
const int greenPin1 = 6;
const int greenPin2 = 5;
const int greenPin3 = 4;
int redState = LOW;
int greenState1 = LOW;
int greenState2 = LOW;
int greenState3 = LOW;


int buttonState = 0;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin2, LOW);
    }
    else {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(greenPin3, HIGH);
      }

}



const int buttonPin = 2;
const int redPin = 7;
const int greenPin1 = 6;
const int greenPin2 = 5;
const int greenPin3 = 4;
int redState = LOW;
int greenState1 = LOW;
int greenState2 = LOW;
int greenState3 = LOW;
int lastButtonState = LOW;
unsigned long currentMillis = NULL;


int buttonState = 0;
long previousMillis = 0;
long T = 300;


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if ((buttonState == HIGH) && (lastButtonState == LOW)){
    unsigned long currentMillis = millis();
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    lastButtonState = HIGH;
    } else {
      if (currentMillis != NULL ) {
        previousMillis = currentMillis;
      unsigned long currentMillis = millis();
       }
       lastButtonState = LOW;
      }
      
   if (((currentMillis - previousMillis) >= T ) && ((currentMillis - previousMillis) < 3*T )){
     digitalWrite(redPin, HIGH);
     delay(500);
     digitalWrite(redPin, LOW);
    } 
  
  
  
    
      
  
        
     Serial.print(previousMillis);
     Serial.print(currentMillis);
     delay(1000);
}

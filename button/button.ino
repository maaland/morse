

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
int count = 0;

boolean dot = false;
boolean dash = false;

int firstTime = 1;
unsigned long startTime;
unsigned long pressTime;
unsigned long startPauseTime;
unsigned long pauseTime;
String results = " ";


int buttonState = 0;
long T = 100;


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
  

}

void loop() {
  if(digitalRead(buttonPin) == HIGH){
 if(firstTime == 1){
  startTime = millis();
  pauseTime = millis() - startPauseTime;
  firstTime=0;
 }
 
}
else if(firstTime == 0){
  pressTime = millis()- startTime;
  startPauseTime = millis();
 firstTime = 1;
}
      
 if (pressTime >= T && pressTime < 3*T) {
  dot = true;
  results = results + "dot";
  dash = false;
  Serial.print("dot");
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin1, LOW); 
  digitalWrite(greenPin2, LOW); 
  digitalWrite(greenPin3, LOW);
  delay(100); 
  pressTime = 0;
  } else if (pressTime >= 3*T) {
      dot = false;
      dash = true;
      results = results + "dash";
      Serial.print("dash");
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin1, HIGH); 
      digitalWrite(greenPin2, HIGH); 
      digitalWrite(greenPin3, HIGH);
      delay(100);
      pressTime = 0;
      pauseTime = 0;
    } else {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin1, LOW); 
      digitalWrite(greenPin2, LOW); 
      digitalWrite(greenPin3, LOW); }
      
  if (pauseTime >= 7*T) {
      dot = false;
      dash = false;
      results = results + "lp";
      Serial.print("lPause");
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin1, LOW); 
      digitalWrite(greenPin2, LOW); 
      digitalWrite(greenPin3, HIGH);
      pressTime = 0;
      pauseTime = 0;
      } else if (pauseTime >= 3*T && pauseTime < 7*T) {
      dot = false;
      dash = false;
      results = results + "mp";
      Serial.print("mPause");
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin1, HIGH); 
      digitalWrite(greenPin2, LOW); 
      digitalWrite(greenPin3, LOW);
      pressTime = 0;
      pauseTime = 0; 
      }
        
      
  Serial.print(results);
  
  
    
    
    
    
    
}

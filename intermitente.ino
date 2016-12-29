const int buttonPinLeft = 8;
const int buttonPinRight = 7;
const int buttonPinEmergencia = 2;

const int ledPinLeft = 13;
const int ledPinRight = 12;

unsigned long previousMillis = 0;
const long interval = 200; 


int buttonPushCounterLeft = 0; 
int buttonStateLeft = 0;         
int lastButtonStateLeft = 0; 

int buttonPushCounterRight = 0; 
int buttonStateRight = 0;         
int lastButtonStateRight = 0; 

int buttonPushCounterEmergencia = 0; 
int buttonStateEmergencia = 0;         
int lastButtonStateEmergencia = 0; 

void setup() {
  pinMode(buttonPinLeft, INPUT);
  pinMode(buttonPinRight, INPUT);
  pinMode(buttonPinEmergencia, INPUT);

  pinMode(ledPinLeft, OUTPUT);
  pinMode(ledPinRight, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  buttonStateLeft = digitalRead(buttonPinLeft);
  buttonStateRight = digitalRead(buttonPinRight);
  buttonStateEmergencia = digitalRead(buttonPinEmergencia);
  
   if (buttonStateEmergencia != lastButtonStateEmergencia) {
    if (buttonStateEmergencia == HIGH) {
      buttonPushCounterEmergencia++;
      buttonPushCounterLeft = 0;
      buttonPushCounterRight = 0;
      updateButton(buttonStateEmergencia, lastButtonStateEmergencia, buttonPushCounterEmergencia);
    }
    delay(50);
    
  } else if (buttonStateLeft != lastButtonStateLeft) {
    if (buttonStateLeft == HIGH) {
      buttonPushCounterLeft++;
      buttonPushCounterRight = 0;
      buttonPushCounterEmergencia = 0;
      updateButton(buttonStateLeft, lastButtonStateLeft, buttonPushCounterLeft);
    }
    delay(50);
    
  }else if (buttonStateRight != lastButtonStateRight) {
    if (buttonStateRight == HIGH) {
      buttonPushCounterRight++;
      buttonPushCounterLeft = 0;
      buttonPushCounterEmergencia = 0;
      updateButton(buttonStateRight, lastButtonStateRight, buttonPushCounterRight);
    }
    delay(50);
  }
  
  if (buttonPushCounterEmergencia % 2 != 0) {
      intermitenteEmergencia(); 
    }
  
  if (buttonPushCounterLeft % 2 != 0) {
      intermitenteDerecho(ledPinLeft);
    } else {
      digitalWrite(ledPinLeft, LOW);
    }
  
  if (buttonPushCounterRight % 2 != 0) {
      intermitenteDerecho(ledPinRight);
    } else {
      digitalWrite(ledPinRight, LOW);
    } 
}

void updateButton(int buttonState, int lastButtonState, int buttonPushCounter){
	lastButtonState = buttonState;
  	Serial.println(buttonPushCounter);
}

void intermitenteDerecho(int ledPin){
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
     digitalWrite(ledPin, HIGH);
  } else {
     digitalWrite(ledPin, LOW);
  }
}

void intermitenteEmergencia(){
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
     digitalWrite(ledPinLeft, HIGH);
     digitalWrite(ledPinRight, HIGH);
  } else {
     digitalWrite(ledPinLeft, LOW);
     digitalWrite(ledPinRight, LOW);
  }
}


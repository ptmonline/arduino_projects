int ledVehiculoVerde = 13;
int ledVehiculoAmarillo = 12;
int ledVehiculoRojo = 8;

int ledPeatonesGreen = 7;
int ledPeatonesRed = 4;

int semaforoCarsDelay = 4000;
int intermitenteDelay = 400;



void setup() {
  Serial.begin(9600);
  
  pinMode(ledVehiculoVerde, OUTPUT);
  pinMode(ledVehiculoAmarillo, OUTPUT);
  pinMode(ledVehiculoRojo, OUTPUT);
  pinMode(ledPeatonesGreen, OUTPUT);
  pinMode(ledPeatonesRed, OUTPUT);

}

void loop(){
  int sensorValue = analogRead(A0);
  float voltage= (sensorValue / 1023.0);
  Serial.println(voltage);
  semaforoCarsDelay = (4000 * voltage);
  intermitenteDelay = (400 * voltage);
	cochesOnPeatonesOff();
  	avisoCoches();
  	cochesOffPeatonesOn();
  	avisoPeatones();
}

void cochesOnPeatonesOff(){
  	digitalWrite(ledVehiculoVerde, HIGH);
  	digitalWrite(ledVehiculoRojo, LOW);
	digitalWrite(ledPeatonesGreen, LOW);
  	digitalWrite(ledPeatonesRed, HIGH);
  	delay(semaforoCarsDelay);
}

void avisoCoches(){
	digitalWrite(ledVehiculoVerde, LOW);
  	digitalWrite(ledVehiculoRojo, LOW);
	digitalWrite(ledPeatonesGreen, LOW);
  	digitalWrite(ledVehiculoAmarillo, HIGH);
  	delay(semaforoCarsDelay);
}

void cochesOffPeatonesOn(){
	digitalWrite(ledVehiculoVerde, LOW);
  	digitalWrite(ledVehiculoRojo, HIGH);
  	digitalWrite(ledPeatonesRed, LOW);
	digitalWrite(ledPeatonesGreen, HIGH);
  	digitalWrite(ledVehiculoAmarillo, LOW);
  	delay(semaforoCarsDelay / 2);
}

void avisoPeatones(){
	int smallLoop = 8;
    while(smallLoop >= 0){
      digitalWrite(ledPeatonesGreen, HIGH);
      delay(intermitenteDelay);
      digitalWrite(ledPeatonesGreen, LOW);
      delay(intermitenteDelay);
      smallLoop --;
    } 
    digitalWrite(ledVehiculoRojo, LOW);
    digitalWrite(ledVehiculoVerde, HIGH);
}

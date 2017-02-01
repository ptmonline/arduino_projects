int ping = 7; //init int

void setup()
{
	Serial.begin(9600);	
}

void loop()
{
	float duration;
	float cm;
  	float velocidad;
	pinMode(ping, OUTPUT);
	digitalWrite(ping, HIGH);
	digitalWrite(ping, LOW);

	pinMode(ping, INPUT);
	duration = pulseIn(ping, HIGH);

	cm = (duration / 2) / 29;
	velocidad = (cm / duration);
        
        Serial.print('\n');
        Serial.println("Distancia");
	Serial.print(cm);
	Serial.println(" cm");
  	Serial.print('\n'); 
  	Serial.println("Velocidad ");
        Serial.print(duration / 1000);
  	Serial.print('\n');
	delay(1000);
}

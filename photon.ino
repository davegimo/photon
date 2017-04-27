int led = D7;
int pir = D1;
int buzzer = D0;

int analogVal = 0;
int intruders = 0;

int alarmOn = 0;

/* This function is called once at start up ----------------------------------*/
void setup()
{
	//Setup the Tinker application here

	//Register all the functions
	Particle.function("stop", stop);
	Particle.function("start", start);
	//Particle.variable("callsToStop", &analogVal, INT);
	Particle.variable("intruders", & intruders, INT);
	Particle.variable("alarmOn", & alarmOn, INT);
	Particle.subscribe("motion_detected", handler);
	Serial.begin(9600);

}

/* This function loops forever --------------------------------------------*/
void loop()
{
	//This will run in a loop
	pinMode(pir, INPUT_PULLDOWN);
	if(digitalRead(D1)==HIGH && alarmOn==0){
	    Particle.publish("motion_detected", "", 70);
	    intruders = intruders+1;
	    pinMode(led, OUTPUT);
	    digitalWrite(led, HIGH);
	    pinMode(buzzer, OUTPUT);
	    analogWrite(buzzer, 25);
	    alarmOn = 1;
	    /*delay(5000);
	    pinMode(led, OUTPUT);
	    digitalWrite(led, LOW);
	    pinMode(buzzer, OUTPUT);
	    analogWrite(buzzer, 0);
	    */
	}

}


int stop(String command){
    //analogVal = analogVal+1;
	pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    pinMode(buzzer, OUTPUT);
    analogWrite(buzzer, 0);
    alarmOn = 0;
    return 1;
}

int start(String command){
	pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    pinMode(buzzer, OUTPUT);
    analogWrite(buzzer, 25);
    return 1;
}

void handler(const char *event, const char *data){
    Serial.println("handler called");
    Serial.print(event);
    Serial.print(", data: ");
    Serial.println(data);
}

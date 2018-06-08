const int serial_out = 13;
const int clock = 2;

int a[8] = {HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW};



void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clock, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
	int i;
  for (i = 0; i < 8; ++i)
  {
  	digitalWrite(serial_out, a[i]);
  	if (digitalRead(clock) == HIGH)
   {
  		digitalWrite(clock, LOW);
  		delay(50);
  		digitalWrite(clock, HIGH);
   }
  	else
    {
  		digitalWrite(clock, HIGH);
  		delay(50);
  		digitalWrite(clock, LOW);
    }
    delay(50);
  }
}


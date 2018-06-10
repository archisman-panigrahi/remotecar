const int serial_out = 2;
const int clk = 4;
const int enable = 5;
int i=0;

int a[8]; //{Dummy,Dummy,Dummy,Dummy,front left,front right,back left,back right} 
//Motion of wheels - LOW is backward, HIGH is forward
int forward[8] = {LOW,LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH};
int backward[8] = {LOW,LOW,LOW,LOW,LOW,LOW,LOW};
int right[8] = {LOW,LOW,LOW,LOW,HIGH,LOW,HIGH,LOW};
int left[8] = {LOW,LOW,LOW,LOW,LOW,HIGH,LOW,HIGH};
unsigned long ptime = 0; //time of previous change
unsigned long ctime; //current time
long interval = 50;

void setup()
{
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(clk, LOW);
}

void alterValue (int pin)
{
	if (digitalRead(pin) == HIGH)
	{
		digitalWrite(pin, LOW);
	}
	else
	{
		digitalWrite(pin, HIGH);
	}
}
void loop()
{
	a = forward; //This is temporary. Later we will change this dynamically with Raspberry Pi
  ctime = millis();
  if (ctime - ptime >= interval)
  {
  	digitalWrite(serial_out, a[i]);
  	alterValue(clk);
  	i++;
  	if (i == 8)
  	{
  		digitalWrite(enable, HIGH);
  		i = 0;
  		ptime = ctime;
  		delay(50);
  	}
  }
  else if (ctime - ptime >= (interval/2))
  {
  	alterValue(clk);
  }
}

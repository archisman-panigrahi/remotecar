/* Note there might be glitches in the D flip flop output if the motor driver
   is connected to the flip-flop, but not connected to power. Once the motor deiver
   gets power and the motors start running, there will be no glitches. */

const int serial_out = 2;
const int clk = 4;
const int enable = 7;
int i=0;
int p=0; //This is for stopping the racing of clock

int a[8];// = {LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,HIGH};//{Dummy,Dummy,Dummy,Dummy,front left,front right,back left,back right} 
//Motion of wheels - LOW is backward, HIGH is forward
int forward[8] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};
int backward[8] = {LOW,LOW,LOW,LOW,LOW,LOW,LOW};
int right[8] = {HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH};
int left[8] = {LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH};
unsigned long previousTime = 0; //time of previous change
unsigned long currentTime;
long interval = 10; //time period of clock in milliseconds

void setup()
{
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enable, OUTPUT);
  copy(a,left,8); //This is temporary. Later we will change this dynamically with Raspberry Pi
  digitalWrite(clk, HIGH); //Initially clock should be high due to positive edge triggered IC
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
  currentTime = millis(); //current time
  if((currentTime - previousTime) > interval)
  {
  	if (i == 0)
  	{
  		digitalWrite(enable, HIGH);
  	}
    if (i == 1)
    {
      digitalWrite(enable, LOW);
    }
    previousTime = currentTime;
  	digitalWrite(serial_out, a[i]);
    Serial.print(i);
    Serial.print("  ");
    Serial.println(a[i]);
  	i++;
  	if(i == 8)
  	{
  		i = 0;
  	}
    alterValue(clk);
    p = 0;
  }
  else if (currentTime - previousTime >= (interval/2) && p == 0)
  {
  	alterValue(clk);
    p = 1;
  }
}

void copy(int destination[], int source[], int count)
{
	int k;
	for (k = 0; k < count; ++k)
	{
		destination[k] = source[k];
	}
}

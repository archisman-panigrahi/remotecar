/* Note there might be glitches in the D flip flop output if the motor driver
   is connected to the flip-flop, but not connected to power. Once the motor deiver
   gets power and the motors start running, there will be no glitches. */

const int serial_out = 2;
const int clk = 4;
const int enable = 7;
int i=0;
int p=0; //This is for stopping the racing of clock
int input;

int a[8];// = {LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,HIGH};//{Dummy,Dummy,front left,front right,mid left,mid right,back left,back right} 
//Motion of wheels - LOW is backward, HIGH is forward
int forward[8] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};
int backward[8] = {LOW,LOW,LOW,LOW,LOW,LOW,LOW};
int fastright[8] = {HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW};
int fastleft[8] = {LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH};
int slowleft[8] = {LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,HIGH};
int slowright[8] = {HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH};
unsigned long previousTime = 0; //time of previous change
unsigned long currentTime;
long interval = 10; //time period of clock in milliseconds

void setup()
{
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enable, OUTPUT);
  copy(a,forward,8); //This is the initial condition. Later we will change this dynamically with Raspberry Pi
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
    //Serial.print(i);
    //Serial.print("  ");
    //Serial.println(a[i]);
  	i++;
  	if(i == 8)
  	{
  		i = 0;
      if(Serial.available()) // Don't keep this outside. Somehow the clock does not move correctly in that case
      {
        input = Serial.read();
      }
        if (input == 97)
      {
        //Serial.println(input); //These prints interrupt with the orders from raspberry pi
        copy(a,forward,8);
        //Serial.println("moving forward");
    
      }
      else if (input == 98)
      {
        copy(a,backward,8);
        //Serial.println("moving backward");
      }
      else if (input == 99)
      {
        copy(a,fastleft,8);
        //Serial.println("moving left");
      }
      else if (input == 100)
      {
        copy(a,fastright,8);
        //Serial.println("moving right");
      }
      else if (input == 101)
      {
        copy(a,slowleft,8);
      }
      else if (input == 102)
      {
        copy(a,slowright,8);
      } 
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

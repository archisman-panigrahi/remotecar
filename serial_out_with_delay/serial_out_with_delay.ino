const int serial_out = 2;
const int clk = 4;
const int enable = 7;
int i;

int a[8] = {LOW,LOW,LOW,LOW,LOW,HIGH,LOW,HIGH}; //{Dummy,Dummy,Dummy,Dummy,front left,front right,back left,back right}
//Motion of wheels - LOW is backward, HIGH is forward

void setup() 
{
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enable, OUTPUT);
}

void loop() 
{
  for (i = 0; i < 8; ++i)
  {
  	digitalWrite(serial_out, a[i]);
  	if (digitalRead(clk) == HIGH)
   {
  		digitalWrite(clk, LOW);
  		delay(25);
  		digitalWrite(clk, HIGH);
   }
  	else
    {
  		digitalWrite(clk, HIGH);
  		delay(25);
  		digitalWrite(clk, LOW);
    }
    delay(25);
  }
   if(i == 8)
   {
      digitalWrite(enable, HIGH);
      delay(25);
      digitalWrite(enable, LOW);
    }
}


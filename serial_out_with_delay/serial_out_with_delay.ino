const int serial_out = 13;
const int clk = 2;
const int enable = 3;
int i;

int a[8] = {LOW,LOW,LOW,LOW,LOW,HIGH,LOW,HIGH};


void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(serial_out, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enable, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
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
   if(i == 8){
      digitalWrite(enable, HIGH);
      delay(25);
      digitalWrite(enable, LOW);
    }
}


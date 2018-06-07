/* HC-SR04 Sensor based on
   https://www.dealextreme.com/p/hc-sr04-ultrasonic-sensor-distance-measuring-module-133696
   and https://www.theengineeringprojects.com/2015/02/interfacing-multiple-ultrasonic-sensor-arduino.html
   
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2 (We are using a single trig pin for all sensors)
  * ECHO connection of the sensor attached to digital pin 4

*/


const int trigPin = 2;

const int echoPinLeft = 3;
const int echoPinMid = 5;
const int echoPinRight = 6;

const int LedLeft = 10;
const int LedMid = 11;
const int LedRight = 12;

long distance;
long duration;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  //Initialize LED
  //pinMode(LedLeft, OUTPUT);
  //pinMode(LedMid, OUTPUT);
  //pinMode(LedRight, OUTPUT);
  //Input echo pins
  pinMode(echoPinLeft, INPUT);
  pinMode(echoPinMid, INPUT);
  pinMode(echoPinRight, INPUT);
  //Output trig pin
  pinMode(trigPin, OUTPUT);
}

void loop()
{

  long cmLeft, cmMid, cmRight;

  //digitalWrite(LedLeft, LOW);
  //digitalWrite(LedMid, LOW);
  //digitalWrite(LedRight, LOW);
  calculateDistance(trigPin, echoPinLeft);
  cmLeft = distance;
  calculateDistance(trigPin, echoPinMid);
  cmMid = distance;
  calculateDistance(trigPin, echoPinRight);
  cmRight = distance;
  Serial.print(cmLeft);
  Serial.print("cm Left ");

  Serial.print(cmMid);
  Serial.print("cm Mid  ");

  Serial.print(cmRight);
  Serial.println("cm Right");

  /*
  if (cmLeft <= 10)
  {
  	digitalWrite(LedLeft, HIGH);
  }
  if (cmMid <= 10)
  {
  	digitalWrite(LedMid, HIGH);
  }
  if (cmRight <= 10)
  {
  	digitalWrite(LedRight, HIGH);
  }*/
  delay(10);
}


void calculateDistance(int trigPin, int echoPin)
{

	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);  //This is for a clear, high pulse
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	//Sound travels 1 cm at 29.4 microseconds, it is 
	//divided by 2 as the ultrasound travels out and back
	distance = (duration/2)/29.4; 
}

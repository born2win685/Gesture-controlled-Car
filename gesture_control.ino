//by B Sathiya Naraayanan
//demo video:https://youtu.be/NMyYmx-K_cc

const int trigPin = 9;
const int echoPin = 10;
const int trigright= 7;
const int echoright=6;
const int trigleft=5;
const int echoleft=4;
const int ledpin=11;
const int flag=12;
const int led_r=8;
const int led_l=13;

// defines variables
long duration;
int distance,R,L;
void setup() {
pinMode(ledpin,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
  
digitalWrite(led_r,LOW);
digitalWrite(led_l,LOW);
digitalWrite(ledpin,LOW);
digitalWrite(flag,LOW);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;


digitalWrite(trigright, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigright, HIGH);
delayMicroseconds(10);
digitalWrite(trigright, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoright, HIGH);
// Calculating the distance
R= duration*0.034/2;
if(R<20)
{
  digitalWrite(led_r,HIGH); 
}

digitalWrite(trigleft, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigleft, HIGH);
delayMicroseconds(10);
digitalWrite(trigleft, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoleft, HIGH);
// Calculating the distance
L=duration*0.034/2;
if(L<20)
{
  digitalWrite(led_l,HIGH); 
}


if(int(distance)<=20)
{
  digitalWrite(flag,HIGH);
  digitalWrite(ledpin,HIGH);
  analogWrite(ledpin,(255-(12*distance)));
}
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.print("Distancer: ");
//Serial.println(R);
//Serial.print("Distancel: ");
//Serial.println(L);
}

const int trigPin = 9;
const int echoPin = 10;
const int trigright= 7;
const int echoright=6;
const int trigleft=5;
const int echoleft=4;
const int ledpin=11;
const int flag=12;
const int led_l=8;
const int led_r=13;

// defines variables
long duration;
long
distance,R,L;
void setup() {
pinMode(ledpin,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(led_r,OUTPUT);
pinMode(trigright, OUTPUT); // Sets the trigPin as an Output
pinMode(echoright, INPUT);
pinMode(led_l,OUTPUT);
pinMode(trigleft, OUTPUT); // Sets the trigPin as an Output
pinMode(echoleft, INPUT);
Serial.begin(38400); // Starts the serial communication
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
if(int(distance)<=20)
{
  digitalWrite(flag,HIGH);
  digitalWrite(ledpin,HIGH);
  analogWrite(ledpin,(255-(12*distance)));
}

if(int(distance)<=20 && int(distance)>15){
  Serial.println("a");
}
else if(int(distance)<=15 && int(distance)>10){
  Serial.println("b");
}
else if(int(distance)<=10 && int(distance)>5){
  Serial.println("c");
}
else if(int(distance)<=5 && int(distance)>0){
  Serial.println("d");
}

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
if(int(R)<=3)
{
  digitalWrite(13,HIGH);
  Serial.println("r"); 
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
if(int(L)<=3)
{
  digitalWrite(8,HIGH);
  Serial.println("l"); 
}
if(int(distance)>20 && L>3 && R>3){
  Serial.println("s");
}

}

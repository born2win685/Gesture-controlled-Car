
//*********************With object avoidance**********************

const int motorIn1
= 9;  

const int motorIn2
= 10;  

const int motorInL1
= 5;

const int motorInL2
= 6;


void setup()

{
  Serial.begin(38400);
  pinMode(motorIn1,OUTPUT);  
  pinMode(motorIn2,OUTPUT); 
  pinMode(motorInL1,OUTPUT);  
  pinMode(motorInL2,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
}

void loop()

{
  long distance = get_distance_cm(7,8);
  if(distance>=10){
    
  
  if (Serial.available()){
    char val = Serial.read();
    if(val=='a'){
      forward(120);
    }
    else if(val=='b'){
      forward(160);
    }
    else if(val=='c'){
      forward(200);
    }
    else if(val=='d'){
      forward(255);
    }
    else if(val=='l'){
      left(255);
    }
    else if(val=='r'){
      right(255);
    }
    else if(val=='s'){
      stopm();
    }
  }
}
else{
 stopm();
    buzzer(distance);
 
}
}

long get_distance_cm(int trig, int echo)
{
  long distance;
  
  //digitalWrite(trig, LOW);
  //delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  return distance;
}

void left(int Speed){
  analogWrite(motorIn2,Speed);  

  analogWrite(motorIn1,0);  

  analogWrite(motorInL2,0);  

  analogWrite(motorInL1,0); 
}

void right(int Speed){
  analogWrite(motorIn2,0);  

  analogWrite(motorIn1,0);  

  analogWrite(motorInL2,Speed);  

  analogWrite(motorInL1,0); 
}
void stopm()

{

  analogWrite(motorIn2,0);  

  analogWrite(motorIn1,0);  

  analogWrite(motorInL2,0);  

  analogWrite(motorInL1,0);  

}

void forward(int Speed)

{

  analogWrite(motorIn2,Speed);  

  analogWrite(motorIn1,0);  

  analogWrite(motorInL2,Speed);  

  analogWrite(motorInL1,0);  

}


void buzzer(long distance) {
  if(distance<10&&distance>5)
    {
       tone(12,500);
       delay(1000);
       noTone(12);
    }

}

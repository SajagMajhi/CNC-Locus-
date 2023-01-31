

void setup() 
{
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() 
{
  //right
 digitalWrite(8,LOW);  //back
 digitalWrite(9,HIGH);  //front

//left
 digitalWrite(7,LOW); //back
 digitalWrite(6,HIGH); //front
}

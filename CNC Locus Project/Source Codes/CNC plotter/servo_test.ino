#include <Servo.h> 

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
int pos = 0;  // variable to store the servo position

void setup() 
{
  myservo1.attach(9);   
  myservo2.attach(10); 
  
}

void loop() 
{
  // sweeps from 0 degrees to 180 degrees
  for(pos = 0; pos <= 180; pos += 1) 
  {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(15);
  }


   delay(200); 
  
  // sweeps from 180 degrees to 0 degrees
  for(pos = 180; pos>=0; pos-=1)
  {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(15);
  }

   myservo1.detach();
   myservo2.detach();
   delay(200);
   myservo1.attach(9);
   myservo2.attach(10);   
   
}

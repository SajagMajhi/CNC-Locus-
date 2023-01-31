#include <Servo.h>
#include <AFMotor.h>

AF_Stepper motorY(200,1);
AF_Stepper motorX(200,2);

Servo myservo1;  // create servo object to control a servo

int pos = 0;  // variable to store the servo position
int i=0;

void setup() {
  motorX.setSpeed(200);
  motorY.setSpeed(200);

  myservo1.attach(10);
 
 myservo1.write(0);
  while(i<7000)
  {
    motorY.onestep(1,MICROSTEP);
    delay(1);
    i++;
  } 
  myservo1.write(40);
  
 // myservo1.write(60);
 // motorY.step(1,FORWARD,MICROSTEP);
  //delay(100);
  // motorY.step(1,FORWARD,MICROSTEP);
 // myservo1.write(100);

}

//myservo2.attach(10);

void loop() {
  /*
  myservo1.write(0);
  delay(1000);
   myservo1.write(40);
   delay(1000);*/

  //motorX.step(50,FORWARD,MICROSTEP);
 // motorY.step(50,FORWARD,MICROSTEP);
 // motorX.step(50,BACKWARD,MICROSTEP);
 // motorY.step(50,BACKWARD,MICROSTEP);

  /*
  delay(500);
  myservo1.write(100);//initial
  delay(500);
  myservo1.write(60);//final 120
  delay(500);*/
  //motorX.onestep(FORWARD,MICROSTEP);
 //motorY.onestep(BACKWARD,MICROSTEP);

/*
 while(i<25)
 {
  motorX.onestep(FORWARD,MICROSTEP);
  //motorY.onestep(FORWARD,MICROSTEP);
  i++;
 }*/
  //motorY.onestep(FORWARD,MICROSTEP);
/*
if(i==0)
  for(i=0;i<50;i++)
  {
   motorX.step(1,FORWARD,MICROSTEP);
   motorY.step(1,FORWARD,MICROSTEP);
  }
  //motorX.step(1,BACKWARD,MICROSTEP);
  //motorY.step(1,BACKWARD,MICROSTEP);*/
  
  /*
motorX.onestep(1,MICROSTEP);
    motorY.onestep(1,MICROSTEP);
    delay(1);*/
/*
  while(i<2000)
  {
    motorX.onestep(1,MICROSTEP);
    motorY.onestep(-1,MICROSTEP);
    delay(1);
    i++;
  } 
delay(1000);

i=0;
  while(i<2000)
  {
    motorX.onestep(-1,MICROSTEP);
    motorY.onestep(1,MICROSTEP);
    delay(1);
    i++;
  } 
  delay(1000);
 i=0;*/
}

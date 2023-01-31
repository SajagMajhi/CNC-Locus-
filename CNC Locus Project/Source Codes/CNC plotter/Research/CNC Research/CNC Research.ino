#include<Servo.h>
#include<AFMotor.h>

// delay(milliseconds) 
AF_Stepper motorx(48,2); //X axis Port no 2
/*class_name object(parameter1,parameter2)
paramter1 = No of Steps
paramter2 = Port no in Shield */
AF_Stepper motory(48,1);  //Y axis motor no 1

Servo servo1; // class_name object;

int i,Speed = 50,steps = 50;
void setup() {
  Serial.begin(9600);
  motorx.setSpeed(Speed);
  motory.setSpeed(Speed);
  /*class_name.member_func(parameter);
    parameter = speed value(RPM)*/

  servo1.attach(10);
}

void loop() {
  motorx.step(steps,FORWARD,MICROSTEP);
  motory.step(steps,FORWARD,MICROSTEP);
  delay(100);
  motorx.step(steps,BACKWARD,MICROSTEP);
  motory.step(steps,BACKWARD,MICROSTEP);
  delay(100);
  
  /*object.func(no_of_steps,DIRECTION,MODE);
    object=motorx and motory
    func= step() inside AF_Stepper class
    DIRECTION = FORWARD & BACKWARD
    MODE = SINGLE, DOUBLE, MICROSTEP
  */
  servo1.write(0); //object.func(int); parameter(int)=angle < 200
  delay(1000); // 1000ms=1sec
  servo1.write(60);
  delay(1000); 

  for(i=0;i<=180;i++)
  {
     servo1.write(i);// 1 degree rotate per millisecond
     delay(100);
  }
  /*stop steppers
    motorx.release(); 
    motory.release();*/
}

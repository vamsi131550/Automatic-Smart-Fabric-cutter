#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepperX(STEPS, 6, 7, 8, 9);     //x (top) platform
Stepper stepperY(STEPS, 2, 3, 4, 5);     //y (bottom) platform
Stepper stepperZ(STEPS, 10, 11, 12, 13); //z pen

int x_inc = 0;
int y_inc = 0;
int z_pos = 0;

word image[16] = {
  0b0000001110000000,
  0b0010011111000100,
  0b0010001110000100,
  0b0010000100000100,
  0b0011111111111100,
  0b0000011111000000,
  0b0000011111000000,
  0b0000001110000000,
  0b0000011111000000,
  0b0000011111000000,
  0b0000110001100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0011100000111000,
  0b0011100000111000,
  0b1111111111111111
};


void setup()
{
  // set the speed of the motors to 60 RPMs
  stepperX.setSpeed(60); //bottom (60rpm)
  stepperY.setSpeed(60); //top (60rpm)
  stepperZ.setSpeed(60); //Pen (60rpm);
  delay(2000);
}

void loop()
{
    
    for(int row = 0; row < 16; row++) { 

      penUp();
     
      
      stepperX.step(-x_inc);
      x_inc = 0;  

      for(int column = 0; column < 16; column++){ 
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1){

          penDown();
          
          //move X-Axis forward 5 steps for each bit in the array
          stepperX.step(10);
          x_inc = x_inc + 10;
          delay(15);
        }
        else{

          penUp();
          
          //move X-Axis forward 5 steps for each bit in the array
          stepperX.step(10);
          x_inc = x_inc + 10;
          delay(15);

        }
      }
      
      penUp();

      //Position Y-Axis for next row
      stepperY.step(10);
      y_inc = y_inc + 10;
      delay(15);
    }
  
  penUp();

  //Return X/Y-Axis back to home position
  stepperX.step(-x_inc);
  stepperY.step(-y_inc);
 
  //Endless Loop
  while(1){
  }
  
}


void penDown()
{
  //if the pen is raised
  if (z_pos == 0){
    //move the pen to the paper
    stepperZ.step(83);  
    delay(15);
    z_pos = 83;
  }
}

void penUp()
{
  //if the pen against the paper
  if(z_pos == 83){
    //move pen away from paper
    stepperZ.step(-83); 
    delay(15);
    z_pos = 0; 
  }
}



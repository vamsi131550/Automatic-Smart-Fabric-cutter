#include <SPI.h>
#include <SD.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);

  #define SD_PIN 2
  #define SERVO_PIN A1

  #define COIL_X_1 3
  #define COIL_X_2 4
  #define COIL_X_3 5
  #define COIL_X_4 6

  #define COIL_Y_1 7
  #define COIL_Y_2 8
  #define COIL_Y_3 9
  #define COIL_Y_4 10
  
  #define X_MAX 450
  #define Y_MAX 200

  #define S1_PIN A2
  #define S2_PIN A3

  #define X_STEPS_PER_MM 50
  #define Y_STEPS_PER_MM 50

  #define SERVO_UP 1300
  #define SERVO_DOWN 1400

  #define WAIT_TIME 3

File myFile;
Servo myServo;

char motorX[5] = {COIL_X_1, COIL_X_2, COIL_X_3, COIL_X_4};
int CX1 = 3;
int CX2 = 0;

char motorY[5] = {COIL_Y_1, COIL_Y_2, COIL_Y_3, COIL_Y_4};
int CY1 = 3;
int CY2 = 0;
char data[61];
int commandType = -1;
int a = 0;
int b = 1;
int i = 1;
int c = 0;
char value[11];
char valueComma[7] = {0, 0, 0, 0, 0, 0};
int comma = 0;
int numberComma = 0;

int remainedX = 0;
int remainedY = 0;
float number = 0.000;
int steps = 0;
int minus = 0;

int column = 0;
int positionLCD = 0;
int pulse = 0;
int buttonHold = 0;
int button = 0;
int menu = 0;

int ai = 0;
int bi = 0;
int yi = 0;
int xi = 0;
int d = 0;
int x = 0;
int y = 0;
int xj = 0;
int yj = 0;


int positionXsteps = 0;
int positionYsteps = 0;

int targetXsteps = 0;
int targetYsteps = 0;


void setup() {
Serial.begin(9600);

while (!Serial) {
  delay(1);
}


pinMode(COIL_X_1, OUTPUT);
pinMode(COIL_X_2, OUTPUT);
pinMode(COIL_X_3, OUTPUT);
pinMode(COIL_X_4, OUTPUT);
pinMode(COIL_Y_1, OUTPUT);
pinMode(COIL_Y_2, OUTPUT);
pinMode(COIL_Y_3, OUTPUT);
pinMode(COIL_Y_4, OUTPUT);

digitalWrite(COIL_X_1, HIGH);
digitalWrite(COIL_Y_1, HIGH);

myServo.attach(SERVO_PIN);
myServo.writeMicroseconds(SERVO_UP);

steps = 1000 / X_STEPS_PER_MM;

lcd.begin (16,2);
lcd.setBacklightPin(3, POSITIVE);
lcd.setBacklight(125);
lcd.home();

infoScreen();
}










void loop() {
  for (a = 0; a < 61; a++) {
    data[a] = 0;
  }
  a = 0;
  b = 1;

  LCDmain();
}






// Command types: X = 1, Y = 2, G = 3, 

void decode1() {
 a = 0;
 for (a = 0; a < 61; a++) {
  switch (data[a]) {
    case 'F':
      comma = 0;
      commandType = 3;
      break;
    case 'X':
      comma = 0;
      commandType = 1;
      break;
    case 'Y':
      comma = 0;
      commandType = 2;
      break;
    case 'Z':
      comma = 0;
      commandType = 4;
      break;  
    case '-':
      minus = 1;
      break;
    case '0': digit(); break;
    case '1': digit(); break;
    case '2': digit(); break;
    case '3': digit(); break;
    case '4': digit(); break;
    case '5': digit(); break;
    case '6': digit(); break;
    case '7': digit(); break;
    case '8': digit(); break;
    case '9': digit(); break;
    
    case 10:           //new line - SD
      comma = 0;
      organize();
      b = 1;
      break;
    case 13:
      organize();
      b = 1;
      break;
    case 46:           // dot
      b = 1;
      comma = 1;
      break;
    case 32:           //space
      comma = 0;
      organize();
      b = 1;
      break;
  }
 }
}







void digit() {
  if (comma == 1) {
    valueComma[b] = data[a] - 48;
    b++;
  } else {
    value[b] = data[a] - 48;
    b++;
    c++;
  }
}


void organize() {
  switch (c) {
    case 1:
      number = value[1];
      break;
    case 2:
      number = (value[1] * 10) + value[2];
      break;
    case 3:
      number = (value[1] * 100) + (value[2] * 10) + value[3];
      break;
  }
  c = 0;
  numberComma = (valueComma[1] * 100) + (valueComma[2] * 10) + valueComma[3];
  valueComma[1] = 0;
  valueComma[2] = 0;
  valueComma[3] = 0;
  valueComma[4] = 0;
  valueComma[5] = 0;
  valueComma[6] = 0;
  
  numberComma = numberComma - (numberComma % steps);
  
  number = number + (numberComma / 1000.000) * 1.000;

  if (minus == 1) {
    number = -number;
    minus = 0;
  }


  
  switch (commandType) {
    case 1: //X
      if (number > X_MAX) {
        number = X_MAX;
      }
      targetXsteps = number * X_STEPS_PER_MM; 
      break;
    case 2: //Y
      if (number > Y_MAX) {
        number = Y_MAX;
      } 
      targetYsteps = number * Y_STEPS_PER_MM;
      break;
    case 4: //Z
      if (number > 0.04) {
        myServo.writeMicroseconds(SERVO_UP);
      } else {
        myServo.writeMicroseconds(SERVO_DOWN);
      }
  } // Switch
  commandType = 0;
  number = 0;
}  //  Void




















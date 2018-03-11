int dirPin = 8;
int stepperPin = 7;
void setup() {
pinMode(dirPin, OUTPUT);
pinMode(stepperPin, OUTPUT);
}
void step(boolean dir,int steps){
digitalWrite(dirPin,dir);
delay(50);
for(int i=0;i<steps;i++){
digitalWrite(stepperPin, HIGH);
delayMicroseconds(800);
digitalWrite(stepperPin, LOW);
delayMicroseconds(800);
}
}
void loop(){
step(true,1600);
delay(500);
step(false,1600);
delay(500);
}

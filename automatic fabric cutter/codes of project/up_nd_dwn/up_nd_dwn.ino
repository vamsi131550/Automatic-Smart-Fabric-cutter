void setup() {
  // put your setup code here, to run once:
 pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (8 , HIGH);
digitalWrite (9 , LOW);
 delay(290);


 digitalWrite (9 , HIGH);
digitalWrite (8 , LOW);
delay(290);
}

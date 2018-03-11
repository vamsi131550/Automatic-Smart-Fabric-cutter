
const int stepsPerRevolution = 200;
int i,j;


/*#define X_STEP_PIN         54
  #define X_DIR_PIN          55
  #define X_ENABLE_PIN       38
  #define X_MIN_PIN           3
  #define X_MAX_PIN           2*/

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19



void setup() {

  /*
    pinMode(X_STEP_PIN  , OUTPUT);
    pinMode(X_DIR_PIN    , OUTPUT);
    pinMode(X_ENABLE_PIN    , OUTPUT);*/

  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);

  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);



  // digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);














}

void loop () {


   digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(16, LOW);    // turn the LED off by making the voltage LOW



  if (millis() < 20000) {
    //digitalWrite(X_DIR_PIN    , HIGH);
     digitalWrite(Y_ENABLE_PIN    , LOW);
    digitalWrite(Z_ENABLE_PIN    , HIGH);

    
    digitalWrite(Y_DIR_PIN    , HIGH);
    digitalWrite(Z_DIR_PIN    , HIGH);

    

    Serial.println("clock1");
  }
  else if (millis() < 30000) {
    //digitalWrite(X_DIR_PIN    , LOW);


     digitalWrite(Y_ENABLE_PIN    , HIGH);
    digitalWrite(Z_ENABLE_PIN    , LOW);
    
    digitalWrite(Y_DIR_PIN    , HIGH );
    digitalWrite(Z_DIR_PIN    , LOW);
    Serial.println("clock2");
  }
  else if (millis()  < 50000) {
    //digitalWrite(X_DIR_PIN    , LOW);

     digitalWrite(Y_ENABLE_PIN    , LOW);
    digitalWrite(Z_ENABLE_PIN    , HIGH);
    
    digitalWrite(Y_DIR_PIN    , LOW);
    digitalWrite(Z_DIR_PIN    , LOW);
    Serial.println("clock3");
  }


  else if(millis() < 60000)
  {
    //digitalWrite(X_DIR_PIN    , LOW);

     digitalWrite(Y_ENABLE_PIN    , HIGH );
    digitalWrite(Z_ENABLE_PIN    , LOW);
    
    digitalWrite(Y_DIR_PIN    , LOW );
    digitalWrite(Z_DIR_PIN    , HIGH);
    Serial.println("clock4");
  }

 else if(millis() > 60000)
  {
    //digitalWrite(X_DIR_PIN    , LOW);

     digitalWrite(Y_ENABLE_PIN    , HIGH );
    digitalWrite(Z_ENABLE_PIN    ,HIGH );
    
    digitalWrite(Y_DIR_PIN    , LOW );
    digitalWrite(Z_DIR_PIN    , HIGH);
    Serial.println("clock4");
  }



  //digitalWrite(X_STEP_PIN    , HIGH);
  digitalWrite(Y_STEP_PIN    , HIGH);
  digitalWrite(Z_STEP_PIN    , HIGH);

  delay(1);

  //digitalWrite(X_STEP_PIN    , LOW);
  digitalWrite(Y_STEP_PIN    , LOW);
  digitalWrite(Z_STEP_PIN    , LOW);



}


int x;
int y;
int k;
const int X_ENABLE_PIN = 56;
const int  X_STEP_PIN  =  7;
 const int  X_DIR_PIN   = 8;

 const int  Y_ENABLE_PIN   = 62;
 const int  Y_STEP_PIN      =46;
const int  Y_DIR_PIN      =48;



void setup() {
 pinMode(17, OUTPUT);
    pinMode(23, OUTPUT);

 pinMode(X_ENABLE_PIN    , OUTPUT);
   pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
 
 pinMode(Y_ENABLE_PIN    , OUTPUT);
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(16 , OUTPUT);
  pinMode(16   , OUTPUT);
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
// Set Enable Low ? Enable at Low state











  
  }

  void loop () {
digitalWrite (X_STEP_PIN, HIGH); // Set Dir High ? set the direction of rotation


    
  for (x = 0; x < 1; x ++) // brackets in the run 200 times
  {
    digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
    delayMicroseconds (500); // 500ms waiting
    digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
    delayMicroseconds (500); // 500ms waiting


    

    

    
  }
  delay (100); // 1 seconds waits


 
 
  for (x = 0,y = 0; x < 1,y < 1; x ++,y++) // brackets in the run 200 times
  {


  
    digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
    delayMicroseconds (500); // 500ms waiting
    digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
    delayMicroseconds (500); // 500ms waiting

     digitalWrite (Y_STEP_PIN, HIGH); // 5 pin the to the High state
    delayMicroseconds (500); // 500ms waiting
    digitalWrite (Y_STEP_PIN, LOW); // 5 pin to Low state
    delayMicroseconds (500); // 500ms waiting

  

    
  }

  delay (1000); // 1 seconds waits


  
  for (x = 0; x < 1; x ++) // 200 times run in the brackets
  {
    digitalWrite (7, HIGH); // 5 pin to High state
    delayMicroseconds (500); // 500ms waiting
    digitalWrite (7, LOW); // 5 pin to Low state
    delayMicroseconds (500); // 500ms waiting
  }
  delay (1000); // wait 1 seconds 
  
  }
  
void penup()
{
  digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
                    // wait for a second
  digitalWrite(23, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);   
    
   digitalWrite(23, HIGH);   // turn the LED on (HIGH is the voltage level)
                    // wait for a second
  digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);      

  }


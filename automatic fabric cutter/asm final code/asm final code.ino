#include<keypad.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
   {'7','8','9','C'},
  {'*','0','#','D'},
  };
  byte rowpins[4] = {7, 6, 5, 4};
  byte colpins[4] = {3, 2, A4, A5};
  Keypad mykeypad = Keypad(makeKeymap(keys), rowpins, colpins, 4, 4);
int x;
int y;
int k;
const int X_ENABLE_PIN = 2;
const int  X_STEP_PIN  =  4;
 const int  X_DIR_PIN   = 3;

 const int  Y_ENABLE_PIN   = 5;
 const int  Y_STEP_PIN      =7;
const int  Y_DIR_PIN      =6;



void setup() {

  

 pinMode(X_ENABLE_PIN    , OUTPUT);
   pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
 
 pinMode(Y_ENABLE_PIN    , OUTPUT);
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
;
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
// Set Enable Low ? Enable at Low state

 pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
   lcd.begin(16,2);
}




  void loop () {
    char key = mykeypad.getKey();
 if(key == '1')
  {
    lcd.setCursor(0,0);
     lcd.print(key);
     digitalWrite (22 , HIGH);
     digitalWrite (23 , LOW);
     delay(90);
     digitalWrite (22 , LOW);
      digitalWrite (23 , LOW);
        digitalWrite (X_DIR_PIN, HIGH); // Set Dir High ? set the direction of rotation
   
        for (x = 0; x < 5000; x ++) // brackets in the run 200 times
        {
          digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
          delayMicroseconds (500); // 500ms waiting
          digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
          delayMicroseconds (500); // 500ms waiting
       }
        digitalWrite (Y_DIR_PIN, HIGH);
        
        for (y = 0; y < 5000; y ++) // brackets in the run 200 times
        {
          digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
          delayMicroseconds (500); // 500ms waiting
          digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
          delayMicroseconds (500); // 500ms waiting
       }

        digitalWrite (X_DIR_PIN, LOW); // Set Dir High ? set the direction of rotation
           
          for (x = 0; x < 5000; x ++) // brackets in the run 200 times
          {
            digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
            delayMicroseconds (500); // 500ms waiting
            digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
            delayMicroseconds (500); // 500ms waiting
         }
          digitalWrite (Y_DIR_PIN, LOW);
          
          for (y = 0; y < 5000; y ++) // brackets in the run 200 times
          {
            digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
            delayMicroseconds (500); // 500ms waiting
            digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
            delayMicroseconds (500); // 500ms waiting
         }
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , HIGH);
                   delay(90);
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , LOW);
   }


   if(key == '2')
     { lcd.setCursor(0,0);
       lcd.print(key);
        digitalWrite (22 , HIGH);
        digitalWrite (23 , LOW);
        delay(90);
        digitalWrite (22 , LOW);
        digitalWrite (23 , LOW);
        digitalWrite (X_DIR_PIN, HIGH); // Set Dir High ? set the direction of rotation
   
        for (x = 0; x < 5000; x ++) // brackets in the run 200 times
        {
          digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
          delayMicroseconds (500); // 500ms waiting
          digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
          delayMicroseconds (500); // 500ms waiting
       }
        digitalWrite (Y_DIR_PIN, HIGH);
        
        for (y = 0; y < 5000; y ++) // brackets in the run 200 times
        {
          digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
          delayMicroseconds (500); // 500ms waiting
          digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
          delayMicroseconds (500); // 500ms waiting
       }

        digitalWrite (X_DIR_PIN, LOW); // Set Dir High ? set the direction of rotation
           
          for (x = 0; x < 5000; x ++) // brackets in the run 200 times
          {
            digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
            delayMicroseconds (500); // 500ms waiting
            digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
            delayMicroseconds (500); // 500ms waiting
         }
          digitalWrite (Y_DIR_PIN, LOW);
          
          for (y = 0; y < 5000; y ++) // brackets in the run 200 times
          {
            digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
            delayMicroseconds (500); // 500ms waiting
            digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
            delayMicroseconds (500); // 500ms waiting
         }
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , HIGH);
                   delay(90);
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , LOW);
  }
           
   if(key == '3') 
      { 
       lcd.setCursor(0,0);
       lcd.print(key);
     digitalWrite (22 , HIGH);
     digitalWrite (23 , LOW);
     delay(90);
     digitalWrite (22 , LOW);
     digitalWrite (23 , LOW);
          digitalWrite (X_DIR_PIN, HIGH); // Set Dir High ? set the direction of rotation
   
        for (x = 0; x < 6000; x ++) // brackets in the run 200 times
        {
          digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
          delayMicroseconds (500); // 500ms waiting
          digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
          delayMicroseconds (500); // 500ms waiting
       }
         digitalWrite (X_DIR_PIN, LOW);
         digitalWrite (Y_DIR_PIN, HIGH);
       for (x = 0,y = 0; x < 3000,y < 3000; x ++,y++) // brackets in the run 200 times
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
        digitalWrite (X_DIR_PIN, LOW);
         digitalWrite (Y_DIR_PIN, LOW);
       for (x = 0,y = 0; x < 3000,y < 3000; x ++,y++) // brackets in the run 200 times
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
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , HIGH);
                   delay(90);
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , LOW);
 }
            
  if(key == '4')
    { lcd.setCursor(0,0);
      lcd.print(key);
     digitalWrite (22 , HIGH);
     digitalWrite (23 , LOW);
     delay(90);
     digitalWrite (22 , LOW);
     digitalWrite (23 , LOW);
              digitalWrite (X_DIR_PIN, HIGH);
              digitalWrite (Y_DIR_PIN, HIGH);
             for (x = 0,y = 0; x < 3000,y < 3000; x ++,y++) // brackets in the run 200 times
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
             digitalWrite (X_DIR_PIN, HIGH);
             digitalWrite (Y_DIR_PIN, LOW);
             for (x = 0,y = 0; x < 3000,y < 3000; x ++,y++) // brackets in the run 200 times
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
             digitalWrite (X_DIR_PIN, LOW);
             digitalWrite (Y_DIR_PIN, HIGH);
               for (x = 0,y = 0; x < 6000,y < 6000; x ++,y++) // brackets in the run 200 times
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
                   digitalWrite (X_DIR_PIN, HIGH); // Set Dir High ? set the direction of rotation
             
                  for (x = 0; x < 6000; x ++) // brackets in the run 200 times
                  {
                    digitalWrite (X_STEP_PIN, HIGH); // 5 pin the to the High state
                    delayMicroseconds (500); // 500ms waiting
                    digitalWrite (X_STEP_PIN, LOW); // 5 pin to Low state
                    delayMicroseconds (500); // 500ms waiting
                 }
                  digitalWrite (X_DIR_PIN, LOW);
                 digitalWrite (Y_DIR_PIN,LOW);
               for (x = 0,y = 0; x < 6000,y < 6000; x ++,y++) // brackets in the run 200 times
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
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , HIGH);
                   delay(90);
                   digitalWrite (22 , LOW);
                   digitalWrite (23 , LOW);
    }
            
            
    
  
  
/*void penup()
{
  //if the pen is raised
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
   // turn the LED on (HIGH is the voltage level)
                  delay (90);    // wait for a second
digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
   // turn the LED on (HIGH is the voltage level)
                       // wait for a second

  }*/         
            
            
            
            
            
            
            
            
            
            
            }
          

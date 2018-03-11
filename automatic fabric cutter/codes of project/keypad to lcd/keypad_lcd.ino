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
  
void setup() {

  lcd.begin(16,2);

}

void loop() {
  char key = mykeypad.getKey();
if(key!=NO_KEY)
{
  lcd.setCursor(0,0);
  lcd.print(key);
}
}


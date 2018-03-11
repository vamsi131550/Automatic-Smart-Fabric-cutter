void LCDmain() {

  if (positionLCD < 0) {
    positionLCD = 0;
  } else {
    if (positionLCD > 2) {
      positionLCD = 2;
    }
  }
  pulse = 0;


  
  while (digitalRead(S1_PIN) == LOW) {
    button = 1;
    delay(1);
    pulse++;
    if (pulse == 900) {
      choose();
    }
  }
  if (button == 1) {
    column = 0;
    button = 0;

    positionLCD--;

    if (menu != 0) {
      menuLCD();
    }
  }



  while (digitalRead(S2_PIN) == LOW) {
    button = 1;
    delay(1);
    pulse++;
    if (pulse == 900) {
      choose();
    }
  }
  if (button == 1) {
    column = 1;
    button = 0;

    positionLCD++;
    if (menu != 0) {
      menuLCD();
    }
  }

} // Void



void choose() { // Menu: 0 - Info, 1 - SD card,
  if (menu == 0) { // while in Info
    menuLCD();
    menu = 1;
  } else {
    if (menu == 1) { // while in Menu
      switch (positionLCD) {
        case 0:          // Place 1: Info
          infoScreen();
          break;
        case 1:          // Place 2: SD Card
          card();
          break;
        case 2:
          homing();
          break;
      } // Switch
    } // If
  } // Else
} // Void



void infoScreen() {
  menu = 0;
  positionLCD = 0;
  lcd.clear();
  lcd.print("Plotter");
  lcd.setCursor(0, 1);
  lcd.print("by Seweryn");
}

void homing() {
  lcd.clear();
  lcd.print("Homing");
  while (digitalRead(S1_PIN) == LOW || digitalRead(S2_PIN) == LOW) {
    ;
  }
  while (digitalRead(S1_PIN) == HIGH && digitalRead(S2_PIN) == HIGH) {
    targetXsteps = targetXsteps - X_STEPS_PER_MM;
    calculate();
  }
  positionXsteps = 0;
  
  while (digitalRead(S1_PIN) == LOW || digitalRead(S2_PIN) == LOW) {
    ;
  }
  
  while (digitalRead(S1_PIN) == HIGH && digitalRead(S2_PIN) == HIGH) {
    targetYsteps = targetYsteps - Y_STEPS_PER_MM;
    calculate();
  }
  positionYsteps = 0;
  infoScreen();
} // Void


void menuLCD() {
  if (column == 0) {
    lcd.clear();
    lcd.print(">               ");
    lcd.setCursor(1, 0);
    
    if (positionLCD <= 0) {
      lcd.print("Info");
      lcd.setCursor(1, 1);
      lcd.print("SD Card");
    }
    
    switch (positionLCD) {
      case 1:
        lcd.print("SD Card");
        lcd.setCursor(1, 1);
        lcd.print("Homing");
        break;
    } // Switch
  } else {
    
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(">               ");
    lcd.setCursor(1, 0);
    
    if (positionLCD >= 2) {
      lcd.print("SD Card");
      lcd.setCursor(1, 1);
      lcd.print("Homing");
    }
    
    switch (positionLCD) {
      case 1:
        lcd.print("Info");
        lcd.setCursor(1, 1);
        lcd.print("SD Card");
        break;
    } // Switch
  } // Else
} // Void

/*
Info
card
Homing

*/















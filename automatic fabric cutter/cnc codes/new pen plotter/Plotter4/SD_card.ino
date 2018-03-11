void card() {

lcd.clear();
lcd.print("Searching for SD");

if (!SD.begin(SD_PIN)) {
  lcd.setCursor(0, 1);
  lcd.print("SD not inserted");
  delay(2000);
  infoScreen();
  loop();
} else {
  lcd.clear();
  lcd.print("Drawing");
}

myFile = SD.open("gcode.ngc");


while (myFile.available()) {
    data[a] = myFile.read();
    a++;
    delay(2);
    if (data[a - 1] == '\n') {
      decode1();
      organize();
      calculate();
      for (a = 0; a < 61; a++) {
        data[a] = 0;
      }
      a = 0;
    }
  }

if (myFile.available() == 0) {
  myFile.close();
  lcd.clear();
  lcd.print("Drawing done!");
  delay(2000);
  infoScreen();
}

}

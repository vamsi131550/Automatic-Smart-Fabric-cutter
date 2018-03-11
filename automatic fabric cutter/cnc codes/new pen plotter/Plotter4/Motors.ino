void motors() { 
  
if (x != xj) {
  xj = x;
  if (xi == 1) {
    digitalWrite(motorX[CX1], LOW);  //   0 / 1 / 2 / 3
    digitalWrite(motorX[CX2], HIGH); //   1 / 2 / 3 / 0
    if (CX1 == 3) {
      CX1 = -1;
    }
    if (CX2 == 3) {
      CX2 = -1;
    }
    CX1++;
    CX2++;
  }
  
  
  if (xi == -1) {
    digitalWrite(motorX[CX2], LOW);  //   0 / 3 / 2 / 1
    digitalWrite(motorX[CX1], HIGH); //   3 / 2 / 1 / 0
    if (CX1 == 0) {
      CX1 = 4;
    }
    if (CX2 == 0) {
      CX2 = 4;
    }
    CX1--;
    CX2--;
  }
}
    
if (y != yj) {
  yj = y;
  if (yi == 1) {
    digitalWrite(motorY[CY1], LOW);  //   0 / 1 / 2 / 3
    digitalWrite(motorY[CY2], HIGH); //   1 / 2 / 3 / 0
    if (CY1 == 3) {
      CY1 = -1;
    }
    if (CY2 == 3) {
      CY2 = -1;
    }
    CY1++;
    CY2++;
  }
  
  if (yi == -1) {
    digitalWrite(motorY[CY2], LOW);  //   0 / 3 / 2 / 1
    digitalWrite(motorY[CY1], HIGH); //   3 / 2 / 1 / 0
    if (CY1 == 0) {
      CY1 = 4;
    }
    if (CY2 == 0) {
      CY2 = 4;
    }
    CY1--;
    CY2--;
  }
}
  delay(WAIT_TIME);

} // Void




















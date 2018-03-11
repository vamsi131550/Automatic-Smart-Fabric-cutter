void calculate() {
  if (positionXsteps < targetXsteps) { 
    xi = 1;
    remainedX = targetXsteps - positionXsteps;
  } else { 
    xi = -1;
    remainedX = positionXsteps - targetXsteps;
  }

  if (positionYsteps < targetYsteps) { 
    yi = 1;
    remainedY = targetYsteps - positionYsteps;
  } else { 
    yi = -1;
    remainedY = positionYsteps - targetYsteps;
  }
  
  if (remainedX > remainedY) {
    ai = (remainedY - remainedX) * 2;
    bi = remainedY * 2;
    d = bi - remainedX;
         
    while (x != targetXsteps) { 
      if (d >= 0) { 
        x += xi;
        y += yi;
        d += ai;
      } else {
        d += bi;
        x += xi;
      }
      motors();
    }
  } else { 
    ai = ( remainedX - remainedY ) * 2;
    bi = remainedX * 2;
    d = bi - remainedY;
    while (y != targetYsteps) {
      if (d >= 0) { 
        x += xi;
        y += yi;
        d += ai;
      } else {
        d += bi;
        y += yi;
      }
      motors();
    }
  }
  positionXsteps = targetXsteps;
  positionYsteps = targetYsteps;
}

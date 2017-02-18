/**
 * increments the left forward encoder counter
 * 
 */
void incrementLeftForward (){
  counter [left_forward] += 1;
}

/**
 * increments the right forward encoder counter
 * 
 */
void incrementRightForward (){
  counter [right_forward] += 1;
}

/**
 * increments the left reverse encoder counter
 * 
 */
void incrementLeftReverse (){
  counter [left_reverse] += 1;
}

/**
 * increments the right reverse encoder counter
 * 
 */
void incrementRightReverse(){
  counter [right_reverse] += 1;
}

/**
 * calculates the rpm that the wheel is moving at
 * 
 * @param encoderPin pins rpm is calculated
 * @return the rpm of the wheel
 */
double getRPM (int encoderPin){
  double totalTime = (millis () - startTime [encoderPin])/1000.0;
  double tps = counter[encoderPin]/totalTime; // ticks per second
  return tps;
}



/**
 * Used to setup all pins
 */
void setupPins (){
  //motor pins
  for (int i=0; i<4; i++){
    pinMode (motor[i], OUTPUT);
    pinMode (encoder[i], INPUT);
  }

  //distance sensor pins
  for (int i=0; i<6; i++){
    pinMode(emitter[i], OUTPUT);
    pinMode(receiver[i], INPUT);
  }

  //gyro pin
  pinMode(gyro, INPUT);
}

/**
 * sets up the interrupts for the encoders
 */
void setupEncoderInterrupts (){
  attachInterrupt (digitalPinToInterrupt(left_forward), incrementLeftForward, CHANGE);
  attachInterrupt (digitalPinToInterrupt(left_reverse), incrementLeftReverse, CHANGE);
  attachInterrupt (digitalPinToInterrupt(right_forward), incrementRightForward, CHANGE);
  attachInterrupt (digitalPinToInterrupt(right_reverse), incrementRightReverse, CHANGE);
}

/**
 * sets up the variables needed for rpm
 */
void setupTPS (){
  for (int i=0; i<4; i++){
    startTime [i] = millis ();
    TPS [i] = 0.0;
  }
}

/**
 * sets up the PID motion
 */
void setupPID (){
  
}

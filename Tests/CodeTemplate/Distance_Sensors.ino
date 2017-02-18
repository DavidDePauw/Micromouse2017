/**
 * calculates an average analog read for distance sensor pins
 * 
 * @param pin the pin that is used to calculate average read
 * @return average analog read
 */
double getDistanceAverageRead (int pin, int count){
  int sum = 0;
  for (int i=0; i<count; i++) sum+=getDistanceSensorRead(pin);
  return sum/count;
}


/*
 * calculates a single sensor read
 * 
 * @param pin the pin that is used to output single analog read
 * @return single  analog read
 */
double getDistanceSensorRead (int pin){
  digitalWrite(emitter[pin], HIGH);
  double val = analogRead(receiver[pin]);
  digitalWrite(emitter[pin], LOW);
  return val;
}


/**
 * checks whether there is a wall on the left
 * 
 * @return true if there is wall on the left
 */
boolean leftWall () {
  return getDistanceAverageRead(left, 10) >= 160;
}

/**
 * checks whether there is a wall on the right
 * 
 * 
 * @return true if there is a wall on the right
 */
boolean rightWall (){ 
 return getDistanceAverageRead(right, 10) >= 138;
}


/**
 * checks whether there is a wall on the front
 * 
 * @return true if there is a wall on the front
 */
boolean frontWall (){
  double distanceToWall = MAZE_SIZE-BOT_SIZE/2;
  return (leftForwardDistance()<=distanceToWall && rightForwardDistance()<=distanceToWall);
}

/**
 * calculates the right forward sensor distance
 * the values of a, b, c are calculated using matlab program 
 * {@code x} is the voltage value from the analogRead of the sensor
 * the distance from the front of the bot to the obstacle is calculated
 * 
 * @return the distance to the nearest obstacle from the front of the bot
 */
double rightForwardDistance (){
  double a = 5.964;
  double b = -1.348;
  double c = 0.9782;
  double x = analogToVoltage(getDistanceAverageRead(right_forward, 10));
 
  //d = a*x^b+c
  double distance = a*pow(x, b)+c;
  return distance;
}

/**
 * calculates the left forward sensor distance
 * the values a, b, c are calculated using matlab program
 * {@code x} is the voltage value from the analogRead of the sensor
 * the distance from the front of the bot to the obstacle is calculated
 * 
 * @return the distance to nearest obstacle from the front of the bot
 */
double leftForwardDistance (){
  double a = 64.07;
  double b = -2.893;
  double c = 1.844;
  double x = analogToVoltage(getDistanceAverageRead(left_forward, 10));

  //d = a*x^b+c;
  double distance = a*pow(x, b)+c;
  return distance;
}

/**
 * calculates the left diagonal sensor distance
 * the values a, b, c are calculated using matlab program
 * {@code x} is the voltage value from the analogRead of the sensor
 * the distance from the curved part that intersects the line of sight from sensor 
 * of the bot to the obstacle is calculated
 * 
 * very bad centering capability
 * 
 * @return the distance to nearest obstacle from the front (45 deg curved section) of the bot
 */
double leftDiagonalDistance (){
  double a = 16.74;
  double b = -0.3706;
  double c = -5.667;
  double x = analogToVoltage(getDistanceAverageRead(left_diag, 100));

  //d = a*x^b+c
  double distance = a*pow(x, b)+c;
  return distance;
}

/**
 * calculates the right diagonal sensor distance
 * the values a, b, c are calculated using matlab program
 * {@code x} is the voltage value from the analogRead of the sensor
 * the distance from the curved part that intersects the line of sight from sensor 
 * of the bot to the obstacle is calculated
 * 
 * normal value 10.5 +/- 0.1
 * reason why it is above the actual distance is because the 
 * linearizing process was done when it was straight
 * 
 * @return the distance to nearest obstacle from the front (45 deg curved section) of the bot
 */
double rightDiagonalDistance (){
  double a = 12.35;
  double b = -0.9895;
  double c = 1.973;
  double x = analogToVoltage(getDistanceAverageRead(right_diag, 10));

  //d = a*x^b+c
  double distance = a*pow(x, b)+c;
  return distance;
}




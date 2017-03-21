/**
 * moves the left motor in the forward direction
 * 
 * @param pin value [0, 3]
 * @param analogValue value specification for pwm [0, 255]
 */
void move (int pin, int analogValue){
  analogWrite (motor[pin], analogValue);
}


void stop (int pin){
  analogWrite (motor[pin], 0);
}


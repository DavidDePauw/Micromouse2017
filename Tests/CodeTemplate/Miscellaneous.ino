/**
 * takes analog value and converts to voltage value
 * 
 * @param analogValue value from analogRead [0, 1023]
 * @return voltage value in double [0.0, 5.0]
 */
double analogToVoltage (double analogValue) {
  return analogValue/1023.0*5.0;
}

/**
 * takes voltage and converts to analog value for pwm
 * 
 * @param voltage value of voltage [0, 5.0]
 * @return analog value between [0, 255]
 */
int voltageToAnalog (double voltage){
  return (int)(voltage/5.0*255);
}

/**
 * takes voltage and converts to analog value for pwm
 * 
 * @param voltageScale value of highest voltage 
 * @param voltage value of voltage [0, voltageScale]
 * @return analog value between [0, 255]
 */
int voltageToAnalog (double voltageScale, double voltage){
  return (int)(voltage/voltageScale*255);
}



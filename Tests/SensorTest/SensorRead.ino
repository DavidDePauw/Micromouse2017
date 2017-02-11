/*
 * working pins from test
 * 
 * 
 * left and right front
 * 
 * left diagonal
 */




void leftFrontSensorTest () {
  digitalWrite (lf_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(lf_receiver);
  digitalWrite(lf_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
  
}

void rightFrontSensorTest () {
  digitalWrite (rf_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(rf_receiver);
  digitalWrite(rf_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
}

void leftSensorTest () {
  digitalWrite (l_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(l_receiver);
  digitalWrite(l_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
}

void rightSensorTest () {
  digitalWrite (r_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(r_receiver);
  digitalWrite(r_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
}

void leftDiagSensorTest () {
  digitalWrite (ld_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(ld_receiver);
  digitalWrite(ld_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
}

void rightDiagSensorTest (){
  digitalWrite (rd_emitter, HIGH);
  double sum = 0;
  for (int i=0; i<10; i++) sum = sum+analogRead(rd_receiver);
  digitalWrite(rd_emitter, LOW);
  
  double average = sum/10;
  double voltage = average * (5.0/1023.0);
  Serial.println (voltage);
}


//sensor pins
// lf - left front
// l - left
// ld - left diagonal
/*
 * @author Akshay Ben
 * 
 * 
 * This is the sensor testing code
 * Used for linearizing sensor data
 * Used for knowing which sensors are broken
 * 
 * 
 */

const int lf_emitter = 0;
const int lf_receiver = 21;

const int rf_emitter = 7;
const int rf_receiver = 20;

const int l_emitter = 1;
const int l_receiver = 23;

const int r_emitter = 8;
const int r_receiver = 22;

const int ld_emitter = 2;
const int ld_receiver = 19;

const int rd_emitter = 11;
const int rd_receiver = 18;

void setup() {
  setupSensors();
  Serial.begin(9600);

}


void setupSensors () {
  pinMode (lf_emitter, OUTPUT);
  pinMode (rf_emitter, OUTPUT);
  pinMode (l_emitter, OUTPUT);
  pinMode (r_emitter, OUTPUT);
  pinMode (ld_emitter, OUTPUT);
  pinMode (rd_emitter, OUTPUT);

  pinMode (lf_receiver, INPUT);
  pinMode (rf_receiver, INPUT);
  pinMode (l_receiver, INPUT);
  pinMode (r_receiver, INPUT);
  pinMode (ld_receiver, INPUT);
  pinMode (rd_receiver, INPUT);
  
}

void loop() {
  Serial.print ("Left Front Sensor: ");
  leftFrontSensorTest ();
  Serial.print ("Right Front Sensor: ");
  rightFrontSensorTest ();
  Serial.print ("Left Sensor: ");
  leftSensorTest ();
  Serial.print ("Reight Sensor: ");
  rightSensorTest ();
  Serial.print("Left Diagonal Sensor: ");
  leftDiagSensorTest();
  Serial.print ("Right Diag Sensor: ");
  rightDiagSensorTest ();

  Serial.println();

  delay (1000);

}

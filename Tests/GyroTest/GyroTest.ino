/*
 * 
 * 
 * @author
 * 
 * 
 * Gyroscope testing sketch
 * reads from gyro
 */

const int gyro_pin = A14;

void setup() {
  // put your setup code here, to run once:
  pinMode (gyro_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead (gyro_pin);
  Serial.println(value);
  
}

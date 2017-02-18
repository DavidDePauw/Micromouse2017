/*
 * @author Akshay Ben
 * 
 * 
 * Motor control Test
 * The program just tests out the basics of the motor control
 * Setting pwm values
 * 
 * RIN - reverse in 
 * FIN - forward in
 * 
 */


double p = .1;
const double setPoint = 5;
double lSpeed = 0;
double rMotorAssign;
double lMotorAssign;
double rSpeed = 0;


const int left_rin = 5;
const int left_fin = 6;
const int right_rin = 9;
const int right_fin = 10;


const int outputValue = 10;

const int EncLeft_r = A2;
const int EncRight_r = 12;
const int EncLeft_f = A1;
const int EncRight_f =  A0;

int lCounter = 0;
long lStartTime; 
int rCounter = 0;
long rStartTime;

void setup() {
  // put your setup code here, to run once
  setupPins();
}

void setupPins () {
  pinMode (left_rin, OUTPUT);
  pinMode (left_fin, OUTPUT);
  pinMode (right_rin, OUTPUT);
  pinMode (left_fin, OUTPUT);  
  pinMode (EncLeft_r, INPUT);
  pinMode (EncRight_r, INPUT);
  pinMode (EncLeft_f, INPUT);
  pinMode (EncRight_f, INPUT);
  lStartTime = millis ();
  rStartTime = millis ();
  attachInterrupt (digitalPinToInterrupt(EncLeft_f), lIncrement, CHANGE);
  attachInterrupt (digitalPinToInterrupt(EncRight_r), rIncrement, CHANGE);
  //analogWrite (left_fin, 10);
  //analogWrite (right_rin, 10);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if (lCounter>=128){
    long totalTime = millis () - lStartTime;
    double lSpeed = lCounter/(totalTime/1000.0);
    Serial.println(lSpeed);
    lCounter = 0;
    lStartTime = millis ();
    
  }
if (rCounter>=128){
    long totalTime = millis () - rStartTime;
    double rSpeed = rCounter/(totalTime/1000.0);
    Serial.println(rSpeed);
    rCounter = 0;
    rStartTime = millis ();
    
  }


  
  double lError = setPoint - lSpeed;
  //Serial.println(lSpeed);
  lMotorAssign += lError * p;
  double rError = setPoint - rSpeed;
  rMotorAssign += rError * p;

  if(lMotorAssign > 50) lMotorAssign = 50;
  if (rMotorAssign > 50) rMotorAssign = 50;  
  //analogWrite(left_fin, lMotorAssign);
  //analogWrite(right_rin, rMotorAssign);

  
  delay (5000);
  
  

}

void  rIncrement (){
  rCounter += 1;
}
void  lIncrement () {
  lCounter += 1;
  Serial.println("hi");
}



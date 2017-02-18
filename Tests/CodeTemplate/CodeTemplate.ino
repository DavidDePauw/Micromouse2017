//array indices
const int left_forward = 0;
const int left_reverse = 1;
const int left = 1;
const int right_forward = 2;
const int right_reverse = 3;
const int right = 3;
const int left_diag = 4;
const int right_diag = 5;

//motor control pins
const int motor [] = {6, 5, 9, 10};


//encoder control pins
const int encoder [] = {15, 16, 14, 12};

//sensor emitter pins
const int emitter [] = {7, 8, 11, 1, 2, 0};

//sensor receiver pins
const int receiver [] = {A6, A5, A7, A4, A9, A8};


//gyro pins
const int gyro = A14;

//battery voltage supply


//encoder counters
int counter [] = {0, 0, 0, 0};

//encoder timers
long startTime [4];

//wheel TPS : ticks per second
double TPS [4];

//PID constants for constant velocity motion


//PID constants for tilt error


//PID constants for center stray error

//maze and bot size in cm
const double BOT_SIZE = 9.6;
const double MAZE_SIZE = 16.7;



void setup() {
  // put your setup code here, to run once:
  setupPins ();
  setupEncoderInterrupts();
  setupTPS();
  setupPID();
  Serial.begin(9600);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  
}






#include "Arduino.h"
#include "PIDLoop.h"



PIDLoop::PIDLoop(double p, double i, double d, double setpoint){
	_p = p;
	_i = i;
	_d = d;
	_setpoint = setpoint;
	_input = 0;
	_error = 0;
	_previousError = 0;
	_output = 0;
	for(int x = 0; x < 10; x++){
		_iArray[x] = 0;
	}
}
void PIDLoop::setSetpoint(double setpoint){
	_setpoint = setpoint;
}
void PIDLoop::setP(double p){
	_p = p;
}
void PIDLoop::setI(double i){
	_i = i;
}
void PIDLoop::setD(double d){
	_d = d;
}
double PIDLoop::runLoop(double input){
	//pid loop
	//calculate error
	_output = 0;
	_previousError= _error;
	_error = _setpoint - input;

	addIValue(_error);

	//calculate p
	_output += _error * _p;

	//calculate i
	_output += getIAverage() * _i;
	//other option
	//_output +=

	//calculate d
	_output += ((_error - _previousError) * _d);

	return _output;
}
void PIDLoop::addIValue(double error){
	for(int x = 0; x < 9; x++){
   		_iArray[x + 1] = _iArray[x];
 	}
	_iArray[0] = error;
}
double PIDLoop::getIAverage(){
	double sum = 0;
	for(int x = 0; x < 10; x++){
		sum += _iArray[x];
	}
	return sum/10;
}
double PIDLoop::getISum(){
	double sum = 0;
	for(int x = 0; x < 10; x++){
		sum += _iArray[x];
	}
	return sum;
}




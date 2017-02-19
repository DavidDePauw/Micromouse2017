#ifndef PIDLoop_h
#define PIDLoop_h

#include "Arduino.h"


class PIDLoop
{
	public:
		PIDLoop(double p, double i, double d, double setpoint);
		void setSetpoint(double setpoint);
		void setP(double p);
		void setI(double i);
		void setD(double d);
		double runLoop(double input);

		double _p;
		double _i;
		double _d;
		double _setpoint;
		double _input;
		double _error;
		double _previousError;
		double _output;
		double _iArray[10];
	private:
		void addIValue(double error);
		double getIAverage();
		double getISum();
		
		
		
};

#endif
#ifndef AutonVisionTurning_H
#define AutonVisionTurning_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Nullable.h"
#include "../Robot.h"

class AutonVisionTurning: public CommandBase
{
public:
	AutonVisionTurning();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Nullable<double> target;
	static const int TARGET = 122;
	static const int UPPER_LIMIT = TARGET + 10;
	static const int LOWER_LIMIT = TARGET - 10;
	bool onTarget = false;
};

#endif

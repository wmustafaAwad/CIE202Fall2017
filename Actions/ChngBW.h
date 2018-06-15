#ifndef CHNG_BW_ACTION_H
#define CHNG_BW_ACTION_H

#include "Action.h"

using namespace std;

//Change border width Action class
class ChngBW: public Action
{
private:
	int newBW;

public:
	ChngBW(ApplicationManager *pApp);

	//Reads new border width specified by user
	virtual void ReadActionParameters();

	//Change the border width color
	virtual void Execute() ;
	
};

#endif




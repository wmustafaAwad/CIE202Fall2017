#ifndef CHNG_FILL_CLR_ACTION_H
#define CHNG_FILL_CLR_ACTION_H

#include "Action.h"

using namespace std;

//Change filling color Action class
class ChngFillClr: public Action
{
private:
	Point P1; //point to decide specefic color in the pallete

public:
	ChngFillClr(ApplicationManager *pApp);

	//Reads new color specified by user
	virtual void ReadActionParameters();

	//Change the filling color
	virtual void Execute() ;
	
};

#endif




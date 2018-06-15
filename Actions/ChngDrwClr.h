#ifndef CHNG_DRW_CLR_ACTION_H
#define CHNG_DRW_CLR_ACTION_H

#include "Action.h"

using namespace std;

//Change drawing color Action class
class ChngDrwClr: public Action
{
private:
	Point P1; //point to decide specefic color in th pallete

public:
	ChngDrwClr(ApplicationManager *pApp);

	//Reads new color specified by user
	virtual void ReadActionParameters();

	//Change the drawing color
	virtual void Execute() ;
	
};

#endif




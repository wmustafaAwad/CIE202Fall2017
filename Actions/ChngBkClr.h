#ifndef CHNG_BK_CLR_ACTION_H
#define CHNG_BK_CLR_ACTION_H

#include "Action.h"

using namespace std;

//Change background color Action class
class ChngBkClr: public Action
{
private:
	Point P1; //point to decide specefic color in the pallete

public:
	ChngBkClr(ApplicationManager *pApp);

	//Reads new color specified by user
	virtual void ReadActionParameters();

	//Change the background color
	virtual void Execute() ;
	
};

#endif




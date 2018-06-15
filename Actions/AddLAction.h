#ifndef ADD_L_ACTION_H
#define ADD_L_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddLAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo LineGfxInfo;
public:
	AddLAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif

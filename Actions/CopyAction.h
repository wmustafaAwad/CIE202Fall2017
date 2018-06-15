#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class CopyAction : public Action
{
private:
	Point P1;
	static CFigure* CopiedFig;
public:

	CopyAction(ApplicationManager *pApp);
	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
	virtual void Execute(Point);
	static void setfig(CFigure*);
	static CFigure* getfig();

};

#endif
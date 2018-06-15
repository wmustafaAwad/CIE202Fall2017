#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class MoveAction : public Action
{
private:
	Point P1;
	Point P2;
public:

	MoveAction(ApplicationManager *pApp);
	//Reads parameters
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif


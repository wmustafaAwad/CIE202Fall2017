#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class DeleteAction : public Action
{
private:
	Point P1;
public:
	DeleteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Execute(Point);
};

#endif



#ifndef Paste_ACTION_H
#define Paste_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
class PasteAction : public Action
{
private:
	Point P1;
public:
	PasteAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Execute(Point);
};

#endif
#ifndef DRAWING_ACTION_H
#define DRAWING_ACTION_H
#include "Action.h"
#include"..\Figures\CFigure.h"



class DrawingAreaAction : public Action
{
private:
	Point Pnew; //New point clicked
	CFigure** MyFigList;
	int Count;

public:
	DrawingAreaAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif

#ifndef DRAWING_ACTION_H
#define DRAWING_ACTION_H
#include "Action.h"
#include "CFigure.h"


class DrawingAreaAction: public Action
{
private:
	Point Pnew; //New point clicked
public:
	DrawingAreaAction(ApplicationManager *pApp);
	void check();
	//virtual void SetSel();	
	//virtual int FigSel();
	//virtual void PrintInfo(Output* pOut)const;

};

#endif

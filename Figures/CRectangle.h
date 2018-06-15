#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool SetSel(Point Pnew);
	int maximum(int x1, int x2);
	int minimum(int x1, int x2);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	//-- Load and Save
	virtual void Save(ofstream &OutFile); //Waleed
	virtual CFigure* Load(ifstream &Infile, string line); //Waleed
	CFigure* CreateFromPointer(Point P);//creates a new rectangle whose geometric center is the passed point
};

#endif
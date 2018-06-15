#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;	
	int RADIUS;
public:
	CCircle(Point , int, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool SetSel(Point Pnew);
	int getRadius()const;
	double getArea()const; 
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	//-- Load and Save
	virtual void Save(ofstream &OutFile); //Waleed
	virtual CFigure* Load(ifstream &Infile, string line);	//Waleed //Load the figure parameters to the file
	CFigure* CreateFromPointer(Point P);//creates a new circle whose center is the passed point
	//used in pasting
};

#endif
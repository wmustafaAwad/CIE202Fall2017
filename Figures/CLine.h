#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point point1;	
	Point point2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool SetSel(Point Pnew);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	//-- Load and Save
	virtual void Save(ofstream &OutFile); //Waleed
	virtual CFigure* Load(ifstream &Infile, string line); //Waleed

};

#endif
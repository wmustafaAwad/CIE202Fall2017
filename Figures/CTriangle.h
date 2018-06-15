#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1;	
	Point Vertex2;
	Point Vertex3;
public:
	CTriangle(Point , Point,Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool SetSel(Point Pnew);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
	CFigure* CreateFromPointer(Point P);//Creates a new triangle whose geometric centre is the passed point
	//-- Load and Save
	virtual void Save(ofstream &OutFile); //Waleed
	virtual CFigure* Load(ifstream &Infile, string line); //Waleed
	
};

#endif
#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual CFigure* CreateFromPointer(Point);//creates a new figure from a figure pointer
    //to be overridden
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool SetSel(Point Pnew) = 0; //Aya //Checks if a figure is selected
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool Selected;	//true if the figure is selected.
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual CFigure* Load(ifstream &Infile, string line) = 0;	//Load the figure parameters from the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	void CFigure::SetID(int IDn); //Waleed
	int CFigure::GetID(); //Waleed
};

#endif
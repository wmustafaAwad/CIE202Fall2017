#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	Point LastClicked;
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool ChangeBit; //"Dirty Bit", set to 1 when a change occurs after last save. //Waleed

public:	
	ApplicationManager(); 
	~ApplicationManager();
	Point GetLastClicked();
	void DeselectAll();
	void ChngMDrwClr(color MDrwClr); //function to change next drawing color or drwing color for selected figures(one or multiple) if there are any
	void ChngMFillClr(color MFillClr); //function to change next filling color or filling color for selected figures(one or multiple) if there are any
	void ChngMBW(int MBW); // function to change next borderwidth or borderwidth for selected figures (one or multiple) if there are any

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction();
	void ExecuteAction(ActionType) ; //Creates an action and executes it


	//-- Save and Load Functions
	void SaveAll(ofstream &OutFile); //Waleed // Saves all figures by calling
	void LoadAll(ifstream &InFile); //Waleed // Loads all figures by calling
	void SetChangeBit(bool Value); //Waleed //Setter for ChangeBit.
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigures();//Deletes all selected figures
	void DeleteFigure(int x, int y);//Deletes the figure at the passed point
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	int GetFigureIndex(int x, int y) const;//Gets the index of the figure at the passed point in the figurelist
};

#endif
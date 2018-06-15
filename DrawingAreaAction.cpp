#include "Action.h"
#include "CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


void DrawingAreaAction :: check() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pIn->GetPointClicked(Pnew.x, Pnew.y);
    SetSel(Pnew);
	int check= FigSel();
	if (check != -1) { 
		PrintInfo(Output* pOut);
}

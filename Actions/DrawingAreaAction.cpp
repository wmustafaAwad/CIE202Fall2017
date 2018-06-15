#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "DrawingAreaAction.h" 



DrawingAreaAction::DrawingAreaAction(ApplicationManager * pApp) :Action(pApp)
{}

void DrawingAreaAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();
	//pIn->GetPointClicked(Pnew.x, Pnew.y);
	//MyFigList = pManager->GetFigList();
	//Count = pManager->GetFigCount();

}
void DrawingAreaAction::Execute() {
	Output* pO = pManager->GetOutput();
	//ReadActionParameters();
	CFigure* Selected_FIG;
	Pnew = pManager->GetLastClicked();
	Selected_FIG = pManager->GetFigure(Pnew.x, Pnew.y);
	if (Selected_FIG != NULL) {
		Selected_FIG->PrintInfo(pO);
	}
	else {
		pManager->DeselectAll();
		pO->ClearStatusBar();
	}

}
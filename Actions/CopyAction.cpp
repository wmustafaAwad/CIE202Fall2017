#include "CopyAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp)
{}

CFigure* CopyAction::CopiedFig = NULL;
void CopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on the figure you want to copy");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}

//Execute the action
void CopyAction::Execute()
{
	//this action needs to read the parameters first
	ReadActionParameters();
	CopiedFig = pManager->GetFigure(P1.x, P1.y);
}//Assigns the figure at the clicked point to CopiedFig
void CopyAction::Execute(Point P)
{
	//This action doesn't to read parameters...to be used in DeleteAction
	CopiedFig = pManager->GetFigure(P.x, P.y);
}//Assigns the figure at the passed point to CopiedFig

void CopyAction::setfig(CFigure* p) {
	CopiedFig = p;
}//a setter for CopiedFig
CFigure* CopyAction::getfig() {
	return CopiedFig;
}//a getter for CopiedFig

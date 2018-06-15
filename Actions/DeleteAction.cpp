#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	//This function has no benefit, it is just to override the ReadActionParameters virtual function to enable instantiation
};

//Execute the action
void DeleteAction::Execute()
{
	//the action doesn't need to read parameters
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigures();//DeleteFigures is called to delete all selected figures
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}
void DeleteAction::Execute(Point P)
{
	//the action doesn't need to read parameters
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(P.x, P.y);//DeleteFigure is called to delete the figure at the passed point
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}

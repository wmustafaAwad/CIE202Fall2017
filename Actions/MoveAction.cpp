#include "MoveAction.h"
#include"CopyAction.h"
#include"DeleteAction.h"
#include"PasteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager * pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on the figure you want to move");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}

//Execute the action
void MoveAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Pointers to Copy/Delete/Paste Actions
	CopyAction* pCopy = new CopyAction(pManager);
	DeleteAction* pDelete = new DeleteAction(pManager);
	PasteAction* pPaste = new PasteAction(pManager);
	pCopy->Execute(P1);//Copies the figure at the clicked point
	pOut->PrintMessage("Click on the point where you want to move");
	pIn->GetPointClicked(P2.x, P2.y);//wait till the user clicks at the other point
	pOut->ClearStatusBar();
	pPaste->Execute(P2);//Pastes the figure at the new point
	pDelete->Execute(P1);//deletes the figure at the first point
}

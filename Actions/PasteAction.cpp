#include "PasteAction.h"
#include "..\Actions\CopyAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<thread>

PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)
{}

void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on the point where you want to paste");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* R = CopyAction::getfig();//The getter is called to get the CopiedFig
	if (R != NULL) {
		if ((R->CreateFromPointer(P1)) != NULL) {
			pManager->AddFigure(R->CreateFromPointer(P1));//Calls Create from pointer to create a figure with the appropriate parameters
			//from the Copied Pointer
		//The getter is called to get the CopiedFig
		}
		else {
			pOut->PrintMessage("Invalid Paste Position");
			std::this_thread::sleep_for(1s);
			Execute();
		}
	}
}
void PasteAction::Execute(Point P)
{
	//This action doesn't need to read parameters
	//to be used in MoveAction
	CFigure* R = CopyAction::getfig();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P1;
	if (R != NULL) {
		if ((R->CreateFromPointer(P)) != NULL) {
			pManager->AddFigure(R->CreateFromPointer(P));//Calls Create from pointer to create a figure with the appropriate parameters
			//from the Copied Pointer//The getter is called to get the CopiedFig
			CopyAction::setfig(NULL);
		}
		else {
			pOut->PrintMessage("Invalid Moving Position");
			std::this_thread::sleep_for(1s);
			pOut->PrintMessage("Click at the point where you want to move");
			pIn->GetPointClicked(P1.x, P1.y);
			Execute(P1);
			pOut->ClearStatusBar();
		}
	}

}
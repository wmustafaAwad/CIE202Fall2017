#include "AddLAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <thread>

AddLAction::AddLAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	//If the line is inside the drawing area..Draw a new line
	if (P1.y > 80 && P1.y < 650 && P2.y>80 && P2.y < 650) {
		CLine *R = new CLine(P1, P2, LineGfxInfo);
		//Add the Line to the list of figures
		pManager->AddFigure(R);
	}
	else {
		pOut->PrintMessage("You cannot Draw here");
		std::this_thread::sleep_for(1s);
		Execute();
	}
}
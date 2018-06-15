#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<thread>

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first vertex");
	
	//Read 1st vertex and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second vertex");

	//Read 2nd vertex and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);


	pOut->PrintMessage("New Triangle: Click at third vertex");

	//Read 3nd vertex and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	//checks if the figure is in the drawing area
	if (P1.y > 80 && P1.y < 650 && P2.y>80 && P2.y < 650 && P3.y>80 && P3.y < 650) {
		//Create a triangle with the parameters read from the user
		CTriangle *R = new CTriangle(P1, P2, P3, TriGfxInfo);
		//Add the triangle to the list of figures
		pManager->AddFigure(R);
	}
	else {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("You cannot draw here");
		std::this_thread::sleep_for(1s);
		Execute();
	}
}
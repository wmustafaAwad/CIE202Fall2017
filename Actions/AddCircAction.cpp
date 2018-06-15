#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<cmath>
#include<thread>
#include<iostream>
using namespace std;

AddCircAction::AddCircAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Centre Point");
	
	//Read 1st vertex and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	
		pOut->PrintMessage("New Circle: Click at the Second Point");
		pIn->GetPointClicked(P2.x, P2.y);
		//checks if the points are in the drawing area
	if (P2.y > 80 && P2.y < 650 && P1.y > 80 && P1.y<650) {
		CircGfxInfo.isFilled = true;	//default is not filled
		//get drawing, filling colors and pen width from the interface
		CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
		CircGfxInfo.FillClr = pOut->getCrntFillColor();
		CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("You cannot draw here");
		std::this_thread::sleep_for(1s);
		ReadActionParameters();
	}
}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	int Radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	//checks if the figure is in the drawing area
	if (P1.x - Radius > 0 && P1.x + Radius<1300 && P1.y-Radius>80 &&P1.y+Radius<650) {
			CCircle *R = new CCircle(P1, Radius, CircGfxInfo);
			pManager->AddFigure(R);
		}
	else {
		pOut->PrintMessage("You cannot draw here");
		std::this_thread::sleep_for(1s);
		Execute();
	}
}
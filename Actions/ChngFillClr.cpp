#include "ChngFillClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngFillClr::ChngFillClr(ApplicationManager * pApp):Action(pApp)
{}

void ChngFillClr::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	pOut->PrintMessage("Click at your prefered color");
	pOut->CreateColorPallete();
	color MulFillClr=pIn->GetColor();
	pManager->ChngMFillClr(MulFillClr); //call function that change filling color for next figures or for current selected figures if there are any
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	}

//Execute the action
void ChngFillClr::Execute() 
{
		ReadActionParameters();
}
		
		
#include "ChngDrwClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//Change drawing color Action class
ChngDrwClr::ChngDrwClr(ApplicationManager * pApp):Action(pApp)
{}

void ChngDrwClr::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	pOut->PrintMessage("Click at your prefered color");
	pOut->CreateColorPallete();
	color MulDrwClr=pIn->GetColor(); 
	pManager->ChngMDrwClr(MulDrwClr); //call function that change drawing color for next figures or for current selected figures if there are any
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	}

//Execute the action
void ChngDrwClr::Execute() 
{
		ReadActionParameters();	
}



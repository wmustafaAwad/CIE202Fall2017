#include "ChngBkClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//Action class responsiple for changing the background color
ChngBkClr::ChngBkClr(ApplicationManager * pApp):Action(pApp)
{}

void ChngBkClr::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	pOut->PrintMessage("Click at your prefered color");
	pOut->CreateColorPallete(); //function call to create the color pallete which user chooses color from
	UI.BkGrndColor=pIn->GetColor();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	}

//Execute the action
void ChngBkClr::Execute() 
{
		ReadActionParameters();
}
		
		
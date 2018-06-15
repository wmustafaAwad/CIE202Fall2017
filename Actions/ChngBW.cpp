#include "ChngBW.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

//Change border width Action class
ChngBW::ChngBW(ApplicationManager * pApp):Action(pApp)
{}

void ChngBW::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	pOut->PrintMessage("Enter the new border width");
	string inputBW = pIn->GetSrting(pOut);
	int intBW = stoi(inputBW);
	pManager->ChngMBW(intBW);
	pOut->ClearStatusBar();

	}

//Execute the action
void ChngBW::Execute() 
{
		ReadActionParameters();
}
		
		
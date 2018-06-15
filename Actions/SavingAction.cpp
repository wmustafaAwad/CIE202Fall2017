#include "SavingAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string>




SavingAction::SavingAction(ApplicationManager * pApp) :Action(pApp)
{}

void SavingAction::ReadActionParameters()  //WALEED
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please input the name of the file you want to save to in Command Window.");

	//Get File Name and check it it's ok (check conditions on .txt file names)

	FileName = ""; char c;
	FileName = pIn->GetSrting(pOut);


	//Check for invalid Characters.
	while (FileName.find(char(47)) != -1 || FileName.find(char(92)) != -1 || FileName.find(char(63)) != -1 || FileName.find(char(37)) != -1
		|| FileName.find(char(42)) != -1 || FileName.find(char(58)) != -1 || FileName.find(char(124)) != -1 || FileName.find(char(34)) != -1
		|| FileName.find(char(60)) != -1 || FileName.find(char(62)) != -1 || FileName.find(char(46)) != -1 || FileName.find(char(32)) != -1) {
		pOut->PrintMessage("Your code contains an invalid character. Please remove it and input a correct File Name: ");
		FileName = pIn->GetSrting(pOut);
	}





	pOut->ClearStatusBar();

}

//Execute the action
void SavingAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters(); //Reads FileInput and sets OStream to handle a file with that file name.

							//Set Variable OStream's FileName to the input text
	string call = "Graphs/";
	call += FileName;
	call += ".txt";
	cout << call << endl;
	ofstream outfile(call);



	//Pass OStream by Reference to Application Manager to the Function SaveAll();
	//SaveAll Lets Application Manager Loop over all elements in FigList and Call their Save Function sending to it OStream by reference.
	pManager->SaveAll(outfile);

	//Close OStream
	outfile.close();

	//Set ChangedBit to False
	pManager->SetChangeBit(0);

}
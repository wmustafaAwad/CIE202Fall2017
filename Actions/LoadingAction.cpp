#include "LoadingAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;




LoadingAction::LoadingAction(ApplicationManager * pApp) :Action(pApp)
{}

void LoadingAction::ReadActionParameters()  //WALEED
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Please input the name of the file you want to load from.");
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
void LoadingAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters(); //Reads FileInput and sets IStream to handle a file with that file name.

							//Set Variable IStream's FileName to the input text
	string call = "Graphs/";
	call += FileName;
	call += ".txt";
	cout << call << endl;
	ifstream infile(call);

	//Load DrawColor, FillClr, BkgrndColor
	string line, word; int ctr = 0;
	getline(infile, line);
	ofstream ColorSave("Graphs/RAW.txt");
	ColorSave << line;
	ColorSave.close();
	ifstream ColorLoad("Graphs/RAW.txt");
	while (getline(ColorLoad, word, '|')) {
		if (ctr == 0) {
			int space1 = word.find(' ');
			int space2 = (word.substr(space1 + 1)).find(' ') + space1 + 1;
			UI.DrawColor.ucRed = stoi(word.substr(0, space1 - 0));
			UI.DrawColor.ucGreen = stoi(word.substr(space1 + 1, space2 - space1));
			UI.DrawColor.ucBlue = stoi(word.substr(space2 + 1));
		}
		else if (ctr == 1) {
			int space1 = word.find(' ');
			int space2 = (word.substr(space1 + 1)).find(' ') + space1 + 1;
			UI.FillColor.ucRed = stoi(word.substr(0, space1 - 0));
			UI.FillColor.ucGreen = stoi(word.substr(space1 + 1, space2 - space1));
			UI.FillColor.ucBlue = stoi(word.substr(space2 + 1));
		}
		else if (ctr == 2) {
			int space1 = word.find(' ');
			int space2 = (word.substr(space1 + 1)).find(' ') + space1 + 1;
			UI.BkGrndColor.ucRed = stoi(word.substr(0, space1 - 0));
			UI.BkGrndColor.ucGreen = stoi(word.substr(space1 + 1, space2 - space1));
			UI.BkGrndColor.ucBlue = stoi(word.substr(space2 + 1));
			cout << stoi(word.substr(0, space1 - 0)) << " " << stoi(word.substr(space1 + 1, space2 - space1)) << " " << stoi(word.substr(space2 + 1)) << endl;

		}
		ctr++;
	}
	Output* pO = pManager->GetOutput();
	pO->ClearDrawArea();

	ColorLoad.close();




	//Pass IStream by Reference to Application Manager to the Function LoadAll();
	//LoadAll Asks Application Manager to Loop over all elements in FigList and Call their Load Function, passing to it IStream by reference.
	pManager->LoadAll(infile);

	//Close OStream
	infile.close();

	//Set ChangedBit to False
	pManager->SetChangeBit(0);

}
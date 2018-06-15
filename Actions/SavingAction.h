#ifndef SAVING_ACTION
#define SAVING_ACTION

#include "Action.h"
#include <iostream>
#include <cstring>

using namespace std;

//Saving Action class
class SavingAction: public Action
{
private:
	string FileName;

public:
	SavingAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();
	
	//Writes to Save File
	virtual void Execute() ;
	
};

#endif
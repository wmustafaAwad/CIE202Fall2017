#ifndef LOADING_ACTION
#define LOADING_ACTION

#include "Action.h"
#include <iostream>
#include <cstring>

using namespace std;

//Saving Action class
class LoadingAction: public Action
{
private:
	string FileName;

public:
	LoadingAction(ApplicationManager *pApp);

	//Reads parameters
	virtual void ReadActionParameters();
	
	//Loads from Load File
	virtual void Execute() ;
	
};

#endif
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddLAction.h"
#include "Actions\DrawingAreaAction.h"
#include "Actions\ChngDrwClr.h"
#include "Actions\ChngBkClr.h"
#include "Actions\ChngFillClr.h"
#include "Actions\ChngBW.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\DeleteAction.h"
#include"Actions\MoveAction.h"
#include "Actions\SavingAction.h" //Waleed
#include "Actions\LoadingAction.h" //Waleed
#include "Figures\CCircle.h" //Waleed
#include "Figures\CLine.h" //Waleed
#include "Figures\CRectangle.h" //Waleed
#include "Figures\CTriangle.h" //Waleed

#include <iostream> 
#include <cstring>

using namespace std;



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction()
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(LastClicked);		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			ChangeBit=1; //Waleed
			break;

		case DRAW_LINE:
			///create AddLineAction here
			pAct = new AddLAction(this);
			ChangeBit=1; //Waleed
			break;
		case DRAW_TRI:
			pAct= new AddTriAction(this);
			ChangeBit=1; //Waleed
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			ChangeBit=1; //Waleed
			break;

		case EXIT:
			///create ExitAction here //Waleed ///No need for new Action
			if (ChangeBit == 1) {
				string decision; pOut->PrintMessage("You have unsaved changes. Do you Want to save before Exit? Y/Else");
				decision = pIn->GetSrting(pOut);
				if (decision[0] == 'y' || decision[0] == 'Y') {
					pAct = new SavingAction(this);
					pAct->Execute();//Execute
					delete pAct;	//Action is not needed any more ==> delete it
					pAct = NULL;
				}
			}
		
		case STATUS:	//a click on the status bar ==> no action
			return;

		
		case CHNG_FILL_CLR:
			pAct = new ChngFillClr(this);
			ChangeBit=1; //Waleed
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChngDrwClr(this);
			ChangeBit=1; //Waleed
			break;
		case CHNG_BK_CLR: 
			pAct = new ChngBkClr(this);
			ChangeBit=1; //Waleed
			break;
		case MOVE: 
			pAct = new MoveAction(this);
			break;
		case DEL: 
			pAct = new DeleteAction(this);
			ChangeBit=1; //Waleed
			break;
		case RESIZE: 
			pAct = new ChngBW(this);
			ChangeBit=1; //Waleed
			break;
        case ROTATE: 
			pOut->PrintMessage("You are rotating a figure");
			break;
	    case SEND_BACK: 
			pAct = new CopyAction(this);
			break;
		case BRNG_FRNT: 
			pAct = new PasteAction(this);
			break;
		case SAVE: 
			pAct= new SavingAction(this);
			ChangeBit=0; //Waleed
			break;
		case LOAD:
			if (FigCount >= 1) {
				string decision; pOut->PrintMessage("You have added Figure to your Drawing Area. Do you Want to append load to them? Y/else");
				decision = pIn->GetSrting(pOut);
				if (decision[0] == 'y' || decision[0] == 'Y') {
					pAct = new LoadingAction(this);
				}
				else {
					//Then Delete all Figures First
					pOut->ClearDrawArea();
					FigCount = 0;
					pAct = new LoadingAction(this);
				}
			}
			else {
				pAct = new LoadingAction(this);
			}

			break;
	    case TO_PLAY: 
			pOut->PrintMessage("You are switching from play mode to draw mode");
			break;
	    case CHNG_BW: 
			pAct = new ChngBW(this);
			ChangeBit=1; //Waleed
			break;

		case DRAWING_AREA:
			pAct = new DrawingAreaAction(this);
			ChangeBit=1; //Waleed
			break;
			
	    
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures

void ApplicationManager::AddFigure(CFigure* pFig)
{
	pFig->SetID(FigCount);
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point p1;
	p1.x = x;
	p1.y = y;
	for (int i = FigCount - 1; i >= 0; i--) {

		if (FigList[i]->SetSel(p1)) {
			return FigList[i];
		}
		///Add your code here to search for a figure given a point x,y	
	}

	return NULL;
}


///////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFigure(int x, int y)
{
	int i = GetFigureIndex(x, y);//Gets the index of the figure at the passed point
	//to check if there is a figure or not 
	if (i > -1){
		//If the figure is found shift the figlist by 1 to the left replacing the figure we want to delete
		for (int j = i; j < FigCount; j++) {
			FigList[j] = FigList[j + 1];
		}
		//decrement the figurecount
		FigCount--;
	}

}
void ApplicationManager::DeleteFigures()
{
	//loops on the figure list till it finds a selected figure
	for(int i=0;i<FigCount;i++){
	if(FigList[i]->IsSelected()){
		//if a figure is found
		//shift the figlist one cell to the left starting from the (i+1)th entry replacing the found figure
		for (int j = i; j < FigCount; j++) {
			FigList[j] = FigList[j + 1];
			}
		//decrement the figure count
		FigCount--;
		//decrement i so as not to skip the (i+1)th figure which is now the ith figure
		i--;
		}
	}

}


///////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigureIndex(int x, int y) const
{
	Point p1;
	p1.x = x;
	p1.y = y;
	//loop on the figurelist till you find a figure which includes this point then return its index
	//If no figure is found return -1
	for (int i = 0; i < FigCount; i++) {

		if (FigList[i]->SetSel(p1)) {
			return i;
		}
	}

	return -1;
}
//////////////////////////////////////////////////////////////////////////

//Waleed
void ApplicationManager::SaveAll(ofstream &OutFile){ //Waleed // Saves all figures by calling

	//Write Draw_Color  Fill_Color Background_Color to outfile
	OutFile<<int(UI.DrawColor.ucRed)<<" "<<int(UI.DrawColor.ucGreen)<<" "<<int(UI.DrawColor.ucBlue)<<"|"
	<<int(UI.FillColor.ucRed)<<" "<<int(UI.FillColor.ucGreen)<<" "<<int(UI.FillColor.ucBlue)<<"|"
	<<int(UI.BkGrndColor.ucRed)<<" "<<int(UI.BkGrndColor.ucGreen)<<" "<<int(UI.BkGrndColor.ucBlue)<<endl;

	OutFile<<FigCount<<endl;
	for (int i =0; i<FigCount; i++) {
		FigList[i]->Save(OutFile);
	}
}


///////////////////////////////////////////////////////////////////////////

//Waleed
void ApplicationManager::LoadAll(ifstream &InFile){
	string line;
	int x=0, y=0;
	Point dummyPoint1,dummyPoint2,dummyPoint3;
	dummyPoint1.x=x;dummyPoint1.y=y;
	dummyPoint2.x=x;dummyPoint2.y=y;
	dummyPoint3.x=x;dummyPoint3.y=y;
	GfxInfo dummyGfxInfo;

	while(getline(InFile,line)){
		if(line[0]=='R'){
			//Call Load for Rectangle
			CRectangle *RPointer=new CRectangle(dummyPoint1, dummyPoint2, dummyGfxInfo);
			AddFigure(RPointer->Load(InFile, line));
		}else if(line[0]=='C'){
			//Call Load for Circle
			CCircle *CPointer=new CCircle(dummyPoint1, dummyPoint2.x, dummyGfxInfo);
			AddFigure(CPointer->Load(InFile, line));
		}else if(line[0]=='T'){
			//Call Load for Triangle
			CTriangle *TPointer=new CTriangle(dummyPoint1, dummyPoint2,dummyPoint3, dummyGfxInfo);
			AddFigure(TPointer->Load(InFile, line));
		}else if(line[0]=='L'){
			//Call Load for Line
			CLine *LPointer=new CLine(dummyPoint1, dummyPoint2, dummyGfxInfo);
			AddFigure(LPointer->Load(InFile, line));
			}
	}
	
}


///////////////////////////////////////////////////////////////////////////





void ApplicationManager::ChngMDrwClr(color MDrwClr)
{
	int counter=0;
	for (int i=FigCount-1; i >= 0; i--)
	{
		if(FigList[i]->Selected)
		{
			FigList[i]->ChngDrawClr(MDrwClr);
			counter++;
		}
	}
	if(counter==0)
	{
		UI.DrawColor=MDrwClr;
	}
}

void ApplicationManager::ChngMFillClr(color MFillClr)
{
	int counter=0;
	for (int i=FigCount-1; i >= 0; i--)
	{
		if(FigList[i]->Selected)
		{
			FigList[i]->ChngFillClr(MFillClr);
			counter++;
		}
	}
	if(counter==0)
	{
		UI.FillColor=MFillClr;
	}
}

void ApplicationManager::ChngMBW(int MBW)
{
	int counter=0;
	for (int i=FigCount-1; i >= 0; i--)
	{
		if(FigList[i]->Selected)
		{
			FigList[i]->FigGfxInfo.BorderWdth=MBW;
			counter++;
		}
	}
	if(counter==0)
	{
		UI.PenWidth=MBW;
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeselectAll() {
	for (int i = 0; i<FigCount; i++)
		FigList[i]->SetSelected(0);
}
//////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}



Point ApplicationManager::GetLastClicked() {
	return LastClicked;
}


void ApplicationManager::SetChangeBit(bool Value){
	ChangeBit=Value;
}
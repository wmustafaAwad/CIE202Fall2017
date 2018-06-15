#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawL(point1, point2, FigGfxInfo, Selected);
}
bool CLine::SetSel(Point Pnew) {
	double m= (point1.y-point2.y)/(point1.x-point2.x); 
	double c= point1.y- m*point1.x; 
	if (Pnew.y== m*Pnew.x+c){
		Selected=1; 
	}
	else {
		return 0; 
	}

	return Selected;
}
void CLine::PrintInfo(Output* pOut) {
			 //print all figure info on the status bar
		
		pOut -> PrintMessage(" Line is selected "); 

		 }

void CLine::Save(ofstream &OutFile){
	
	
	OutFile<<"LINE"<<"|"<<ID<<"|"<<point1.x<<" "<<point1.y<<"|"<<point2.x<<" "<<point2.y<<"|"<<int(FigGfxInfo.DrawClr.ucRed)<<" "<<int(FigGfxInfo.DrawClr.ucGreen)<<" "<<int(FigGfxInfo.DrawClr.ucBlue)<<"|"
		<<FigGfxInfo.isFilled<<"|"<<int(FigGfxInfo.FillClr.ucRed)<<" "<<int(FigGfxInfo.FillClr.ucGreen)<<" "<<int(FigGfxInfo.FillClr.ucBlue)<<"|"<<FigGfxInfo.BorderWdth<<endl;

}




CFigure* CLine::Load(ifstream &Infile, string line){
			string word;
			int ctr=0;
			ofstream LineSave("Graphs/Cache.txt");
			LineSave<<line;
			LineSave.close();
			ifstream LineLoad("Graphs/Cache.txt");
			while(getline(LineLoad,word,'|')){
				if(ctr==1){
					ID=stoi(word);
				}else if(ctr==2){
					int space= word.find(' ');
					point1.x=stoi(word.substr(0,space));
					point1.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==3){
					int space= word.find(' ');
					point2.x=stoi(word.substr(0,space));
					point2.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==4){
					int space1= word.find(' ');
					int space2= (word.substr(space1+1)).find(' ')+space1+1;
					this->FigGfxInfo.DrawClr.ucRed=stoi(word.substr(0,space1-0));
					this->FigGfxInfo.DrawClr.ucGreen=stoi(word.substr(space1+1,space2-space1));
					this->FigGfxInfo.DrawClr.ucBlue=stoi(word.substr(space2+1));
				}else if(ctr==5){
					if(stoi(word)==0){
						this->FigGfxInfo.isFilled=0;
					}else if(stoi(word)==1){
						this->FigGfxInfo.isFilled=1;
					}
				}else if(ctr==6){
					if(this->FigGfxInfo.isFilled){
						int space1= word.find(' ');
						int space2= (word.substr(space1+1)).find(' ')+space1+1;
						this->FigGfxInfo.FillClr.ucRed=stoi(word.substr(0,space1-0));
						this->FigGfxInfo.FillClr.ucGreen=stoi(word.substr(space1+1,space2-space1));
						this->FigGfxInfo.FillClr.ucBlue=stoi(word.substr(space2+1));
					}
				}else if(ctr==7){
					this->FigGfxInfo.BorderWdth=stoi(word);
				}
				ctr++;
			}
			LineLoad.close();
			return this;
}
#include "CCircle.h"
#include <math.h> 

CCircle::CCircle(Point P1,int rad, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
		Center = P1;
		RADIUS = rad;
}
	

void CCircle::Draw(Output* pOut) const
{	
	pOut->DrawCirc(Center, RADIUS, FigGfxInfo, Selected);
}
bool CCircle::SetSel(Point Pnew) { 


	if (pow(pow(Pnew.x - Center.x, 2) + pow(Pnew.y - Center.y, 2), 0.5) <= RADIUS) {
		Selected = !Selected; //To Deselect when clicked on.
		return 1;

	}
	else
	{
		return 0;
	}

}
int CCircle:: getRadius ()const{
	return RADIUS; 
}
	double CCircle:: getArea ()const{
	double area= RADIUS*RADIUS*3.14;
	return area;
	}

	 void CCircle::PrintInfo(Output* pOut) {
			 //print all figure info on the status bar
		int temp1= getRadius(); 
		std::string r = std::to_string(ceil(temp1));
		double temp2= getArea(); 
		std::string AREA = std::to_string(ceil(temp2));
		int FID= GetID();
		std::string id = std::to_string(FID);
		pOut -> PrintMessage(" Radius equals "+ r.substr(0,6)+ " Area equals "+ AREA.substr(0,6) + " Figure ID: "+ id); 

		 }

void CCircle::Save(ofstream &OutFile){
	
	OutFile<<"CIRCLE"<<"|"<<ID<<"|"<<Center.x<<" "<<Center.y<<"|"<<RADIUS<<"|"<<int(FigGfxInfo.DrawClr.ucRed)<<" "<<int(FigGfxInfo.DrawClr.ucGreen)<<" "<<int(FigGfxInfo.DrawClr.ucBlue)<<"|"
		<<FigGfxInfo.isFilled<<"|"<<int(FigGfxInfo.FillClr.ucRed)<<" "<<int(FigGfxInfo.FillClr.ucGreen)<<" "<<int(FigGfxInfo.FillClr.ucBlue)<<"|"<<FigGfxInfo.BorderWdth<<endl;

}

CFigure* CCircle::CreateFromPointer(Point P) {
	CCircle* pFig = new CCircle(P, RADIUS, FigGfxInfo);
	//checks if the figure is in the drawing area
	if(pFig->Center.x+pFig->RADIUS<1300&& pFig->Center.x - pFig->RADIUS>0&& pFig->Center.y + pFig->RADIUS<650 && pFig->Center.y - pFig->RADIUS>80)
	return pFig;
	else return NULL;
}//calls the circle constructor with the new parameters if they are valid

CFigure* CCircle::Load(ifstream &Infile, string line){
	string word;
			int ctr=0;
			ofstream CircSave("Graphs/Cache.txt");
			CircSave<<line;
			CircSave.close();
			ifstream CircLoad("Graphs/Cache.txt");
			while(getline(CircLoad,word,'|')){
				if(ctr==1){
					ID=stoi(word);
				}else if(ctr==2){
					int space= word.find(' ');
					Center.x=stoi(word.substr(0,space));
					Center.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==3){
					RADIUS=stoi(word);	
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
			CircLoad.close();
			return this;
}
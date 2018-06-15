#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
int CRectangle::minimum(int x1, int x2) {
	int min;
	if (x1 <= x2) {
		min = x1;
	}
	else
	{
		min = x2;
	}
	return min;
}
int CRectangle::maximum(int x1, int x2) {
	int max;
	if (x1 >= x2) {
		max = x1;
	}
	else
	{
		max = x2;
	}
	return max;
}


bool CRectangle::SetSel(Point Pnew) { //Aya5


	int min_x = minimum(Corner1.x, Corner2.x);
	int min_y = minimum(Corner1.y, Corner2.y);
	int max_x = maximum(Corner1.x, Corner2.x);
	int max_y = maximum(Corner1.y, Corner2.y);




	if (Pnew.x <= max_x && Pnew.y >= min_y && Pnew.x >= min_x && Pnew.y <= max_y) {
		Selected = !Selected;
		return 1;
	}
	else
	{
		return 0;
	}


}
void CRectangle::PrintInfo(Output* pOut) {
			 //print all figure info on the status bar
	int min_x = minimum(Corner1.x, Corner2.x);
	int min_y = minimum(Corner1.y, Corner2.y);
	int max_x = maximum(Corner1.x, Corner2.x);
	int max_y = maximum(Corner1.y, Corner2.y);

		double height1= max_y- min_y;
		std::string height = std::to_string(height1);		
		double width1= max_x - min_x;
		std::string width = std::to_string(width1);	
		double circum= (height1+ width1)*2; 
		std::string circumference = std::to_string(circum);	
		int FID= GetID();
		std::string id = std::to_string(FID);	




		pOut -> PrintMessage("Heigt equals "+ height.substr(0,6) +" "+ "Width equals "+" "+ width.substr(0,6)+" "+ "Circumference equals "+" "+ circumference.substr(0,6)+ "  Figure ID: "+ id); 

		 }


void CRectangle::Save(ofstream &OutFile){
	
	
	OutFile<<"RECT"<<"|"<<ID<<"|"<<Corner1.x<<" "<<Corner1.y<<"|"<<Corner2.x<<" "<<Corner2.y<<"|"<<int(FigGfxInfo.DrawClr.ucRed)<<" "<<int(FigGfxInfo.DrawClr.ucGreen)<<" "<<int(FigGfxInfo.DrawClr.ucBlue)<<"|"
		<<FigGfxInfo.isFilled<<"|"<<int(FigGfxInfo.FillClr.ucRed)<<" "<<int(FigGfxInfo.FillClr.ucGreen)<<" "<<int(FigGfxInfo.FillClr.ucBlue)<<"|"<<FigGfxInfo.BorderWdth<<endl;

}

CFigure* CRectangle::CreateFromPointer(Point P) {
	//computes the geometric centre of the rectangle
	Point Centroid;
	Centroid.x = ((Corner1.x) + (Corner2.x)) / 2;
	Centroid.y = ((Corner1.y) + (Corner2.y)) / 2;
	//computes the magnitude of the translation of the geometric centre
	Point translationpoint;
	translationpoint.x = P.x - Centroid.x;
	translationpoint.y = P.y - Centroid.y;
	//translates the corners
	Point Newcorner1;
	Newcorner1.x = Corner1.x + translationpoint.x;
	Newcorner1.y = Corner1.y + translationpoint.y;
	Point Newcorner2;
	Newcorner2.x = Corner2.x + translationpoint.x;
	Newcorner2.y = Corner2.y + translationpoint.y;
	//checks if the figure is in the drawing area
	if (Newcorner1.y > 80 && Newcorner1.y < 650 && Newcorner2.y>80 && Newcorner2.y < 650 && Newcorner1.x > 0 && Newcorner1.x < 1300 && Newcorner2.x>0 && Newcorner2.x < 1300) {
		CRectangle* outfig = new CRectangle(Newcorner1, Newcorner2, FigGfxInfo);
		return outfig;
	}
	else return NULL;
}
CFigure* CRectangle::Load(ifstream &Infile, string line){
		string word;
			int ctr=0;
			ofstream RectSave("Graphs/Cache.txt");
			RectSave<<line;
			RectSave.close();
			ifstream RectLoad("Graphs/Cache.txt");
			
			while(getline(RectLoad,word,'|')){
				if(ctr==1){
					ID=stoi(word);
					
				}else if(ctr==2){
					int space= word.find(' ');
					Corner1.x=stoi(word.substr(0,space));
					Corner1.y= stoi(word.substr(space+1,word.length()-space));
					
				}else if(ctr==3){
					int space= word.find(' ');
					Corner2.x=stoi(word.substr(0,space));
					Corner2.y= stoi(word.substr(space+1,word.length()-space));
					
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
					
						int space1= word.find(' ');
						int space2= (word.substr(space1+1)).find(' ')+space1+1;
						this->FigGfxInfo.FillClr.ucRed=stoi(word.substr(0,space1-0));
						this->FigGfxInfo.FillClr.ucGreen=stoi(word.substr(space1+1,space2-space1));
						this->FigGfxInfo.FillClr.ucBlue=stoi(word.substr(space2+1));
					
				
				}else if(ctr==7){
					this->FigGfxInfo.BorderWdth=stoi(word);
					
				}
				
				ctr++;
				
			}
			RectLoad.close();
			return this;
}
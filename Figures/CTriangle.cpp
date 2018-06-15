#include "CTriangle.h"
#include <iostream>
#include< math.h>

using namespace std;

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Vertex1 = P1;
	Vertex2 = P2;
	Vertex3 = P3;
}



	
Point MinY(Point P1, Point P2) {
	Point P;
	if (P1.y <= P2.y) {
		P = P1;
	}
	else
	{
		P = P2;
	}
	return P;
}

Point minXPoint(Point P1, Point P2) {
	Point P;
	if (P1.x <= P2.x) {
		P = P1;
	}
	else
	{
		P = P2;
	}
	return P;

}


Point* DefPoints(Point P1, Point P2, Point P3) {
	Point max3P, max2P;
	Point min2P;
	Point LeftPoint;

	max2P = MinY(P1, P2);
	max3P = MinY(max2P, P3);

	if (P3.x == max3P.x && P3.y == max3P.y) {
		min2P = minXPoint(P1,P2);
	}
	else if (P2.x == max3P.x && P2.y == max3P.y) {
		min2P = minXPoint(P1,P3);
	}
	else if (P1.x == max3P.x && P1.y == max3P.y) {
		min2P = minXPoint(P2, P3);
	}

	if (P3.x == max3P.x && P3.y == max3P.y && P2.x == min2P.x && P2.y == min2P.y) { //P3 IS MAX Y, P2 IS MIN X
		LeftPoint = P1;
	}
	else if (P2.x == max3P.x && P2.y == max3P.y && P3.x == min2P.x && P3.y == min2P.y) { //P2 IS MAX Y, P3 IS MIN X
		LeftPoint = P1;
	}
	//
	else if (P1.x == max3P.x && P1.y == max3P.y && P2.x == min2P.x && P2.y == min2P.y) { //P1 IS MAX Y, P2 IS MIN X
		LeftPoint = P3;
	}
	else if (P2.x == max3P.x && P2.y == max3P.y && P1.x == min2P.x && P1.y == min2P.y) { //P2 IS MAX Y, P1 IS MIN X
		LeftPoint = P3;
	}
	//
	else if (P1.x == max3P.x && P1.y == max3P.y && P3.x == min2P.x && P3.y == min2P.y) { //P1 IS MAX Y, P3 IS MIN X
		LeftPoint = P2;
	}
	else if (P3.x == max3P.x && P3.y == max3P.y && P1.x == min2P.x && P1.y == min2P.y) { //P3 IS MAX Y, P1 IS MIN X
		LeftPoint = P2;
	}

	Point PARRAY[3];
	PARRAY[0] = max3P;
	PARRAY[1] = min2P;
	PARRAY[2] = LeftPoint;

	//

	return PARRAY;
}



void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Vertex1, Vertex2,Vertex3, FigGfxInfo, Selected);
}
bool CTriangle::SetSel(Point Pnew) { //Aya5

	Point P1, P2, P3;
	Point* VertexArray;
	VertexArray = DefPoints(Vertex1, Vertex2, Vertex3);
	P3 = VertexArray[0];
	P1 = VertexArray[1];
	P2 = VertexArray[2];

	
	double m1 = double (P3.y - P1.y) /double (P3.x - P1.x);
	double m2 = double (P3.y - P2.y) / double (P3.x - P2.x);
	double m3 = double (P2.y - P1.y) / double (P2.x - P1.x);
	//double mid1y= double (P3.y-P1.y/2.0); 	double mid1x= double (P3.x-P1.x/2.0);
	//double mid2y= double (P3.y-P2.y/2.0); 	double mid2x= double (P3.x-P2.x/2.0);
	//double mid3y= double (P2.y-P1.y/2.0); 	double mid3x= double (P2.x-P1.x/2.0);

	double c1 = P3.y - m1* P3.x;
	double c2 = P2.y - m2* P2.x;
	double c3 = P1.y - m3* P1.x;

	if (Pnew.x >= double (Pnew.y -c1)/m1 && Pnew.x <= double (Pnew.y -c2)/m2 && Pnew.y <= m3* Pnew.x + c3 && Pnew.y>= P3.y){

		Selected = !Selected;
		return 1;
	}
	else
	{
		return 0;
	}

}
CFigure* CTriangle::CreateFromPointer(Point P) {
	//computes the geometric centre of the triangle
	Point Centroid;
	Centroid.x = ((Vertex1.x) + (Vertex2.x) + (Vertex3.x)) / 3;
	Centroid.y = ((Vertex1.y) + (Vertex2.y) + (Vertex3.y)) / 3;
	//computes the magnitude of the translation of the geometric centre
	Point translationpoint;
	translationpoint.x = P.x - Centroid.x;
	translationpoint.y = P.y - Centroid.y;
	//translates the vertices
	Point Newvertex1;
	Newvertex1.x = (Vertex1.x) + translationpoint.x;
	Newvertex1.y = (Vertex1.y) + translationpoint.y;
	Point Newvertex2;
	Newvertex2.x = (Vertex2.x) + translationpoint.x;
	Newvertex2.y = (Vertex2.y) + translationpoint.y;
	Point Newvertex3;
	Newvertex3.x = (Vertex3.x) + translationpoint.x;
	Newvertex3.y = (Vertex3.y) + translationpoint.y;
	//checks if the figure is in the drawing area
	if (Newvertex1.y > 80 && Newvertex1.y < 650 && Newvertex2.y>80 && Newvertex2.y < 650 && Newvertex3.y>80 && Newvertex3.y < 650 && Newvertex1.x>0 && Newvertex1.x < 1300 && Newvertex2.x>0 && Newvertex2.x < 1300 && Newvertex3.x>0 && Newvertex3.x < 1300) {
		//Creates a new rectangle with the new parameters
		CTriangle* outfig = new CTriangle(Newvertex1, Newvertex2, Newvertex3, FigGfxInfo);
		return outfig;
	}
	else return NULL;
}
void CTriangle::PrintInfo(Output* pOut){
			 //print all figure info on the status bar
Point P1, P2, P3;
	Point* VertexArray;
	VertexArray = DefPoints(Vertex1, Vertex2, Vertex3);
	P3 = VertexArray[0];
	P1 = VertexArray[1];
	P2 = VertexArray[2];
	double dis1= pow(pow(P3.x-P1.x,2)+ pow(P3.y-P1.y,2),0.5);
	std::string distance1 = std::to_string(dis1);
	double dis2= pow(pow(P3.x-P2.x,2)+ pow(P3.y-P2.y,2),0.5);
	std::string distance2 = std::to_string(dis2);
	double dis3= pow(pow(P2.x-P1.x,2)+ pow(P2.y-P1.y,2),0.5);
	std::string distance3 = std::to_string(dis3);
    double circ= dis1+ dis2+ dis3;
	std::string circumference = std::to_string(circ);
	int FID= GetID();
	std::string id = std::to_string(FID);
	pOut -> PrintMessage(" Distance 1 equals "+ distance1.substr(0,6) + " Distance 2 equals "+ distance2.substr(0,6) +" Distance 3 equals "+ distance3.substr(0,6)+ "Circumference equals "+ " "+circumference.substr(0,6)+ "Figure ID: "+ id); 

		 }


void CTriangle::Save(ofstream &OutFile){
	
	OutFile<<"TRIANG"<<"|"<<ID<<"|"<<Vertex1.x<<" "<<Vertex1.y<<"|"<<Vertex2.x<<" "<<Vertex2.y<<"|"<<Vertex3.x<<" "<<Vertex3.y<<"|"<<int(FigGfxInfo.DrawClr.ucRed)<<" "<<int(FigGfxInfo.DrawClr.ucGreen)<<" "<<int(FigGfxInfo.DrawClr.ucBlue)<<"|"
		<<FigGfxInfo.isFilled<<"|"<<int(FigGfxInfo.FillClr.ucRed)<<" "<<int(FigGfxInfo.FillClr.ucGreen)<<" "<<int(FigGfxInfo.FillClr.ucBlue)<<"|"<<FigGfxInfo.BorderWdth<<endl;


}



CFigure* CTriangle::Load(ifstream &Infile,string line){
	string word;
			int ctr=0;
			ofstream TriSave("Graphs/Cache.txt");
			TriSave<<line;
			TriSave.close();
			ifstream TriLoad("Graphs/Cache.txt");
			while(getline(TriLoad,word,'|')){
				if(ctr==1){
					ID=stoi(word);
				}else if(ctr==2){
					int space= word.find(' ');
					Vertex1.x=stoi(word.substr(0,space));
					Vertex1.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==3){
					int space= word.find(' ');
					Vertex2.x=stoi(word.substr(0,space));
					Vertex2.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==4){
					int space= word.find(' ');
					Vertex3.x=stoi(word.substr(0,space));
					Vertex3.y= stoi(word.substr(space+1,word.length()-space));
				}else if(ctr==5){
					int space1= word.find(' ');
					int space2= (word.substr(space1+1)).find(' ')+space1+1;
					this->FigGfxInfo.DrawClr.ucRed=stoi(word.substr(0,space1-0));
					this->FigGfxInfo.DrawClr.ucGreen=stoi(word.substr(space1+1,space2-space1));
					this->FigGfxInfo.DrawClr.ucBlue=stoi(word.substr(space2+1));
				}else if(ctr==6){
					if(stoi(word)==0){
						this->FigGfxInfo.isFilled=0;
					}else if(stoi(word)==1){
						this->FigGfxInfo.isFilled=1;
					}
				}else if(ctr==7){
					if(this->FigGfxInfo.isFilled){
						int space1= word.find(' ');
						int space2= (word.substr(space1+1)).find(' ')+space1+1;
						this->FigGfxInfo.FillClr.ucRed=stoi(word.substr(0,space1-0));
						this->FigGfxInfo.FillClr.ucGreen=stoi(word.substr(space1+1,space2-space1));
						this->FigGfxInfo.FillClr.ucBlue=stoi(word.substr(space2+1));
					}
				}else if(ctr==8){
					this->FigGfxInfo.BorderWdth=stoi(word);
				}
				ctr++;
			}
			TriLoad.close();
			return this;
}
#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	//MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	    MenuItemImages[ITM_TRI]= "images\\MenuItems\\Menu_TRI.jpg";
		MenuItemImages[ITM_LINE]= "images\\MenuItems\\Menu_LINE.jpg";
		MenuItemImages[ITM_CHNG_FILL_CLR]= "images\\MenuItems\\Menu_CHNG_FILL_CLR.jpg";
		MenuItemImages[ITM_CHNG_DRAW_CLR]= "images\\MenuItems\\Menu_CHNG_DRAW_CLR.jpg";
		MenuItemImages[ITM_CHNG_BK]= "images\\MenuItems\\Menu_CHNG_BK.jpg";
		MenuItemImages[ITM_MOVE]= "images\\MenuItems\\Menu_MOVE.jpg";
		MenuItemImages[ITM_DEL]= "images\\MenuItems\\Menu_DEL.jpg";
		MenuItemImages[ITM_RESIZE]= "images\\MenuItems\\Menu_RESIZE.jpg";
		MenuItemImages[ITM_ROTATE]= "images\\MenuItems\\Menu_ROTATE.jpg";
		MenuItemImages[ITM_SEND_BACK]= "images\\MenuItems\\Copy.jpg";
		MenuItemImages[ITM_BRNG_FRNT]= "images\\MenuItems\\Paste.jpg";
		MenuItemImages[ITM_SAVE]= "images\\MenuItems\\Menu_SAVE.jpg";
		MenuItemImages[ITM_LOAD]= "images\\MenuItems\\Menu_LOAD.jpg";
		MenuItemImages[ITM_EXIT_DRAW]= "images\\MenuItems\\Menu_EXIT_DRAW.jpg";
		MenuItemImages[ITM_TO_PLAY]= "images\\MenuItems\\Menu_TO_PLAY.jpg";
		MenuItemImages[ITM_CHNG_BW]= "images\\MenuItems\\Menu_CHNG_BW.jpg";
		MenuItemImages[ITM_UNDO]= "images\\MenuItems\\Menu_UNDO.jpg";
		MenuItemImages[ITM_REDO]= "images\\MenuItems\\Menu_REDO.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorPallete() const
{
	pWind->DrawImage("images\\MenuItems\\color-palette.jpg", 6*UI.MenuItemWidth,UI.ToolBarHeight,3*UI.MenuItemWidth, 6*UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::CreatePlayToolBar() const
{
	//play mode 
	string MenuItemImages[PLAY_ITM_COUNT];
	UI.InterfaceMode = MODE_PLAY;
	MenuItemImages[PLAY_ITM_TO_DRAW] = "images\\MenuItems\\Menu_PLAY_ITM_TO_DRAW.png";
	MenuItemImages[ITM_PICK_HIDE_FILL] = "images\\MenuItems\\Menu_PICK_HIDE_FILL.png";
	MenuItemImages[ITM_PICK_HIDE_TYPE] = "images\\MenuItems\\Menu_PICK_HIDE_TYPE.png";
	MenuItemImages[ITM_PICK_HIDE_BOTH] = "images\\MenuItems\\Menu_PICK_HIDE_BOTH.png";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_EXIT_PLAY.png";

	//Draw menu item one image at a time
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
///////////////////////
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
////////////////////////////////////////////////////////////////////////////////////
void Output::DrawL(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected)const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}
////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawCirc(Point P1, int r, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, r, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}


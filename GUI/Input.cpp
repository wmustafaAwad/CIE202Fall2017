#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

color Input::GetColor()const
{
	int x,y;
	pWind->WaitMouseClick(x,y);
	return pWind->GetColor(x,y);
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(Point& LTClicked) 
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	LTClicked.x = x;
	LTClicked.y = y;

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT:			return DRAW_RECT;
			case ITM_CIRC:			return DRAW_CIRC;
			case ITM_EXIT_DRAW:		return EXIT;
			case ITM_TRI:			return DRAW_TRI;   
			case ITM_LINE:			return DRAW_LINE;
			case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_BW:		return CHNG_BW;
			case ITM_CHNG_BK:       return CHNG_BK_CLR;
			case ITM_MOVE:          return MOVE;
			case ITM_DEL:			return DEL;
			case ITM_RESIZE:	    return RESIZE;
			case ITM_ROTATE:	    return ROTATE;
			case ITM_SEND_BACK:		return SEND_BACK;
			case ITM_BRNG_FRNT:		return BRNG_FRNT;
			case ITM_SAVE:	        return SAVE;
			case ITM_LOAD:			return LOAD;
			case ITM_TO_PLAY:       return TO_PLAY;
			case ITM_UNDO:			return UNDO;
			case ITM_REDO:			return REDO;	
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case   PLAY_ITM_TO_DRAW :		return TO_DRAW   ;
			case   ITM_PICK_HIDE_FILL:		return PICK_HIDE_FILL   ;
			case   ITM_PICK_HIDE_TYPE:		return PICK_HIDE_TYPE   ;
			case   ITM_PICK_HIDE_BOTH:		return PICK_HIDE_BOTH   ;
			case   ITM_EXIT_PLAY:			return EXIT    ;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	}	

/////////////////////////////////
	
Input::~Input()
{
}

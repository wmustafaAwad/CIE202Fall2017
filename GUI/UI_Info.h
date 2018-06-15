#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRI,        //Triangle Item in Menu
	ITM_LINE,       // Line Item in Menu
	ITM_CHNG_FILL_CLR, // Change fill color, for next if no fig. is selected, for figure and next if fig.(s) is selected.
	ITM_CHNG_DRAW_CLR, // Change draw color, for next if no fig. is selected, for figure and next if fig.(s) is selected.
	ITM_CHNG_BK,         // Change bk color
	ITM_MOVE,            //Move without Drag.
	ITM_DEL,			 //Delete a figure(s)
	ITM_RESIZE,			  //Resize a figure(s)
	ITM_ROTATE,			    //Rotate a figure(s)
	ITM_SEND_BACK,		    //Send a figure to the back of all figures
	ITM_BRNG_FRNT,		    //Bring a figure to the front of all figures
	ITM_SAVE,			    //Save the whole graph to a file
	ITM_LOAD,			    //Load a graph from a file
	ITM_EXIT_DRAW,			    //Exit the application
    ITM_TO_PLAY,             //Switch to Play mode from Draw Mode
    ITM_CHNG_BW,          //Change Border Width.
    ITM_UNDO,
    ITM_REDO,

	//TODO: Add more items names here
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	
	PLAY_ITM_TO_DRAW,			//4// Switch to Draw Mode.
    ITM_PICK_HIDE_FILL,         //2// Choose Pick by fill from Pick and Hide.
    ITM_PICK_HIDE_TYPE,         //3// Choose Pick by type from Pick and Hide.
    ITM_PICK_HIDE_BOTH,         //5// Choose Pick by both fill and type from Pick and Hide.
	ITM_EXIT_PLAY,				//6// Exit Program.
	PLAY_ITM_COUNT				//no. of menu items ==> This should be the last line in this enum
};







__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif
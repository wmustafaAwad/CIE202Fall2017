#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		    //Draw Line
	DRAW_RECT,		    //Draw Rectangle
	DRAW_TRI,		    //Draw Triangle
	DRAW_CIRC,		    //Draw Circle
	CHNG_DRAW_CLR,		//7// Change the drawing color
	CHNG_FILL_CLR,		//8// Change the filling color
	CHNG_BK_CLR,	    //Change background color
	DEL,			    //Delete a figure(s)
	MOVE,			    //Move a figure(s)
	RESIZE,			    //Resize a figure(s)
	ROTATE,			    //Rotate a figure(s)
	SEND_BACK,		    //Send a figure to the back of all figures
	BRNG_FRNT,		    //Bring a figure to the front of all figures
	SAVE,			    //Save the whole graph to a file
	LOAD,			    //Load a graph from a file
	EXIT,			    //Exit the application

	DRAWING_AREA,	//A click on the drawing area  //16// May be redundant, check if we need to remove it.
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode

	CHNG_BW,         //1//Change Border Width
	//SEL_FIG_INSIDE,      //2// Select Figure(s) if inside of Figure is clicked
	//SEL_FIG_BORDER,      //3// Select Figure(s) if its border is clicked
	//EMPTY_DESLECT,       //15// Deselect Selected Figure(s) if Empty area in Drawing Space is selected.
 //                           // Two Scenarios:
 //                           //a- Multiple Selection: Default.
                            //b- Select individual shape while previously selecting another: First Click on empty space to deselect then select the shape.
    PICK_HIDE_FILL,          //10// Choose Pick by fill from Pick and Hide.
    PICK_HIDE_TYPE,          //11// Choose Pick by type from Pick and Hide.
    PICK_HIDE_BOTH,           //12// Choose Pick by both fill and type from Pick and Hide.
    UNDO,                    //13// Undo.	
    REDO,                  //14// Redo.
    //DRAG_FOLLOW,            //17// Initiated by a long click, orders shape to follow pointer.
    //                        // We do not need a drop action since the boolean value (FOLLOW) will be automatically set to false
    //                        // after the user terminates the click (loop check and set to false after loop.)
	PLAYING_AREA			//19// A click not on toolbar nor status bar in Play mode.

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif

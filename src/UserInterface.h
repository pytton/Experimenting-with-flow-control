#ifndef _UserInterface_H_INCLUDED_
#define _UserInterface_H_INCLUDED_

//Include only once

//#pragma once

#include "FLUID/FluidInterface.h"
//#include "Pointers.h"

#include <iostream>
#include <sstream>
#include <stdio.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Text_Display.H>


class WidgetTable;	//forward declaration
class Display;
class MikeSimulator;

class UserInterface : public FluidInterface
{	//elements of FluidInterface:
	
	//Fl_Double_Window *m_window1;
	//Fl_Double_Window *m_window2;

	//Fl_Button *m_btn_load_data;
	//Fl_Value_Input *m_starting_bid;
	//Fl_Value_Input *m_curr_ask;
	//Fl_Value_Input *m_top_limit;
	//Fl_Value_Input *m_top_profit;
	//Fl_Table *m_table;
	//Fl_Value_Input *m_curr_bid;
	//Fl_Value_Input *m_bottom_limit;
	//Fl_Value_Input *m_bottom_profit;
	//Fl_Button *m_btn_up;
	//Fl_Button *m_btn_down;
	//Fl_Button *m_btn_next;
	//Fl_Button *m_btn_initAlgo;
	//Fl_Button *m_set_startBid;
	//Fl_Button *m_set_topLimit;
	//Fl_Button *m_set_btmLimit;
	//Fl_Value_Slider *m_slider1;
	//Fl_Button *m_btn_extra;	
	//Fl_Text_Display *text_display;

public:
	//members:
	WidgetTable *m_pTable;		//this replaces regular Fl_Table with my custom one	
	MikeSimulator * ptr_to_mikesimulator;
	Display * m_pDisplay;	//points to object creating this object
	Fl_Button* m_myExtraBtn;
	Fl_Text_Buffer * textBuffer;
	Fl_Text_Display * text;
	std::stringstream textDisplayString;

	//constructors/destructor:
	UserInterface(MikeSimulator * p, Display * ptr_t_display);

	//GETTERS / SETTERS:
	Display * GetDisplay();
	void SetDisplay(Display * ptr_t_display);
	MikeSimulator* GetMikeSim() { return ptr_to_mikesimulator; }
	inline WidgetTable *GetTable()
	{
		return m_pTable;
	}
	inline void SetTable(WidgetTable * pTable)
	{
		m_pTable = pTable;
	}

	//helper functions
	void show();

//CALLBACKS
private:
	static void m_down_btn_cb(Fl_Widget *w, void * p);
	static void m_up_btn_cb(Fl_Widget *w, void * p);
	static void m_slider1_cb(Fl_Widget *w, void * p);

	//OLD CALLBACKS FOR REFERENCE:
	static void experimental2_cb(Fl_Widget *w, void * p);
	static void experimental_cb(Fl_Widget *w, void * p);
	static void experim3(Fl_Widget *w, void * p);	//THIS FUNCTION CHANGES SIZE OF WIDGETTABLE

};


//class My_fl_button : public Fl_Button  //with location of button in Fl_Table
//{
//public:
//	//below determines where in the Fl_Table the button is located
//	//needs to be set inside WidgetTable::SetSize function
//	int x_pos;	//column of button -> 0 is the first
//	int y_pos;	//row of button -> 0 is the first
//
//	//constructor:
//	My_fl_button(int x, int y, int w, int h, const char *l);	//x_pos y_pos set to 0 by default
//
//};



#endif //_UserInterface_H_INCLUDED_
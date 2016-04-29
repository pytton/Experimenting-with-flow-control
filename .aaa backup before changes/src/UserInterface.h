#ifndef _UserInterface_H_INCLUDED_
#define _UserInterface_H_INCLUDED_

//Include only once

//#pragma once

#include "FLUID/FluidInterface.h"
#include "Pointers.h"

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
{	
public:
	//constructors/destructor:
	UserInterface(MikeSimulator * p, Display * ptr_t_display);

	Fl_Text_Buffer * textBuffer;
	Fl_Text_Display * text;

	std::stringstream textDisplayString;
//CALLBACKS
	static void m_down_btn_cb(Fl_Widget *w, void * p);
	static void m_up_btn_cb(Fl_Widget *w, void * p);
	static void m_slider1_cb(Fl_Widget *w, void * p);

	//OLD CALLBACKS FOR REFERENCE:
	static void experimental2_cb(Fl_Widget *w, void * p);
	static void experimental_cb(Fl_Widget *w, void * p);
	static void experim3(Fl_Widget *w, void * p);	//THIS FUNCTION CHANGES SIZE OF WIDGETTABLE
	//helper functions
	void show();

//GETTERS / SETTERS:
	Display * GetDisplay();
	void SetDisplay(Display * ptr_t_display);
	MikeSimulator* GetMikeSim() { return ptr_to_mikesimulator;}
	inline WidgetTable *GetTable()
	{
		return m_pTable;
	}
	inline void SetTable(WidgetTable * pTable)
		{
		m_pTable = pTable;
		}

//private:
	//members:
	WidgetTable *m_pTable;		//this replaces regular Fl_Table with my custom one	
	MikeSimulator * ptr_to_mikesimulator;
	//Display * ptr_t_display;	//points to object creating this object
	Display * m_pDisplay;	//points to object creating this object
	Fl_Button* m_myExtraBtn;
};


class WidgetTable : public Fl_Table_Row		//WigetTable - table with cells drawed inside it
{
protected:
	void draw_cell(TableContext context, int R = 0, int C = 0, int X = 0, int Y = 0, int W = 0, int H = 0);	//supplied from example - dont know how this works
public:
	//constructor:
	WidgetTable(UserInterface * pUserInterface, int x, int y, int w, int h, const char *l);
	~WidgetTable()
	{ 
	
	}

	//callbacks:
	static void button_cb(Fl_Widget *w, void * p);	//callbacks in fltk have to be static

	//helper functions:
	void printInTable(int row, int col, std::string text);	//row = 0 is first row!
	Fl_Widget * GetElement(int nRow, int nCol);	//returns a pointer to the cell in the table at nRow nCol
	void SetSize(int newrows, int newcols, WidgetTable * mytable);	//fills the table with cells:
	void ColHeaderText(char * s, int C);	//defines text of column headers
	UserInterface * GetUserInterface()
	{
		return	ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	}
	void WidgetTable::PopPriceCol(/*WidgetTable * myTable*/); //populates the Price column with prices based on current TopRowPrice
	void WidgetTable::PopPriceCol(WidgetTable * myTable); //populates the Price column with prices based on current TopRowPrice

//GETTERS / SETTERS:
	inline void SetRows(int numRows)
	{
		table_rows=numRows;
	}
	inline void SetCols(int numCol)
	{
		table_cols = numCol;
	}
	inline int GetRows()
	{
		return table_rows;
	}
	inline int GetCols()
	{
		return table_cols;
	}
	int RowOfPrice(long price);	//given price - returns the row in which that price is displayed in WidgetTable
	long PriceOfRow(int row);	//given the row - returns what price is currently printed in that row
	MikeSimulator * GetMikeSim();	//returns pointer to mikesimulator
	inline int GetTopRowPrice() { return TopRowPrice; }
	inline void SetTopRowPrice(int value) { TopRowPrice = value; }


//private:
	UserInterface * ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	int table_rows, table_cols;
	int ButtonColsNumber;	//how many columns are buttons?
	int TopRowPrice;		//the price at the first row on top - used to determine which positions to display
	MikeSimulator * mikesimulator;
//	bool PricesAlreadyPrinted;
};

class My_fl_button : public Fl_Button  //with location of button in Fl_Table
{
public:
	//below determines where in the Fl_Table the button is located
	//needs to be set inside WidgetTable::SetSize function
	int x_pos;	//column of button -> 0 is the first
	int y_pos;	//row of button -> 0 is the first

	//constructor:
	My_fl_button(int x, int y, int w, int h, const char *l);	//x_pos y_pos set to 0 by default

};



#endif //_UserInterface_H_INCLUDED_
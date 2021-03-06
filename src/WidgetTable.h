#ifndef _WidgetTable_H_INCLUDED_
#define _WidgetTable_H_INCLUDED_

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


class MikeSimulator;
class UserInterface;

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
	
	void printInTable(int row, int col, std::string text);	//row = 0 is first row!
	Fl_Widget * GetElement(int nRow, int nCol);	//returns a pointer to the cell in the table at nRow nCol
	void SetSize(int newrows, int newcols, WidgetTable * mytable);	//fills the table with cells:
	void WidgetTable::PopPriceCol(/*WidgetTable * myTable*/); //populates the Price column with prices based on current TopRowPrice

	//GETTERS:
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
	inline int GetTopRowPrice() { return TopRowPrice; }
	inline void SetTopRowPrice(int value) { TopRowPrice = value; }

private:
	//members:
	int table_rows, table_cols;
	int ButtonColsNumber;	//how many columns are buttons?
	int TopRowPrice;		//the price at the first row on top - used to determine which positions to display
	UserInterface * ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	MikeSimulator * mikesimulator;

	//helper functions:
	UserInterface * GetUserInterface()
	{
		return	ptr_to_UserInterface;	//stores a pointer to window in which table is constructed. null at first. has to be set from outside.
	}
	void ColHeaderText(char * s, int C);	//defines text of column headers
	MikeSimulator * GetMikeSim();	//returns pointer to mikesimulator
	inline void SetRows(int numRows)
	{
		table_rows = numRows;
	}
	inline void SetCols(int numCol)
	{
		table_cols = numCol;
	}

	//callbacks:
	static void button_cb(Fl_Widget *w, void * p);	//callbacks in fltk have to be static
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


#endif //_WidgetTable_H_INCLUDED_
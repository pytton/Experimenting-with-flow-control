#include "Control.h"
#include <iostream>
#include "MikeSimulator.h"
#include "Data.h"
#include "Display.h"

Control::Control(MikeSimulator * p)
{
	ptr_to_mikesimulator = p;
}



//void Control::tryout1()
//{
//	std::cout << "\nprinted from Control Class\n";
//}

void Control::MainLoop()
{
	//TODO: work on 1 and 2 first

	//1 check prices	-- this is done by manual up/down now

	//2 check fills
	//2a check/print current position, profit/loss, etc
	//3 make decisions	-- now just manual orders
	//4 display results/decisions
	printCurrentAll();
	//add other functions as needed
	//5 send orders		-- for algos - nothing now



}

void Control::printCurrentAll()
{
	Data * myData = ptr_to_mikesimulator->GetData();
	Display * myDisplay = ptr_to_mikesimulator->GetDisplay();

	long bid_price = ptr_to_mikesimulator->GetData()->GetBidPrice();
	long ask_price = ptr_to_mikesimulator->GetData()->GetAskPrice();
	//std::stringstream buffer;
	//buffer << bid_price;
	//std::cout << buffer.str();
	//buffer.str("newstring");
	//std::cout << buffer.str();
	//std::cout << "\nPrintCurrent All";
	//buffer.str("");
	//buffer << bid_price;

	//print current bid/ask prices inside UserInterface window1:
	ptr_to_mikesimulator->GetDisplay()->GetWindow()->m_curr_bid->value((double)bid_price);
	ptr_to_mikesimulator->GetDisplay()->GetWindow()->m_curr_ask->value((double)ask_price);

	//experimenting:
	using namespace std;
	//	cout << "\nget prices/check fills/make decisions/send orders/print results" << endl;
	//	cout << " " << myDisplay->GetWindow()->m_slider1->value();
	//	string myString;
	//	myString = "BID";
		//myString + bid_price;
		//myString.append();
	//	const char * ch = myString.c_str();
	//	cout << ch[233];	//HACK	- this should not have worked :D

	int TopRowPrice = myDisplay->GetWindow()->GetTable()->GetTopRowPrice();
	//printing BID and ASK in WidgetTable:
	myDisplay->GetWindow()->GetTable()->printInTable(TopRowPrice - bid_price, 6, "BID");
	myDisplay->GetWindow()->GetTable()->printInTable(TopRowPrice - myData->GetPrevBidPrice(), 6, "");
	myDisplay->GetWindow()->GetTable()->printInTable(TopRowPrice - ask_price, 7, "ASK");
	myDisplay->GetWindow()->GetTable()->printInTable(TopRowPrice - myData->GetPrevAskPrice(), 7, "");

//	myDisplay->GetWindow()->GetTable()->PopPriceCol(/*myDisplay->GetWindow()->GetTable()*/);

	//ROW POSITION:
	//determine row which holds the price corresponding to current bid:
	int scrollposition = myDisplay->GetWindow()->GetTable()->GetTopRowPrice() - myData->GetBidPrice();
	//scroll the table to current bid with a 15 row offset:
	myDisplay->GetWindow()->GetTable()->row_position(scrollposition - 15);
}

void Control::ManualOrder(int type, long price) 
{
	using namespace std;

	cout << "\n Manual Order Entered!\n";
	cout << "Price: " << price << "\n Order Type: " << type;

	//enter new order into Data:
//	ptr_to_mikesimulator->GetData()->GetMikeOrder()->NewOrder(type, price);
	//printout the new order in WidgetTable:
//	ptr_to_mikesimulator->GetData()->GetMikeOrder()->PrintOrder();

}
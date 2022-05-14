#include "Write.h"
#include <sstream>

using namespace std;

Write::Write(Point Lcorner, string obj)
{
	OBJ = obj;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void Write::setOBJ(const string& obj)
{
	OBJ = obj;
	UpdateStatementText();
}



void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{
	if (OBJ == "")	//No left handside ==>statement have no valid text yet
		Text = " ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << OBJ;
		Text = T.str();
	}
}
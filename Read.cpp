#include "Read.h"
#include <sstream>

using namespace std;

Read::Read(Point Lcorner, string var)
{
	VAR = var;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void Read::setVAR(const string& var)
{
	VAR = var;
	UpdateStatementText();
}



void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRead(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{
	if (VAR == "")	//No left handside ==>statement have no valid text yet
		Text = " ";
	else
	{
		ostringstream T;
		T << VAR;
		Text = T.str();
	}
}
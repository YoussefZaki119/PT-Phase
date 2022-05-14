#pragma once
#include "Statements/Statement.h"

class End : public Statement
{
private:


	Connector* pConn;	//Start Stat. has one Connector to next statement

	Point  Inlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();


public:
	End(Point Lcorner);
	virtual void Draw(Output* pOut) const;
};


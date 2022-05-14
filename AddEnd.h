#pragma once
#include "Actions/Action.h"
#include "End.h"
class AddEnd : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddEnd(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};


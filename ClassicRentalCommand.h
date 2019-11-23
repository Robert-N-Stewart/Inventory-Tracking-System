// ------------------------------------------------ ClassicRentalCommand.h --------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClassicRentalCommand class

// --------------------------------------------------------------------------------------------------------------------
#ifndef  CLASSICRENTALCOMMAND_H
#define CLASSICRENTALCOMMAND_H

#include "RentalCommand.h"

using namespace std;


class ClassicRentalCommand : public RentalCommand {
public:

	// -------------------------------ClassicRentalCommand Default Constructor----------------------------------------- 
	// Description
	// ClassicRentalCommand: default constructor for the ClassicRentalCommand
	// preconditions: none
	// postconditions: a new ClassicRentalCommand is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	ClassicRentalCommand();

	// -----------------------------------ClassicRentalCommand Constructor--------------------------------------------- 
	// Description
	// ClassicRentalCommand: constructor for the ClassicRentalCommand
	// preconditions: none
	// postconditions: a new ClassicRentalCommand is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	ClassicRentalCommand(char commandType, int clientID, char mediaType, char movieType, int month, int year, string actorFirstName, string actorLastName);

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two ClassicRentalCommands
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	bool operator==(const ClassicRentalCommand&);

	// ---------------------------------------------outputCommand------------------------------------------------------ 
	// Description
	// outputCommand: method to print to console the commandType and movie info
	// preconditions: a ClassicRentalCommand exists
	// postconditions: returns the commandType and movie info
	// ----------------------------------------------------------------------------------------------------------------
	void outputCommand();

	// ---------------------------------------------getYear------------------------------------------------------------ 
	// Description
	// getMonth: method to return the year a classic movie was released
	// preconditions: a ClassicRentalCommand exists
	// postconditions: returns the year a classic movie was released
	// ----------------------------------------------------------------------------------------------------------------
	int getYear();

	// ---------------------------------------------getMonth----------------------------------------------------------- 
	// Description
	// getMonth: method to return the month a classic movie was released
	// preconditions: a ClassicRentalCommand exists
	// postconditions: returns the month a classic movie was released
	// ----------------------------------------------------------------------------------------------------------------
	int getMonth();

	// ---------------------------------------------getActorsFirstName------------------------------------------------- 
	// Description
	// getActorsFirstName: method to return an actor's first name
	// preconditions: an actor exists
	// postconditions: actor's first name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getActorFirstName() const;

	// ---------------------------------------------getActorsLastName-------------------------------------------------- 
	// Description
	// getActorsLastName: method to return an actor's last name
	// preconditions: an actor exists
	// postconditions: actor's last name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getActorLastName() const;

private:
	string actorFirstName;		//field for actors first name
	string actorLastName;		//field for actors last name
	int year;		//field for classic movies year
	int month;		//field for classic movies month
};

#endif

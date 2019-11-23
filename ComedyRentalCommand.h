// ------------------------------------------------ ComedyRentalCommand.h ---------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ComedyRentalCommand class

// --------------------------------------------------------------------------------------------------------------------

#ifndef COMEDYRENTALCOMMAND_H
#define COMEDYRENTALCOMMAND_H

#include "RentalCommand.h"

using namespace std;

class ComedyRentalCommand : public RentalCommand {

public:

	// -------------------------------ComedyRentalCommand Default Constructor------------------------------------------ 
	// Description
	// ComedyRentalCommand: default constructor for the ClassicRentalCommand
	// preconditions: none
	// postconditions: a new ComedyRentalCommand is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	ComedyRentalCommand();

	// -----------------------------------ComedyRentalCommand Constructor---------------------------------------------- 
	// Description
	// ComedyRentalCommand: constructor for the ComedyRentalCommand
	// preconditions: none
	// postconditions: a new ComedyRentalCommand is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	ComedyRentalCommand(char, int, char, char, string, int);

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two ComedyRentalCommand
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	bool operator==(const ComedyRentalCommand&);

	// ---------------------------------------------outputCommand------------------------------------------------------ 
	// Description
	// outputCommand: method to print to console the commandType and movie info
	// preconditions: a ComedyRentalCommand exists
	// postconditions: returns the commandType and movie info
	// ----------------------------------------------------------------------------------------------------------------
	void outputCommand();


	// ---------------------------------------------getTitle----------------------------------------------------------- 
	// Description
	// getTitle: method to return the year a comedy movie was released
	// preconditions: a ComedyRentalCommand exists
	// postconditions: returns the year a comedy movie was released
	// ----------------------------------------------------------------------------------------------------------------
	string getTitle() const;

	// ---------------------------------------------getYear------------------------------------------------------------ 
	// Description
	// getMonth: method to return the year a comedy movie was released
	// preconditions: a ComedyRentalCommand exists
	// postconditions: returns the year a comedy movie was released
	// ----------------------------------------------------------------------------------------------------------------
	int getYear() const;

private:
	string title;
	int year;
};

#endif

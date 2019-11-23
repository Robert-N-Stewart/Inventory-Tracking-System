// ------------------------------------------------ DramaRentalCommand.h ----------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the DramaRentalCommand class

// --------------------------------------------------------------------------------------------------------------------

#ifndef DRAMARENTALCOMMAND_H
#define DRAMARENTALCOMMAND_H

#include "RentalCommand.h"

using namespace std;

class DramaRentalCommand : public RentalCommand {
public:


	// -------------------------------DramaRentalCommand Default Constructor------------------------------------------- 
	// Description
	// DramaRentalCommand: default constructor for the DramaRentalCommand
	// preconditions: none
	// postconditions: a new DramaRentalCommand is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	DramaRentalCommand();


	// -----------------------------------DramaRentalCommand Constructor----------------------------------------------- 
	// Description
	// DramaRentalCommand: constructor for the DramaRentalCommand
	// preconditions: none
	// postconditions: a new DramaRentalCommand is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	DramaRentalCommand(char, int, char, char, string, string);

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two DramaRentalCommand
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	bool operator==(const DramaRentalCommand&);


	// ---------------------------------------------outputCommand------------------------------------------------------ 
	// Description
	// outputCommand: method to print to console the commandType and movie info
	// preconditions: a DramaRentalCommand exists
	// postconditions: returns the commandType and movie info
	// ----------------------------------------------------------------------------------------------------------------
	void outputCommand();


	// ---------------------------------------------getTitle----------------------------------------------------------- 
	// Description
	// getTitle: method to return the year a comedy movie was released
	// preconditions: a DramaRentalCommand exists
	// postconditions: returns the year a comedy movie was released
	// ----------------------------------------------------------------------------------------------------------------
	string getTitle() const;

	// ---------------------------------------------getDirector-------------------------------------------------------- 
	// Description
	// getDirector: method to return the director of a drama movie
	// preconditions: a DramaRentalCommand exists
	// postconditions: returns the director of a drama movie
	// ----------------------------------------------------------------------------------------------------------------
	string getDirector() const;

private:
	string title;
	string director;

};


#endif 

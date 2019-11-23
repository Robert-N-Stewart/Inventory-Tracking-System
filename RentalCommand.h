// ------------------------------------------------- RentalCommand.h --------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the RentalCommand class

// --------------------------------------------------------------------------------------------------------------------

#ifndef RENTALCOMMAND_H
#define RENTALCOMMAND_H

#include <iostream>
#include <string>


using namespace std;

class RentalCommand {

public:

	// -----------------------------------RentalCommand Default Constructor--------------------------------------------- 
	// Description
	// DramaRentalCommand: default constructor for the RentalCommand
	// preconditions: none
	// postconditions: a new RentalCommand is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	RentalCommand();

	// -------------------------------------RentalCommand Constructor-------------------------------------------------- 
	// Description
	// RentalCommand: constructor for the RentalCommand
	// preconditions: none
	// postconditions: a new RentalCommand is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	RentalCommand(char, int, char, char);

	// ---------------------------------------------getCommandType----------------------------------------------------- 
	// Description
	// getCommandType: method to return the commandType associated with the movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the commandType associated with the movie
	// ----------------------------------------------------------------------------------------------------------------
	char getCommandType() const;

	// ---------------------------------------------getMediaType------------------------------------------------------- 
	// Description
	// getMediaType: method to return the media type of a movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the media type of a movie
	// ----------------------------------------------------------------------------------------------------------------
	char getMediaType()const;

	// ---------------------------------------------getMovieType------------------------------------------------------- 
	// Description
	// getMovieType: method to return the type of movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the type of movie
	// ----------------------------------------------------------------------------------------------------------------
	char getMovieType() const;

	// ---------------------------------------------getClientID-------------------------------------------------------- 
	// Description
	// getClientID: method to return the client's ID
	// preconditions: a RentalCommand exists
	// postconditions: returns the client's ID
	// ----------------------------------------------------------------------------------------------------------------
	int getClientID() const;

	// ---------------------------------------------outputCommand------------------------------------------------------ 
	// Description
	// outputCommand: method to call the child and run the outputCommand
	// preconditions: a DramaRentalCommand exists
	// postconditions: returns the commandType and movie info
	// ----------------------------------------------------------------------------------------------------------------
	virtual void outputCommand() = 0;

protected:
	char commandType;
	char mediaType;
	char movieType;
	int clientID;

};

#endif 






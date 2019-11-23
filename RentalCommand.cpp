// ------------------------------------------------- RentalCommand.h --------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the RentalCommand class

// --------------------------------------------------------------------------------------------------------------------
#include "RentalCommand.h"

	// -----------------------------------RentalCommand Default Constructor--------------------------------------------- 
	// Description
	// DramaRentalCommand: default constructor for the RentalCommand
	// preconditions: none
	// postconditions: a new RentalCommand is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
RentalCommand::RentalCommand()
{
	this->commandType = ' ';
	this->clientID = -1;
	this->mediaType = ' ';
	this->movieType = ' ';
}

	// -------------------------------------RentalCommand Constructor-------------------------------------------------- 
	// Description
	// RentalCommand: constructor for the RentalCommand
	// preconditions: none
	// postconditions: a new RentalCommand is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
RentalCommand::RentalCommand(char commandType, int clientID, char mediaType, char movieType)
{
	this->commandType = commandType;
	this->clientID = clientID;
	this->mediaType = mediaType;
	this->movieType = movieType;
}

	// ---------------------------------------------getCommandType----------------------------------------------------- 
	// Description
	// getCommandType: method to return the commandType associated with the movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the commandType associated with the movie
	// ----------------------------------------------------------------------------------------------------------------
char RentalCommand::getCommandType() const
{
	return commandType;
}


	// ---------------------------------------------getMediaType------------------------------------------------------- 
	// Description
	// getMediaType: method to return the media type of a movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the media type of a movie
	// ----------------------------------------------------------------------------------------------------------------
char RentalCommand::getMediaType() const
{
	return mediaType;
}

	// ---------------------------------------------getMovieType------------------------------------------------------- 
	// Description
	// getMovieType: method to return the type of movie
	// preconditions: a RentalCommand exists
	// postconditions: returns the type of movie
	// ----------------------------------------------------------------------------------------------------------------
char RentalCommand::getMovieType() const
{
	return movieType;
}

	// ---------------------------------------------getClientID-------------------------------------------------------- 
	// Description
	// getClientID: method to return the client's ID
	// preconditions: a RentalCommand exists
	// postconditions: returns the client's ID
	// ----------------------------------------------------------------------------------------------------------------
int RentalCommand::getClientID() const
{
	return clientID;
}

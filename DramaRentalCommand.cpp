// ------------------------------------------------ DramaRentalCommand.h ----------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the DramaRentalCommand class

// --------------------------------------------------------------------------------------------------------------------

#include "DramaRentalCommand.h"

// -------------------------------DramaRentalCommand Default Constructor------------------------------------------- 
// Description
// DramaRentalCommand: default constructor for the DramaRentalCommand
// preconditions: none
// postconditions: a new DramaRentalCommand is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
DramaRentalCommand::DramaRentalCommand()
	:RentalCommand()
{
	this->title = "";
	this->director = "";
}


// -----------------------------------DramaRentalCommand Constructor----------------------------------------------- 
// Description
// DramaRentalCommand: constructor for the DramaRentalCommand
// preconditions: none
// postconditions: a new DramaRentalCommand is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
DramaRentalCommand::DramaRentalCommand(char commandType, int clientID, char mediaType, char movieType, string director, string title)
	: RentalCommand(commandType, clientID, mediaType, movieType)
{
	this->director = director;
	this->title = title;
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two DramaRentalCommand
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ----------------------------------------------------------------------------------------------------------------
bool DramaRentalCommand::operator==(const DramaRentalCommand & other)
{
	return (commandType == other.commandType && clientID == other.clientID && mediaType == other.mediaType && movieType == other.movieType &&  title == other.title && director == other.director);
}

// ---------------------------------------------outputCommand------------------------------------------------------ 
// Description
// outputCommand: method to print to console the commandType and movie info
// preconditions: a DramaRentalCommand exists
// postconditions: returns the commandType and movie info
// ----------------------------------------------------------------------------------------------------------------
void DramaRentalCommand::outputCommand()
{
	cout << commandType << " " << clientID << " " << mediaType << " ";
	cout << movieType << " " << director << ", " << title << endl;
}


// ---------------------------------------------getTitle----------------------------------------------------------- 
// Description
// getTitle: method to return the year a comedy movie was released
// preconditions: a DramaRentalCommand exists
// postconditions: returns the year a comedy movie was released
// ----------------------------------------------------------------------------------------------------------------
string DramaRentalCommand::getTitle() const
{
	return title;
}

// ---------------------------------------------getDirector-------------------------------------------------------- 
// Description
// getDirector: method to return the director of a drama movie
// preconditions: a DramaRentalCommand exists
// postconditions: returns the director of a drama movie
// ----------------------------------------------------------------------------------------------------------------
string DramaRentalCommand::getDirector() const
{
	return director;
}

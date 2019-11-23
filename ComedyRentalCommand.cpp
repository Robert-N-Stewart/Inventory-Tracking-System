// ------------------------------------------------ ComedyRentalCommand.h ---------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ComedyRentalCommand class

// --------------------------------------------------------------------------------------------------------------------

#include "ComedyRentalCommand.h"

// -------------------------------ComedyRentalCommand Default Constructor------------------------------------------ 
// Description
// ComedyRentalCommand: default constructor for the ClassicRentalCommand
// preconditions: none
// postconditions: a new ComedyRentalCommand is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
ComedyRentalCommand::ComedyRentalCommand()
	:RentalCommand()
{
	this->title = "";
	this->year = -1;
}

// -----------------------------------ComedyRentalCommand Constructor---------------------------------------------- 
// Description
// ComedyRentalCommand: constructor for the ComedyRentalCommand
// preconditions: none
// postconditions: a new ComedyRentalCommand is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
ComedyRentalCommand::ComedyRentalCommand(char commandType, int clientID, char mediaType, char movieType, string title, int year)
	: RentalCommand(commandType, clientID, mediaType, movieType)
{
	this->title = title;
	this->year = year;
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two ComedyRentalCommand
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ----------------------------------------------------------------------------------------------------------------
bool ComedyRentalCommand::operator==(const ComedyRentalCommand & other)
{
	return (commandType == other.commandType && clientID == other.clientID && mediaType == other.mediaType && movieType == other.movieType &&  title == other.title && year == other.year);
}

// ---------------------------------------------outputCommand------------------------------------------------------ 
// Description
// outputCommand: method to print to console the commandType and movie info
// preconditions: a ComedyRentalCommand exists
// postconditions: returns the commandType and movie info
// ----------------------------------------------------------------------------------------------------------------
void ComedyRentalCommand::outputCommand()
{
	cout << commandType << " " << clientID << " " << mediaType << " ";
	cout << movieType << " " << title << ", " << year << endl;
}

// ---------------------------------------------getTitle----------------------------------------------------------- 
// Description
// getTitle: method to return the year a comedy movie was released
// preconditions: a ComedyRentalCommand exists
// postconditions: returns the year a comedy movie was released
// ----------------------------------------------------------------------------------------------------------------
string ComedyRentalCommand::getTitle() const
{
	return title;
}

// ---------------------------------------------getYear------------------------------------------------------------ 
// Description
// getMonth: method to return the year a comedy movie was released
// preconditions: a ComedyRentalCommand exists
// postconditions: returns the year a comedy movie was released
// ----------------------------------------------------------------------------------------------------------------
int ComedyRentalCommand::getYear() const
{
	return year;
}


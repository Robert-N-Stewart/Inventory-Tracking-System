#include "ClassicRentalCommand.h"

// -------------------------------ClassicRentalCommand Default Constructor----------------------------------------- 
// Description
// ClassicRentalCommand: default constructor for the ClassicRentalCommand
// preconditions: none
// postconditions: a new ClassicRentalCommand is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
ClassicRentalCommand::ClassicRentalCommand() 
	:RentalCommand()
{
	this->month = -1;
	this->year = -1;
	this->actorFirstName = "";
	this->actorLastName = "";
}

// -----------------------------------ClassicRentalCommand Constructor--------------------------------------------- 
// Description
// ClassicRentalCommand: constructor for the ClassicRentalCommand
// preconditions: none
// postconditions: a new ClassicRentalCommand is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
ClassicRentalCommand::ClassicRentalCommand(char commandType, int clientID, char mediaType, char movieType, int month, int year, string actorFirstName, string actorLastName)
	: RentalCommand(commandType, clientID, mediaType, movieType)
{
	this->month = month;
	this->year = year;
	this->actorFirstName = actorFirstName;
	this->actorLastName = actorLastName;
}


// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two ClassicRentalCommands
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ----------------------------------------------------------------------------------------------------------------
bool ClassicRentalCommand::operator==(const ClassicRentalCommand & other)
{
	return (commandType == other.commandType && clientID == other.clientID && mediaType == other.mediaType && movieType == other.movieType &&  month == other.month && year == other.year
		&& actorFirstName == other.actorFirstName && actorLastName == other.actorLastName);
}

// ---------------------------------------------outputCommand------------------------------------------------------ 
// Description
// outputCommand: method to print to console the commandType and movie info
// preconditions: a ClassicRentalCommand exists
// postconditions: returns the commandType and movie info
// ----------------------------------------------------------------------------------------------------------------
void ClassicRentalCommand::outputCommand()
{
	cout << commandType << " " << clientID << " " << mediaType << " ";
	cout << movieType << " " << month << " " << year << " " << actorFirstName << " " << actorLastName << endl;
}

// ---------------------------------------------getYear------------------------------------------------------------ 
// Description
// getMonth: method to return the year a classic movie was released
// preconditions: a ClassicRentalCommand exists
// postconditions: returns the year a classic movie was released
// ----------------------------------------------------------------------------------------------------------------
int ClassicRentalCommand::getYear()
{
	return year;
}

// ---------------------------------------------getMonth----------------------------------------------------------- 
// Description
// getMonth: method to return the month a classic movie was released
// preconditions: a ClassicRentalCommand exists
// postconditions: returns the month a classic movie was released
// ----------------------------------------------------------------------------------------------------------------
int ClassicRentalCommand::getMonth()
{
	return month;
}

// ---------------------------------------------getActorsFirstName------------------------------------------------- 
// Description
// getActorsFirstName: method to return an actor's first name
// preconditions: an actor exists
// postconditions: actor's first name is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicRentalCommand::getActorFirstName() const
{
	return actorFirstName;
}

// ---------------------------------------------getActorsLastName-------------------------------------------------- 
// Description
// getActorsLastName: method to return an actor's last name
// preconditions: an actor exists
// postconditions: actor's last name is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicRentalCommand::getActorLastName() const
{
	return actorLastName;
}


#include "ActorName.h"

// ------------------------------------ActorName Default Constructor----------------------------------------------- 
// Description
// ActorName: default constructor for the ActorName
// preconditions: none
// postconditions: a new ActorName is created with first name and last name variables empty
// ----------------------------------------------------------------------------------------------------------------
ActorName::ActorName()
{
	firstName = "";
	lastName = "";
}

// -------------------------------------------ActorName  Constructor----------------------------------------------- 
// Description
// ActorName: constructor for the ActorName
// preconditions: none
// postconditions: a new ActorName is created with first name and last name variables included
// ----------------------------------------------------------------------------------------------------------------
ActorName::ActorName(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

// ---------------------------------------------getFirstName------------------------------------------------------- 
// Description
// getFirstName: method to return an actor's first name
// preconditions: an actor exists
// postconditions: actor's first name is returned
// ----------------------------------------------------------------------------------------------------------------
string ActorName::getFirstName() const
{
	return firstName;
}

// ---------------------------------------------getLastName-------------------------------------------------------- 
// Description
// getLastName: method to return an actor's last name
// preconditions: an actor exists
// postconditions: actor's last name is returned
// ----------------------------------------------------------------------------------------------------------------
string ActorName::getLastName() const
{
	return lastName;
}

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print an actor's name
// preconditions: an actor exists
// postconditions: actor's name is printed to console
// ----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const ActorName& actorName)
{
	out << actorName.firstName << " " << actorName.lastName << endl;
	return out;
}

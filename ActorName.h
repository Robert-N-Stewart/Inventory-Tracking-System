// ------------------------------------------------ ActorName.h -------------------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ActorName

// --------------------------------------------------------------------------------------------------------------------

#ifndef ACTORNAME_H
#define ACTORNAME_H

#include <string>
#include <iostream>

using namespace std;

	
class ActorName {
public:
	// ------------------------------------ActorName Default Constructor----------------------------------------------- 
	// Description
	// ActorName: default constructor for the ActorName
	// preconditions: none
	// postconditions: a new ActorName is created with first name and last name variables empty
	// ----------------------------------------------------------------------------------------------------------------
	ActorName();
	
	// -------------------------------------------ActorName  Constructor----------------------------------------------- 
	// Description
	// ActorName: constructor for the ActorName
	// preconditions: none
	// postconditions: a new ActorName is created with first name and last name variables included
	// ----------------------------------------------------------------------------------------------------------------
	ActorName(string, string);
	
	// ---------------------------------------------getFirstName------------------------------------------------------- 
	// Description
	// getFirstName: method to return an actor's first name
	// preconditions: an actor exists
	// postconditions: actor's first name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getFirstName() const;
	
	// ---------------------------------------------getLastName-------------------------------------------------------- 
	// Description
	// getLastName: method to return an actor's last name
	// preconditions: an actor exists
	// postconditions: actor's last name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getLastName() const;

	// ---------------------------------------------operator<<--------------------------------------------------------- 
	// Description
	// operator<<: operator to print an actor's name
	// preconditions: an actor exists
	// postconditions: actor's name is printed to console
	// ----------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& out, const ActorName& actorName);

private:
	string firstName;	//actors first name
	string lastName;	//actors last name

};

#endif

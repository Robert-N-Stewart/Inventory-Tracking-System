// ----------------------------------------------------- Client.h -----------------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the Client class

// --------------------------------------------------------------------------------------------------------------------
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>

#include "RentalCommand.h"
#include "ClassicRentalCommand.h"
#include "ComedyRentalCommand.h"
#include "DramaRentalCommand.h"

using namespace std;

class Client {

public:
	// ---------------------------------------Client Default Constructor----------------------------------------------- 
	// Description
	// Client: default constructor for the Client
	// preconditions: none
	// postconditions: a new Client is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	Client();

	// --------------------------------------------Client Constructor-------------------------------------------------- 
	// Description
	// Client: constructor for the Client
	// preconditions: none
	// postconditions: a new Client is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	Client(int iD, string firstName, string lastName);
	
	// --------------------------------------------Client Deconstructor------------------------------------------------ 
	// Description
	// Client: Deconstructor for the Client
	// preconditions: Client exists
	// postconditions: a Client deleted, then the memory is deallocated
	// ----------------------------------------------------------------------------------------------------------------
	~Client();

	// ---------------------------------------------printHistory------------------------------------------------------ 
	// Description
	// printHistory: method to print to console the Client rental history
	// preconditions: a Client exists
	// postconditions: prints the Client rental history
	// ----------------------------------------------------------------------------------------------------------------
	void printHistory() const;

	// ---------------------------------------------getClientID-------------------------------------------------------- 
	// Description
	// getClientID: method to find and return the Client's ID
	// preconditions: a Client exists
	// postconditions: returns the client's ID
	// ----------------------------------------------------------------------------------------------------------------
	int getClientID() const;
	
	// ------------------------------------------------getFirstName---------------------------------------------------- 
	// Description
	// getFirstName: method to return the client's first name
	// preconditions: a client exists
	// postconditions: client's first name is returned
	// --------------------------------------------------------------------------------------------------------------
	string getFirstName() const;
	
	// ------------------------------------------------getLastName----------------------------------------------------- 
	// Description
	// getLastName: method to return the client's last name
	// preconditions: a client exists
	// postconditions: client's last name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getLastName() const;
	
	// -----------------------------------------------getHistory------------------------------------------------------- 
	// Description
	// getHistory: method to find all of a client's rental history
	// preconditions: none
	// postconditions: all the movies a client has rented is returned in a vector

	// ----------------------------------------------------------------------------------------------------------------
	vector<RentalCommand*>getHistory() const;
	
	// -----------------------------------------------validateReturn--------------------------------------------------- 
	// Description
	// validateReturn: method to find if a client has returned a movie previously borrowed
	// preconditions: client exists
	// postconditions: returns true or false depending is a client has returned a movie previously borrowed
	// ----------------------------------------------------------------------------------------------------------------
	bool validateReturn(RentalCommand*);
	
	// -----------------------------------------------addToHistory----------------------------------------------------- 
	// Description
	// addToHistory: method to add to a client's history that the client rented a this movie
	// preconditions: client exists
	// postconditions: adds a movie to the list of the client's rented movies
	// ----------------------------------------------------------------------------------------------------------------
	void addToHistory(RentalCommand*);


private:
	int iD;		//field for client id
	string firstName;		//field for client first name
	string lastName;		//field for client last name
	vector<RentalCommand*> history;		// field for client command history

};

#endif 

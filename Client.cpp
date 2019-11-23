// ----------------------------------------------------- Client.h -----------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the Client class

// --------------------------------------------------------------------------------------------------------------------
#include "Client.h"

// ---------------------------------------Client Default Constructor----------------------------------------------- 
// Description
// Client: default constructor for the Client
// preconditions: none
// postconditions: a new Client is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
Client::Client()
{
	iD = -1;
	firstName = "";
	lastName = "";

}

// --------------------------------------------Client Constructor-------------------------------------------------- 
// Description
// Client: constructor for the Client
// preconditions: none
// postconditions: a new Client is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
Client::Client(int iD, string firstName, string lastName)
{
	this->iD = iD;
	this->firstName = firstName;
	this->lastName = lastName;

}

// --------------------------------------------Client Deconstructor------------------------------------------------ 
// Description
// Client: Deconstructor for the Client
// preconditions: Client exists
// postconditions: a Client deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
Client::~Client()
{
	for (int i = 0; i < history.size(); i++) {
		delete history.at(i);
		history.at(i) = NULL;
	}
	history.clear();
}

// ---------------------------------------------printHistory------------------------------------------------------ 
// Description
// printHistory: method to print to console the Client rental history
// preconditions: a Client exists
// postconditions: prints the Client rental history
// ----------------------------------------------------------------------------------------------------------------
void Client::printHistory() const
{
	cout << "Client " << this->iD << " history:" << endl;
	for (int i = history.size() - 1; i >= 0; i--) {
		history[i]->outputCommand();
	}
}

// ---------------------------------------------getClientID-------------------------------------------------------- 
// Description
// getClientID: method to find and return the Client's ID
// preconditions: a Client exists
// postconditions: returns the client's ID
// ----------------------------------------------------------------------------------------------------------------
int Client::getClientID() const
{
	return iD;
}

// ------------------------------------------------getFirstName---------------------------------------------------- 
// Description
// getFirstName: method to return the client's first name
// preconditions: a client exists
// postconditions: client's first name is returned
// --------------------------------------------------------------------------------------------------------------
string Client::getFirstName() const
{
	return firstName;
}

// ------------------------------------------------getLastName----------------------------------------------------- 
// Description
// getLastName: method to return the client's last name
// preconditions: a client exists
// postconditions: client's last name is returned
// ----------------------------------------------------------------------------------------------------------------
string Client::getLastName() const
{
	return lastName;
}

// -----------------------------------------------getHistory------------------------------------------------------- 
// Description
// getHistory: method to find all of a client's rental history
// preconditions: none
// postconditions: all the movies a client has rented is returned in a vector

// ----------------------------------------------------------------------------------------------------------------
vector<RentalCommand*> Client::getHistory() const
{
	return history;
}

	
// -----------------------------------------------validateReturn--------------------------------------------------- 
// Description
// validateReturn: method to find if a client has returned a movie previously borrowed
// preconditions: client exists
// postconditions: returns true or false depending is a client has returned a movie previously borrowed
// ----------------------------------------------------------------------------------------------------------------
bool Client::validateReturn(RentalCommand * returnCommand)
{
	//attempts to validate the return based on the movie type of the rental command
	if (returnCommand->getMovieType() == 'C') {
		//cast the retnal command to classic rental command
		ClassicRentalCommand* classicReturnCommand = static_cast<ClassicRentalCommand*>(returnCommand);
		//creates a temporary borrow rental command for searching for borrow
		ClassicRentalCommand* borrowCommand = new ClassicRentalCommand('B', returnCommand->getClientID(), returnCommand->getMediaType(),
			returnCommand->getMovieType(), classicReturnCommand->getMonth(), classicReturnCommand->getYear(), classicReturnCommand->getActorFirstName(),
			classicReturnCommand->getActorLastName());

		//for all of the clients history attempt to find the borrow
		for (int i = 0; i < history.size(); i++) {
			//if current rental command is of type classic only compare
			if (history.at(i)->getMovieType() == 'C' && *(static_cast<ClassicRentalCommand*>(history.at(i))) == *borrowCommand) {
				delete borrowCommand;
				borrowCommand = NULL;
				return true;
			}
		}

		//if the borrow command is not found in the client's history then the return is not valid
		delete borrowCommand;
		borrowCommand = NULL;
		return false;

	}
	else if (returnCommand->getMovieType() == 'D') {
		//cast the retnal command to drama rental command
		DramaRentalCommand* dramaReturnCommand = static_cast<DramaRentalCommand*>(returnCommand);
		//creates a temporary borrow rental command for searching for borrow
		DramaRentalCommand* borrowCommand = new DramaRentalCommand('B', returnCommand->getClientID(), returnCommand->getMediaType(),
			returnCommand->getMovieType(), dramaReturnCommand->getDirector(), dramaReturnCommand->getTitle());
		
		//for all of the clients history attempt to find the borrow
		for (int i = 0; i < history.size(); i++) {
			if (history.at(i)->getMovieType() == 'D' && *(static_cast<DramaRentalCommand*>(history.at(i))) == *borrowCommand) {
				delete borrowCommand;
				borrowCommand = NULL;
				return true;
			}
		}
		//if the borrow command is not found in the client's history then the return is not valid
		delete borrowCommand;
		borrowCommand = NULL;
		return false;
	}
	else {
		//cast the retnal command to comedy rental command
		ComedyRentalCommand* comedyReturnCommand = static_cast<ComedyRentalCommand*>(returnCommand);
		//creates a temporary borrow rental command for searching for borrow
		ComedyRentalCommand* borrowCommand = new ComedyRentalCommand('B', returnCommand->getClientID(), returnCommand->getMediaType(),
			returnCommand->getMovieType(), comedyReturnCommand->getTitle(), comedyReturnCommand->getYear());
		
		//for all of the clients history attempt to find the borrow
		for (int i = 0; i < history.size(); i++) {
			if (history.at(i)->getMovieType() == 'F' && *(static_cast<ComedyRentalCommand*>(history.at(i))) == *borrowCommand) {
				delete borrowCommand;
				borrowCommand = NULL;
				return true;
			}
		}

		//if the borrow command is not found in the client's history then the return is not valid
		delete borrowCommand;
		borrowCommand = NULL;
		return false;
	}
	
}

// -----------------------------------------------addToHistory----------------------------------------------------- 
// Description
// addToHistory: method to add to a client's history that the client rented a this movie
// preconditions: client exists
// postconditions: adds a movie to the list of the client's rented movies
// ----------------------------------------------------------------------------------------------------------------
void Client::addToHistory(RentalCommand * rentalCommandToAdd)
{
	//adds the rental command to the back of the clients history
	history.push_back(rentalCommandToAdd);
}


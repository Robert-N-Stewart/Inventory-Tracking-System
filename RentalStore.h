// ------------------------------------------------- RentalStore.h ----------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the RentalStore class

// --------------------------------------------------------------------------------------------------------------------
#ifndef RENTALSTORE_H
#define RENTALSTORE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

#include "ClientHashMap.h"
#include "MovieBST.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicRentalCommand.h"
#include "ComedyRentalCommand.h"
#include "DramaRentalCommand.h"
#include "ClassicActorList.h"


using namespace std;

class RentalStore {

public:


	// -------------------------------------RentalStore Default Constructor--------------------------------------------- 
	// Description
	// RentalStore: default constructor for the RentalStore
	// preconditions: none
	// postconditions: a new RentalStore is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	RentalStore();

	// --------------------------------------------RentalStore Deconstructor------------------------------------------- 
	// Description
	// RentalStore: Deconstructor for the RentalStore
	// preconditions: RentalStore exists
	// postconditions: a RentalStore deleted, then the memory is deallocated
	// ----------------------------------------------------------------------------------------------------------------
	~RentalStore();

	// -------------------------------------------------buildClients--------------------------------------------------- 
	// Description
	// buildClients: a method that reads from a file to input all the clients
	// preconditions: RentalStore exists
	// postconditions: clients are read from a file and inserted into the system
	// ----------------------------------------------------------------------------------------------------------------
	void buildClients(ifstream&);

	// -------------------------------------------------buildStock----------------------------------------------------- 
	// Description
	// buildStock: a method that reads from a file to input all the stock
	// preconditions: RentalStore exists
	// postconditions: stock is read from a file and inserted into the system
	// ----------------------------------------------------------------------------------------------------------------
	void buildStock(ifstream&);

	// -------------------------------------------------buildCommands-------------------------------------------------- 
	// Description
	// buildCommands: a method that reads from a file to input all the commands
	// preconditions: RentalStore exists
	// postconditions: commands are read from a file and inserted into the system
	// ----------------------------------------------------------------------------------------------------------------
	void loadCommands(ifstream&);

private:

	ClientHashMap* clients;		//field to store all of the clients in a hash map
	MovieBST<ClassicMovie>* classicMovieStorage;		// field to store all of the classic movies 
	MovieBST<DramaMovie>* dramaMovieStorage;		//field to store all of the drama movies
	MovieBST<ComedyMovie>* comedyMovieStorage;		//field to store all of the comedy movies

	MovieBST<ClassicActorsList>* classicMovieActors;		//field to store all of the actors names for classical movies

	// -------------------------------------------------processReturnOrBorrow-------------------------------------------------- 
	// Description
	// buildCommands: processes borrow and return commands
	// preconditions: RentalStore exists
	// postconditions: borrow and return commands are processed
	// ----------------------------------------------------------------------------------------------------------------
	bool processReturnOrBorrow(string);	
	

};

#endif


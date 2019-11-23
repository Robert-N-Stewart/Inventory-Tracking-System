// ----------------------------------------------------- ClientHashMap.h -----------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClientHashMap class

// --------------------------------------------------------------------------------------------------------------------
#ifndef CLIENTHASHMAP_H
#define CLIENTHASHMAP_H

#include "Client.h"

using namespace std;

class ClientHashMap {
public:

	// -----------------------------------ClientHashMap Default Constructor-------------------------------------------- 
	// Description
	// ClientHashMap: default constructor for the ClientHashMap
	// preconditions: none
	// postconditions: a new ClientHashMap is created
	// ----------------------------------------------------------------------------------------------------------------
	ClientHashMap();


	// ----------------------------------------ClientHashMap Deconstructor--------------------------------------------- 
	// Description
	// ClientHashMap: Deconstructor for the ClientHashMap
	// preconditions: ClientHashMap exists
	// postconditions: a ClientHashMap is deleted, then the memory is deallocated
	// ----------------------------------------------------------------------------------------------------------------
	~ClientHashMap();


	// -----------------------------------------------insert----------------------------------------------------------- 
	// Description
	// insert: method to insert a new client into the client hashmap
	// preconditions: a ClientHashMap exists
	// postconditions: a new client is added to the client hashmap
	// ----------------------------------------------------------------------------------------------------------------
	bool insert(Client* client);

	// -----------------------------------------------retrieve--------------------------------------------------------- 
	// Description
	// retrieve: method to retrieve a client from the client hashmap
	// preconditions: a ClientHashMap exists
	// postconditions: a client is retrieve from the client hashmap
	// ----------------------------------------------------------------------------------------------------------------
	Client* retrieve(int clientID);

private:
	Client* clients[10000];		//field for clients array

};
#endif 

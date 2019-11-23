// ----------------------------------------------------- ClientHashMap.h -----------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClientHashMap class

// --------------------------------------------------------------------------------------------------------------------

#include "ClientHashMap.h"

// -----------------------------------ClientHashMap Default Constructor-------------------------------------------- 
// Description
// ClientHashMap: default constructor for the ClientHashMap
// preconditions: none
// postconditions: a new ClientHashMap is created
// ----------------------------------------------------------------------------------------------------------------
ClientHashMap::ClientHashMap()
{
	for (int i = 0; i <= 9999; i++) {
		clients[i] = NULL;
	}
}


// ----------------------------------------ClientHashMap Deconstructor--------------------------------------------- 
// Description
// ClientHashMap: Deconstructor for the ClientHashMap
// preconditions: ClientHashMap exists
// postconditions: a ClientHashMap is deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
ClientHashMap::~ClientHashMap()
{
	for(int i = 0; i < 10000; i++) {
		if(clients[i] != NULL) {		
			delete clients[i];
			clients[i] = NULL;
		}
	}
}

// -----------------------------------------------insert----------------------------------------------------------- 
// Description
// insert: method to insert a new client into the client hashmap
// preconditions: a ClientHashMap exists
// postconditions: a new client is added to the client hashmap
// ----------------------------------------------------------------------------------------------------------------
bool ClientHashMap::insert(Client * clientToInsert)
{
	int toInsert = clientToInsert->getClientID();
	if (clients[toInsert] == NULL) {
		clients[toInsert] = clientToInsert;
		return true;
	}
	else {
		return false;
	}
}

// -----------------------------------------------retrieve--------------------------------------------------------- 
// Description
// retrieve: method to retrieve a client from the client hashmap
// preconditions: a ClientHashMap exists
// postconditions: a client is retrieve from the client hashmap

// ----------------------------------------------------------------------------------------------------------------
Client * ClientHashMap::retrieve(int clientID)
{
	return clients[clientID];
}

#ifndef CLASSICACTORSLIST_H
#define CLASSICACTORSLIST_H


#include <iostream>
#include <vector>
#include <string>
#include "ActorName.h"

using namespace std;

class ClassicActorsList {

public:
// ------------------------------------ClassicActorList Default Constructor---------------------------------------- 
// Description
// ClassicActorList: default constructor for the ClassicActorList
// preconditions: none
// postconditions: a new ClassicActorList is created with title, director, year and month variables empty
// ----------------------------------------------------------------------------------------------------------------
	ClassicActorsList();
// ---------------------------------------ClassicActorList Constructor--------------------------------------------- 
// Description
// ClassicActorList: constructor for the ClassicActorList
// preconditions: none
// postconditions: a new ClassicActorList is created with title, director, year and month variables filled
// ----------------------------------------------------------------------------------------------------------------
	ClassicActorsList(string, string, int, int);
// -------------------------------------ClassicActorList Deconstructor--------------------------------------------- 
// Description
// ClassicActorList: Deconstructor for the ClassicActorList
// preconditions: ClassicActorList exists
// postconditions: a ClassicActorList deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
	~ClassicActorsList();

// -----------------------------------------------addActor--------------------------------------------------------- 
// Description
// addActor: an actor is added to the ClassicActorList
// preconditions: none
// postconditions: a new actor with first and last name is added to the ClassicActorsList
// ----------------------------------------------------------------------------------------------------------------
	void addActor(string, string);
// -----------------------------------------------getTitle--------------------------------------------------------- 
// Description
// getTitle: method to find the title of a movie
// preconditions: none
// postconditions: a movie title is returned
// ----------------------------------------------------------------------------------------------------------------
	string getTitle() const;

// -----------------------------------------------getDirector------------------------------------------------------ 
// Description
// getDirector: method to find the director of a movie
// preconditions: none
// postconditions: a movie director is returned
// ----------------------------------------------------------------------------------------------------------------
	string getDirector() const;

// -----------------------------------------------getYear---------------------------------------------------------- 
// Description
// getYear: method to find the year a movie was released
// preconditions: none
// postconditions: the movie year is returned
// ----------------------------------------------------------------------------------------------------------------
	int getYear() const;
// -----------------------------------------------getMonth--------------------------------------------------------- 
// Description
// getMonth: method to find the month a movie was released
// preconditions: none
// postconditions: the movie month is returned
// ----------------------------------------------------------------------------------------------------------------
	int getMonth() const;

// -----------------------------------------------getActors-------------------------------------------------------- 
// Description
// getActors: method to find all the actors in a classic movie
// preconditions: none
// postconditions: all the actors in a movie are returned in a vector
// ----------------------------------------------------------------------------------------------------------------
	vector<ActorName*>* getActors() const;

// -----------------------------------------------operator>-------------------------------------------------------- 
// Description
// operator>: method to compare two actors alphabetically
// preconditions: none
// postconditions: compares two actors alphabetically

// ----------------------------------------------------------------------------------------------------------------
	bool operator>(const ClassicActorsList &other) const;

// -----------------------------------------------operator<-------------------------------------------------------- 
// Description
// operator<: method to compare two actors alphabetically
// preconditions: none
// postconditions: compares two actors alphabetically

// ----------------------------------------------------------------------------------------------------------------
	bool operator<(const ClassicActorsList &other) const;

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two actors alphabetically
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent

// ----------------------------------------------------------------------------------------------------------------
	bool operator==(const ClassicActorsList &other) const;

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print the actors
// preconditions: a ClassicActorsList exists
// postconditions: actors are printed to console
// ----------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& out, const ClassicActorsList& classicActorsList);

private:
	string title;
	string director;
	int year;
	int month;
	vector<ActorName*>* actorsList;

};

#endif

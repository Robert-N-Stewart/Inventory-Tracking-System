// ------------------------------------------------ ClassicActorList.h -------------------------------------------------------

// Robert Stewart 
// // 

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClassicActorList

// --------------------------------------------------------------------------------------------------------------------
#include "ClassicActorList.h"

// ------------------------------------ClassicActorList Default Constructor---------------------------------------- 
// Description
// ClassicActorList: default constructor for the ClassicActorList
// preconditions: none
// postconditions: a new ClassicActorList is created with title, director, year and month variables empty
// ----------------------------------------------------------------------------------------------------------------
ClassicActorsList::ClassicActorsList()
{
	this->title = "";
	this->director = "";
	this->month = -1;
	this->year = -1;
	actorsList = new vector<ActorName*>();
}

// ---------------------------------------ClassicActorList Constructor--------------------------------------------- 
// Description
// ClassicActorList: constructor for the ClassicActorList
// preconditions: none
// postconditions: a new ClassicActorList is created with title, director, year and month variables filled
// ----------------------------------------------------------------------------------------------------------------
ClassicActorsList::ClassicActorsList(string title, string director, int month, int year)
{
	this->title = title;
	this->director = director;
	this->month = month;
	this->year = year;
	actorsList = new vector<ActorName*>();

}

// -------------------------------------ClassicActorList Deconstructor--------------------------------------------- 
// Description
// ClassicActorList: Deconstructor for the ClassicActorList
// preconditions: ClassicActorList exists
// postconditions: a ClassicActorList deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
ClassicActorsList::~ClassicActorsList()
{
	for (int i = 0; i < actorsList->size(); i++) {
		delete actorsList->at(i);
		actorsList->at(i) = NULL;
	}
	actorsList->clear();
	delete actorsList;
	actorsList = NULL;
}

// -----------------------------------------------addActor--------------------------------------------------------- 
// Description
// addActor: an actor is added to the ClassicActorList
// preconditions: none
// postconditions: a new actor with first and last name is added to the ClassicActorsList
// ----------------------------------------------------------------------------------------------------------------
void ClassicActorsList::addActor(string firstName, string lastName)
{
	ActorName* actorNameToAdd = new ActorName(firstName, lastName);
	actorsList->push_back(actorNameToAdd);
}

// -----------------------------------------------getTitle--------------------------------------------------------- 
// Description
// getTitle: method to find the title of a movie
// preconditions: none
// postconditions: a movie title is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicActorsList::getTitle() const
{
	return title;
}

// -----------------------------------------------getDirector------------------------------------------------------ 
// Description
// getDirector: method to find the director of a movie
// preconditions: none
// postconditions: a movie director is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicActorsList::getDirector() const
{
	return director;
}

// -----------------------------------------------getYear---------------------------------------------------------- 
// Description
// getYear: method to find the year a movie was released
// preconditions: none
// postconditions: the movie year is returned
// ----------------------------------------------------------------------------------------------------------------
int ClassicActorsList::getYear() const
{
	return year;
}

// -----------------------------------------------getMonth--------------------------------------------------------- 
// Description
// getMonth: method to find the month a movie was released
// preconditions: none
// postconditions: the movie month is returned
// ----------------------------------------------------------------------------------------------------------------
int ClassicActorsList::getMonth() const
{
	return month;
}

// -----------------------------------------------getActors-------------------------------------------------------- 
// Description
// getActors: method to find all the actors in a classic movie
// preconditions: none
// postconditions: all the actors in a movie are returned in a vector
// ----------------------------------------------------------------------------------------------------------------
vector<ActorName*>* ClassicActorsList::getActors() const
{
	return actorsList;
}

bool ClassicActorsList::operator>(const ClassicActorsList & other) const
{
	if (this->year > other.year) {
		return true;
	} else if (this->year < other.year) {
		return false;
	}
	else if (this->month > other.month) {
		return true;
	} else if(this->month < other.month) {
		return false;
	} else if(this->director > other.director){
		return true;
	}
	else if(this->director < other.director){
		return false;
	}
	else if (this->title > other.title) {
		return true;
	}
	else if (this->title < other.title) {
		return false;
	}
	else {
		return false;
	}
}

// -----------------------------------------------operator<-------------------------------------------------------- 
// Description
// operator<: method to compare two actors alphabetically
// preconditions: none
// postconditions: compares two actors alphabetically

// ----------------------------------------------------------------------------------------------------------------
bool ClassicActorsList::operator<(const ClassicActorsList & other) const
{
	return !(this->operator>(other));
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two actors alphabetically
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent

// ----------------------------------------------------------------------------------------------------------------
bool ClassicActorsList::operator==(const ClassicActorsList & other) const
{
	return (this->year == other.year && this->month == other.month 
		&& this->director == other.director && this->title == other.title);
}

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print the actors
// preconditions: a ClassicActorsList exists
// postconditions: actors are printed to console
// ----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const ClassicActorsList & classicActorsList)
{
	for (int i = 0; i < classicActorsList.actorsList->size(); i++) {
		out << classicActorsList.actorsList->at(i);
	}
	return out;
}

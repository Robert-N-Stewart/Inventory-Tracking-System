// ------------------------------------------------ ClassicMovie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClassicMovie class

// --------------------------------------------------------------------------------------------------------------------
#include "ClassicMovie.h"

// ------------------------------------ClassicMovie Default Constructor-------------------------------------------- 
// Description
// ClassicMovie: default constructor for the ClassicMovie
// preconditions: none
// postconditions: a new ClassicMovie is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
ClassicMovie::ClassicMovie() : Movie()
{
	this->actorsFirstName = "";
	this->actorsLastName = "";
	this->month = -1;

}

// ------------------------------------ClassicMovie Constructor---------------------------------------------------- 
// Description
// ClassicMovie: constructor for the ClassicMovie
// preconditions: none
// postconditions: a new ClassicMovie is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
ClassicMovie::ClassicMovie(int stock, string director, string title, string actorsFirstName, string actorsLastName, int month, int year)
	: Movie('C', stock, director, title, year)
{
	this->actorsFirstName = actorsFirstName;
	this->actorsLastName = actorsLastName;
	this->month = month;

}

// ------------------------------------------printMovie------------------------------------------------------------ 
// Description
// printMovie: method that calls the child method to printMovie
// preconditions: a movie with a type exists
// postconditions: the child printMovie function is called and the movie is printed to the console
// ----------------------------------------------------------------------------------------------------------------
void ClassicMovie::printMovie()
{
	cout << type << ", " << stock << ", " << director << ", " << title << ", ";
	cout << actorsFirstName << " " << actorsLastName << " " << month << " " << year << endl;
}

// -----------------------------------------------operator>-------------------------------------------------------- 
// Description
// operator>: method to compare two ClassicMovies alphabetically
// preconditions: none
// postconditions: compares two ClassicMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator>(const ClassicMovie & other) const
{
	if (this->year > other.year) {
		return true;
	}
	else if (this->year < other.year) {
		return false;
	} else if(this->month > other.month) {
		return true;
	}
	else if (this->month < other.month) {
		return false;
	}
	else if(this->actorsFirstName > other.actorsFirstName) {
		return true;
	}
	else if (this->actorsFirstName < other.actorsFirstName) {
		return false;
	}
	else if (this->actorsLastName > other.actorsLastName) {
		return true;
	}
	else {
		return false;
	}
}

// -----------------------------------------------operator<-------------------------------------------------------- 
// Description
// operator<: method to compare two ClassicMovies alphabetically
// preconditions: none
// postconditions: compares two ClassicMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator<(const ClassicMovie & other) const
{
	return !(operator>(other));
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two ClassicMovies alphabetically
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ----------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator==(const ClassicMovie & other) const
{
	if (this->year == other.year && this->month == other.month && this->actorsFirstName == other.actorsFirstName
		&& this->actorsLastName == other.actorsLastName) {
		return true;
	}
	else {
		return false;
	}
}

// ---------------------------------------------getMonth----------------------------------------------------------- 
// Description
// getMonth: method to return the month a classic movie was released
// preconditions: a ClassicMovie exists
// postconditions: returns the month a classic movie was released
// ----------------------------------------------------------------------------------------------------------------
int ClassicMovie::getMonth() const
{
	return month;
}

// ---------------------------------------------getActorsFirstName------------------------------------------------- 
// Description
// getActorsFirstName: method to return an actor's first name
// preconditions: an actor exists
// postconditions: actor's first name is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicMovie::getActorsFirstName() const
{
	return actorsFirstName;
}

// ---------------------------------------------getActorsLastName-------------------------------------------------- 
// Description
// getActorsLastName: method to return an actor's last name
// preconditions: an actor exists
// postconditions: actor's last name is returned
// ----------------------------------------------------------------------------------------------------------------
string ClassicMovie::getActorsLastName() const
{
	return actorsLastName;
}

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print the ClassicMovie
// preconditions: a ClassicMovie exists
// postconditions: ClassicMovies are printed to console
// ----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const ClassicMovie & classifMovie)
{
	out << classifMovie.type << ", " << classifMovie.stock << ", " << classifMovie.director << ", " << classifMovie.title << ", ";
	out << classifMovie.actorsFirstName << " " << classifMovie.actorsLastName << " " << classifMovie.month << " " << classifMovie.year;
	return out;
}

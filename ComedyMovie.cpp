// ------------------------------------------------ ComedyMovie.h -------------------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ComedyMovie class

// --------------------------------------------------------------------------------------------------------------------
#include "ComedyMovie.h"


// ------------------------------------ComedyMovie Default Constructor--------------------------------------------- 
// Description
// ComedyMovie: default constructor for the ComedyMovie
// preconditions: none
// postconditions: a new ComedyMovie is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
ComedyMovie::ComedyMovie() : Movie()
{
}

// ------------------------------------ComedyMovie Constructor----------------------------------------------------- 
// Description
// ComedyMovie: constructor for the ComedyMovie
// preconditions: none
// postconditions: a new ComedyMovie is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
ComedyMovie::ComedyMovie(int stock, string director, string title, int year)
	: Movie('F', stock, director, title, year)
{
}

// ------------------------------------------printMovie------------------------------------------------------------ 
// Description
// printMovie: method that calls the child method to printMovie
// preconditions: a movie with a type exists
// postconditions: the child printMovie function is called and the movie is printed to the console
// ----------------------------------------------------------------------------------------------------------------
void ComedyMovie::printMovie()
{
	cout << type << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// -----------------------------------------------operator>-------------------------------------------------------- 
// Description
// operator>: method to compare two ComedyMovies alphabetically
// preconditions: none
// postconditions: compares two ComedyMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator>(const ComedyMovie & other) const
{
	if (this->title > other.title) {
		return true;
	}
	else if (this->title < other.title) {
		return false;
	}
	else if (this->year > other.year) {
		return false;
	}
	else {
		return false;
	}

}

// -----------------------------------------------operator<-------------------------------------------------------- 
// Description
// operator<: method to compare two ComedyMovies alphabetically
// preconditions: none
// postconditions: compares two ComedyMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator<(const ComedyMovie & other) const
{
	return !(operator>(other));
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two ComedyMovies alphabetically
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ---------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator==(const ComedyMovie & other) const
{
	if (this->title == other.title && this->year == other.year) {
		return true;
	}
	else {
		return false;
	}
}

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print the ComedyMovie
// preconditions: a ComedyMovie exists
// postconditions: ComedyMovie are printed to console
// ----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const ComedyMovie & comedyMovie)
{
	out << comedyMovie.type << ", " << comedyMovie.stock << ", " << comedyMovie.director << ", " << comedyMovie.title << ", " << comedyMovie.year;
	return out;
}

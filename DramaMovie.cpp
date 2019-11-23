#include "DramaMovie.h"


// ------------------------------------DramaMovie Default Constructor---------------------------------------------- 
// Description
// DramaMovie: default constructor for the DramaMovie
// preconditions: none
// postconditions: a new DramaMovie is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
DramaMovie::DramaMovie() : Movie()
{
}

// -------------------------------------DramaMovie Constructor----------------------------------------------------- 
// Description
// DramaMovie: constructor for the DramaMovie
// preconditions: none
// postconditions: a new DramaMovie is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
DramaMovie::DramaMovie(int stock, string director, string title, int year)
	: Movie('D', stock, director, title, year)
{
}


// ------------------------------------------printMovie------------------------------------------------------------ 
// Description
// printMovie: method that calls the child method to printMovie
// preconditions: a movie with a type exists
// postconditions: the child printMovie function is called and the movie is printed to the console
// ----------------------------------------------------------------------------------------------------------------
void DramaMovie::printMovie()
{
	cout << type << ", " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// -----------------------------------------------operator>-------------------------------------------------------- 
// Description
// operator>: method to compare two DramaMovies alphabetically
// preconditions: none
// postconditions: compares two DramaMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator>(const DramaMovie & other) const
{
	if (this->director > other.director) {
		return true;
	}
	else if (this->director < other.director) {
		return false;
	}
	else if (this->title > other.title) {
		return true;
	}
	else {
		return false;
	}
}

// -----------------------------------------------operator<-------------------------------------------------------- 
// Description
// operator<: method to compare two DramaMovies alphabetically
// preconditions: none
// postconditions: compares two DramaMovies alphabetically
// ----------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator<(const DramaMovie & other) const
{
	return !(operator>(other));
}

// -----------------------------------------------operator==------------------------------------------------------- 
// Description
// operator==: method to compare two DramaMovie alphabetically
// preconditions: none
// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
// ----------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator==(const DramaMovie & other) const
{
	if (this->director == other.director && this->title == other.title) {
		return true;
	}
	else {
		return false;
	}
}

// ---------------------------------------------operator<<--------------------------------------------------------- 
// Description
// operator<<: operator to print the DramaMovie
// preconditions: a DramaMovie exists
// postconditions: DramaMovie are printed to console
// ----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const DramaMovie & dramaMovie)
{
	out << dramaMovie.type << ", " << dramaMovie.stock << ", " << dramaMovie.director << ", " << dramaMovie.title << ", " << dramaMovie.year;
	return out;
}

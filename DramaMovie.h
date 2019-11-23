// ------------------------------------------------ DramaMovie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the DramaMovie class

// --------------------------------------------------------------------------------------------------------------------

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"


using namespace std;


class DramaMovie : public Movie {
public:

	// ------------------------------------DramaMovie Default Constructor---------------------------------------------- 
	// Description
	// DramaMovie: default constructor for the DramaMovie
	// preconditions: none
	// postconditions: a new DramaMovie is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	DramaMovie();

	// -------------------------------------DramaMovie Constructor----------------------------------------------------- 
	// Description
	// DramaMovie: constructor for the DramaMovie
	// preconditions: none
	// postconditions: a new DramaMovie is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	DramaMovie(int stock, string director, string title, int year);

	// ------------------------------------------printMovie------------------------------------------------------------ 
	// Description
	// printMovie: method that calls the child method to printMovie
	// preconditions: a movie with a type exists
	// postconditions: the child printMovie function is called and the movie is printed to the console
	// ----------------------------------------------------------------------------------------------------------------
	virtual void printMovie();

	// -----------------------------------------------operator>-------------------------------------------------------- 
	// Description
	// operator>: method to compare two DramaMovies alphabetically
	// preconditions: none
	// postconditions: compares two DramaMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator>(const DramaMovie &other) const;

	// -----------------------------------------------operator<-------------------------------------------------------- 
	// Description
	// operator<: method to compare two DramaMovies alphabetically
	// preconditions: none
	// postconditions: compares two DramaMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator<(const DramaMovie &other) const;

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two DramaMovie alphabetically
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator==(const DramaMovie &other) const;

	// ---------------------------------------------operator<<--------------------------------------------------------- 
	// Description
	// operator<<: operator to print the DramaMovie
	// preconditions: a DramaMovie exists
	// postconditions: DramaMovie are printed to console
	// ----------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& out, const DramaMovie& dramaMovie);


};

#endif 

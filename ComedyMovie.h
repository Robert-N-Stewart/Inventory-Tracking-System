// ------------------------------------------------ ComedyMovie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ComedyMovie class

// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H


#include "Movie.h"


class ComedyMovie : public Movie {
public:

	// ------------------------------------ComedyMovie Default Constructor--------------------------------------------- 
	// Description
	// ComedyMovie: default constructor for the ComedyMovie
	// preconditions: none
	// postconditions: a new ComedyMovie is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	ComedyMovie();

	// ------------------------------------ComedyMovie Constructor----------------------------------------------------- 
	// Description
	// ComedyMovie: constructor for the ComedyMovie
	// preconditions: none
	// postconditions: a new ComedyMovie is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	ComedyMovie(int stock, string director, string title, int year);

	// ------------------------------------------printMovie------------------------------------------------------------ 
	// Description
	// printMovie: method that calls the child method to printMovie
	// preconditions: a movie with a type exists
	// postconditions: the child printMovie function is called and the movie is printed to the console
	// ----------------------------------------------------------------------------------------------------------------
	virtual void printMovie();
	
	// -----------------------------------------------operator>-------------------------------------------------------- 

	// Description
	// operator>: method to compare two ComedyMovies alphabetically
	// preconditions: none
	// postconditions: compares two ComedyMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator>(const ComedyMovie &other) const;

	// -----------------------------------------------operator<-------------------------------------------------------- 
	// Description
	// operator<: method to compare two ComedyMovies alphabetically
	// preconditions: none
	// postconditions: compares two ComedyMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator<(const ComedyMovie &other) const;

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two ComedyMovies alphabetically
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator==(const ComedyMovie &other) const;

	// ---------------------------------------------operator<<--------------------------------------------------------- 
	// Description
	// operator<<: operator to print the ComedyMovie
	// preconditions: a ComedyMovie exists
	// postconditions: ComedyMovie are printed to console
	// ----------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& out, const ComedyMovie& comedyMovie);
};

#endif 

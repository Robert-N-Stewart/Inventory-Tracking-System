// ------------------------------------------------ ClassicMovie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the ClassicMovie class

// --------------------------------------------------------------------------------------------------------------------
#ifndef  CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "Movie.h"

class ClassicMovie : public Movie {

public:
	// ------------------------------------ClassicMovie Default Constructor-------------------------------------------- 
	// Description
	// ClassicMovie: default constructor for the ClassicMovie
	// preconditions: none
	// postconditions: a new ClassicMovie is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	ClassicMovie();

	// ------------------------------------ClassicMovie Constructor---------------------------------------------------- 
	// Description
	// ClassicMovie: constructor for the ClassicMovie
	// preconditions: none
	// postconditions: a new ClassicMovie is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	ClassicMovie(int stock, string director, string title, string actorsFirst, string actorsLast, int month, int year);

	// ------------------------------------------printMovie------------------------------------------------------------ 
	// Description
	// printMovie: method that calls the child method to printMovie
	// preconditions: a movie with a type exists
	// postconditions: the child printMovie function is called and the movie is printed to the console
	// ----------------------------------------------------------------------------------------------------------------
	virtual void printMovie();

	// -----------------------------------------------operator>-------------------------------------------------------- 
	// Description
	// operator>: method to compare two ClassicMovies alphabetically
	// preconditions: none
	// postconditions: compares two ClassicMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator>(const ClassicMovie &other) const;

	// -----------------------------------------------operator<-------------------------------------------------------- 
	// Description
	// operator<: method to compare two ClassicMovies alphabetically
	// preconditions: none
	// postconditions: compares two ClassicMovies alphabetically
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator<(const ClassicMovie &other) const;

	// -----------------------------------------------operator==------------------------------------------------------- 
	// Description
	// operator==: method to compare two ClassicMovies alphabetically
	// preconditions: none
	// postconditions: returns whether or not the LHS and the RHS of the operator are equivalent
	// ----------------------------------------------------------------------------------------------------------------
	virtual bool operator==(const ClassicMovie &other) const;

	// ---------------------------------------------getMonth----------------------------------------------------------- 
	// Description
	// getMonth: method to return the month a classic movie was released
	// preconditions: a ClassicMovie exists
	// postconditions: returns the month a classic movie was released
	// ----------------------------------------------------------------------------------------------------------------
	int getMonth() const;

	// ---------------------------------------------getActorsFirstName------------------------------------------------- 
	// Description
	// getActorsFirstName: method to return an actor's first name
	// preconditions: an actor exists
	// postconditions: actor's first name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getActorsFirstName() const;

	// ---------------------------------------------getActorsLastName-------------------------------------------------- 
	// Description
	// getActorsLastName: method to return an actor's last name
	// preconditions: an actor exists
	// postconditions: actor's last name is returned
	// ----------------------------------------------------------------------------------------------------------------
	string getActorsLastName() const;

	// ---------------------------------------------operator<<--------------------------------------------------------- 
	// Description
	// operator<<: operator to print the ClassicMovie
	// preconditions: a ClassicMovie exists
	// postconditions: ClassicMovies are printed to console
	// ----------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& out, const ClassicMovie& classifMovie);


private:

	int month;	//field for classic movie month
	string actorsFirstName;		//field for actors first name
	string actorsLastName;		//field for actors last name

};

#endif

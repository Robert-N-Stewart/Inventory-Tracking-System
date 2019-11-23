// ---------------------------------------------------- Movie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the Movie class

// --------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

class Movie {


public:

	// ------------------------------------------Movie Default Constructor--------------------------------------------- 
	// Description
	// ComedyMovie: default constructor for the Movie
	// preconditions: none
	// postconditions: a new Movie is created with all variables empty

	// ----------------------------------------------------------------------------------------------------------------
	Movie();

	// ------------------------------------------Movie Constructor----------------------------------------------------- 
	// Description
	// ComedyMovie: constructor for the Movie
	// preconditions: none
	// postconditions: a new Movie is created with all variables filled
	// ----------------------------------------------------------------------------------------------------------------
	Movie(char type, int stock, string director, string title, int year);

	// ---------------------------------------------getType------------------------------------------------------------ 

	// Description

	// getType: method to return the type of movie that was released
	// preconditions: a Movie exists
	// postconditions: returns the type of movie released

	// ----------------------------------------------------------------------------------------------------------------
	char getType() const;

	// ---------------------------------------------getStock----------------------------------------------------------- 
	// Description
	// getStock: method to return the quantity of a movie
	// preconditions: a Movie exists
	// postconditions: returns the quantity of the movie in stock
	// ----------------------------------------------------------------------------------------------------------------
	int getStock() const;

	// ---------------------------------------------getDirector-------------------------------------------------------- 
	// Description
	// getDirector: method to return the director of the movie
	// preconditions: a Movie exists
	// postconditions: returns the director of a movie
	// ----------------------------------------------------------------------------------------------------------------
	string getDirector()const;

	// ---------------------------------------------getTitle----------------------------------------------------------- 
	// Description
	// getTitle: method to return the title of a movie
	// preconditions: a Movie exists
	// postconditions: returns the title of the movie
	// ----------------------------------------------------------------------------------------------------------------
	string getTitle() const;

	// ---------------------------------------------getYear------------------------------------------------------------ 
	// Description
	// getMonth: method to return the year a movie was released
	// preconditions: a Movie exists
	// postconditions: returns the year a movie was released
	// ----------------------------------------------------------------------------------------------------------------
	int getYear() const;

	// ---------------------------------------------rentOutMovie------------------------------------------------------- 
	// Description
	// rentOutMovie: method to mark the movie as borrowed
	// preconditions: a Movie exists
	// postconditions: a movie is borrowed and the quantity is adjusted
	// ----------------------------------------------------------------------------------------------------------------
	bool rentOutCopy();

	// ---------------------------------------------returnCopy--------------------------------------------------------- 
	// Description
	// returnCopy: method to return a movie to the store from a Client
	// preconditions: none
	// postconditions: returns the movie
	// ----------------------------------------------------------------------------------------------------------------
	bool returnCopy();

	// ------------------------------------------printMovie------------------------------------------------------------ 
	// Description
	// printMovie: method that calls the child method to printMovie
	// preconditions: a movie with a type exists
	// postconditions: the child printMovie function is called and the movie is printed to the console
	// ----------------------------------------------------------------------------------------------------------------
	virtual void printMovie() = 0;

protected:
	char type;
	int stock;
	string director;
	string title;
	int year;
};

#endif // !MOVIE_H





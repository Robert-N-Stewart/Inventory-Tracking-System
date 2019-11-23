// ---------------------------------------------------- Movie.h -------------------------------------------------------

// Robert Stewart 
// Sky Lockwood

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the Movie class

// --------------------------------------------------------------------------------------------------------------------
#include "Movie.h"

// ------------------------------------------Movie Default Constructor--------------------------------------------- 
// Description
// ComedyMovie: default constructor for the Movie
// preconditions: none
// postconditions: a new Movie is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
Movie::Movie()
{
	this->type = 'N';
	this->stock = -1;
	this->director = "";
	this->title = "";
	this->year = -1;
}


// ------------------------------------------Movie Constructor----------------------------------------------------- 
// Description
// ComedyMovie: constructor for the Movie
// preconditions: none
// postconditions: a new Movie is created with all variables filled
// ----------------------------------------------------------------------------------------------------------------
Movie::Movie(char type, int stock, string director, string title, int year)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->year = year;

}

// ---------------------------------------------getType------------------------------------------------------------ 

// Description

// getType: method to return the type of movie that was released
// preconditions: a Movie exists
// postconditions: returns the type of movie released

// ----------------------------------------------------------------------------------------------------------------
char Movie::getType() const
{
	return type;
}


// ---------------------------------------------getStock----------------------------------------------------------- 
// Description
// getStock: method to return the quantity of a movie
// preconditions: a Movie exists
// postconditions: returns the quantity of the movie in stock
// ----------------------------------------------------------------------------------------------------------------
int Movie::getStock() const
{
	return stock;
}

// ---------------------------------------------getDirector-------------------------------------------------------- 
// Description
// getDirector: method to return the director of the movie
// preconditions: a Movie exists
// postconditions: returns the director of a movie
// ----------------------------------------------------------------------------------------------------------------
string Movie::getDirector() const
{
	return director;
}

// ---------------------------------------------getTitle----------------------------------------------------------- 
// Description
// getTitle: method to return the title of a movie
// preconditions: a Movie exists
// postconditions: returns the title of the movie
// ----------------------------------------------------------------------------------------------------------------
string Movie::getTitle() const
{
	return title;
}


// ---------------------------------------------getYear------------------------------------------------------------ 
// Description
// getMonth: method to return the year a movie was released
// preconditions: a Movie exists
// postconditions: returns the year a movie was released
// ----------------------------------------------------------------------------------------------------------------
int Movie::getYear() const
{
	return year;
}


// ---------------------------------------------rentOutMovie------------------------------------------------------- 
// Description
// rentOutMovie: method to mark the movie as borrowed
// preconditions: a Movie exists
// postconditions: a movie is borrowed and the quantity is adjusted
// ----------------------------------------------------------------------------------------------------------------
bool Movie::rentOutCopy()
{
	if (stock < 1) {
		return false;
	}
	else {
		stock--;
		return true;
	}
}

// ---------------------------------------------returnCopy--------------------------------------------------------- 
// Description
// returnCopy: method to return a movie to the store from a Client
// preconditions: none
// postconditions: returns the movie
// ----------------------------------------------------------------------------------------------------------------
bool Movie::returnCopy()
{
	stock++;
	return true;
}


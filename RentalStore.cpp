// ------------------------------------------------- RentalStore.h ----------------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the RentalStore class

// --------------------------------------------------------------------------------------------------------------------
#include "RentalStore.h"

// -------------------------------------RentalStore Default Constructor--------------------------------------------- 
// Description
// RentalStore: default constructor for the RentalStore
// preconditions: none
// postconditions: a new RentalStore is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
RentalStore::RentalStore()
{
	clients = new ClientHashMap();
	comedyMovieStorage = new MovieBST<ComedyMovie>();
	dramaMovieStorage = new MovieBST<DramaMovie>();
	classicMovieStorage = new MovieBST<ClassicMovie>();
	classicMovieActors = new MovieBST<ClassicActorsList>();

}

// --------------------------------------------RentalStore Deconstructor------------------------------------------- 
// Description
// RentalStore: Deconstructor for the RentalStore
// preconditions: RentalStore exists
// postconditions: a RentalStore deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
RentalStore::~RentalStore()
{
	delete clients;
	delete comedyMovieStorage;
	delete dramaMovieStorage;
	delete classicMovieStorage;
	delete classicMovieActors;

}

// -------------------------------------------------buildClients--------------------------------------------------- 
// Description
// buildClients: a method that reads from a file to input all the clients
// preconditions: RentalStore exists
// postconditions: clients are read from a file and inserted into the system
// ----------------------------------------------------------------------------------------------------------------
void RentalStore::buildClients(ifstream & infile)
{
	//if the file does not exist output a message
	if (infile.fail()) {
		cout << "file does not exist" << endl;
		cout << "Exit program" << endl;
	}

	//variables for the client and a counter for the line number being read
	string firstName;
	string lastName;
	int iD;
	int lineNumber = 0;

	//for each line of the text file containing one client per line
	//asumes that each line is formatted correctly
	while (!infile.eof()) {
		lineNumber++;		//increments the line number

		infile >> iD;		// gets the client id

		//tests for extra space at end of file 
		if (infile.eof()) {
			break;
		}

		//gets the clients first and last name
		infile >> lastName;
		infile >> firstName;

		//if the client id is invalid output a message
		//else create the client
		if (iD / 10000 > 0) {
			cout << "Invalid client read at line " << lineNumber << endl;
		}
		else {
			(*clients).insert(new Client(iD, firstName, lastName));
		}

	}
}

// -------------------------------------------------buildStock----------------------------------------------------- 
// Description
// buildStock: a method that reads from a file to input all the stock
// preconditions: RentalStore exists
// postconditions: stock is read from a file and inserted into the system
// ----------------------------------------------------------------------------------------------------------------
void RentalStore::buildStock(ifstream & infile)
{
	//if the file does not exist output a message
	if (infile.fail()) {
		cout << "file does not exist" << endl;
		cout << "Exit program" << endl;
	}

	//variables for all types of movies
	//and parsing the line
	char movieType;
	char spaceAfterComma;
	string movieTypeString;
	int stock;
	string stockString;
	string director;
	string title;
	string actorsFirstName;
	string actorsLastName;
	string monthString;
	int month;
	string yearString;
	int year;

	//variable for counting the line and line itself to parse
	int lineCount = 0;
	string line;

	//for each line on the file 
	//assumes that each line of the file is formatted correctly for a movie
	while (!infile.eof()) {

		lineCount++;	//increments the line count

		//gets the whole line to parse
		getline(infile, line);
		
		//if the line is empty then output message and continue 
		if (line.empty()) {
			continue;		//tests empty line
		}

		//gets the first character of the line representing movie type
		//if it is not a valid movie type, go to next line in file
		movieType = line.at(0);
		if (movieType != 'C' && movieType != 'D' && movieType != 'F') {
			cout << "Invalid movie type read on line " << lineCount << endl << endl;;
			continue;		//invalid movie therefore continue
		}

		//process line to create movie
		stringstream ss(line);

		
		// parses information that all movie types share 
		getline(ss, movieTypeString, ',');	// 	gets movie type
		ss.get(spaceAfterComma);
		getline(ss, stockString, ',');			//gets stock in string format
		stock = atoi(stockString.c_str());		//converts the stock string into an int

		//can not have a negative stock therefore outputs message if negative stock read
		if (stock < 0) {
			cout << "Invalid movie type read on line " << lineCount << endl << endl;;
			continue;		//invalid movie therefore continue
		}

		//continues parsing information that all movie types share 
		ss.get(spaceAfterComma);
		getline(ss, director, ',');			//gets director
		ss.get(spaceAfterComma);
		getline(ss, title, ',');		//gets title
		ss.get(spaceAfterComma);

		//gets the other required movie information depending on the movie type
		//then creates the movie and stores it in the correct movie bin
		if (movieType == 'C') {

			ss >> actorsFirstName;		//gets actors first name
			ss >> actorsLastName;		//gets actors last name
			ss >> monthString;		//gets the month in string format
			month = atoi(monthString.c_str());		//converts month in string format to int	
			ss >> yearString;		//gets the year in string format
			year = atoi(yearString.c_str());		//converts the year into string format
			if (year < 1890) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;
			}
			//attempts to insert the classic movie created from variables in classic movie storage
			bool insertSuccess = classicMovieStorage->insert(new ClassicMovie(stock, director, title, actorsFirstName, actorsLastName, month, year));
			//if movie is already stored under sorting variables then output invalid movie
			if (insertSuccess != true) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;		//invalid movie therefore continue
			}
			
			//searches for the the actor list for the classic movie
			ClassicActorsList* searchTempForClassicItem = new ClassicActorsList(title, director, month, year);
			ClassicActorsList* classicActorListForItem = classicMovieActors->retrieve(searchTempForClassicItem);
			
			//if no actor list is found for the classic movie then create a new actors list  
			//else add actor to actor list found for the classic movie
			if (classicActorListForItem == NULL) {
				searchTempForClassicItem->addActor(actorsFirstName, actorsLastName);
				classicMovieActors->insert(searchTempForClassicItem);
			}
			else {
				classicActorListForItem->addActor(actorsFirstName, actorsLastName);
				delete searchTempForClassicItem;
				searchTempForClassicItem = NULL;
			}
		}
		else if (movieType == 'F') {
				
			ss >> yearString;		//gets the year in string format
			year = atoi(yearString.c_str());		//converts the year into string format
			if (year < 1890) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;
			}
			//attempts to insert the movie created from variables in comedy movie storage
			bool insertSuccess = comedyMovieStorage->insert(new ComedyMovie(stock, director, title, year));
			//if movie is already stored under sorting variables then output invalid movie
			if (insertSuccess != true) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;		//invalid movie therefore continue
			}
		}
		else if (movieType == 'D') {
				
			ss >> yearString;		//gets the year in string format
			year = atoi(yearString.c_str());		//converts the year into string format
			if (year < 1890) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;
			}
			//attempts to insert the movie created from variables in drama movie storage
			bool insertSuccess = dramaMovieStorage->insert(new DramaMovie(stock, director, title, year));
			//if movie is already stored under sorting variables then output invalid movie
			if (insertSuccess != true) {
				cout << "Invalid movie type read on line " << lineCount << endl << endl;;
				continue;		//invalid movie therefore continue
			}
			
		}
	}
}

// -------------------------------------------------buildCommands-------------------------------------------------- 
// Description
// buildCommands: a method that reads from a file to input all the commands
// preconditions: RentalStore exists
// postconditions: commands are read from a file and inserted into the system
// ----------------------------------------------------------------------------------------------------------------
void RentalStore::loadCommands(ifstream & infile)
{
	int lineCount = 0;		//variable for line count, used for outputing invalid commands
	string line;		//string for parsing line

	//variables that commands share
	char commandType;
	string commandTypeString;
	string clientIDString;
	int clientID;

	//for every line of the command text file parse each line creating a rental command
	//or outputting an invalid command read message
	while (!infile.eof()) {

		lineCount++;		//increments the line

		//gets the line to parse
		getline(infile, line);

		//if the line is empty outputs a empty line message
		if (line.empty()) {
			continue;		//tests empty line
		}

		//gets the first character of the line representing movie type
		//if it is not a valid movie type, go to next line in file
		commandType = line.at(0);


		if (commandType == 'I') {

			cout << "Comedy movies in storage:" << endl;
			comedyMovieStorage->printTree();
			cout << endl;
			cout << "Drama movies in storage:" << endl;
			dramaMovieStorage->printTree();
			cout << endl;
			cout << "Classic movies in storage:" << endl;
			classicMovieStorage->printTree();
			cout << endl;

		}
		else if (commandType == 'H') {
			
			//parses the line
			stringstream ss(line);
			ss >> commandTypeString;
			ss >> clientIDString;		//gets the client id in string format
			clientID = atoi(clientIDString.c_str());		//converts the client id to int

			if (clientID < 0 || clientID > 9999) {
				cout << "Invalid command type read on line " << lineCount << endl << endl;;
				continue;
			}

			//attempts to retrieve client stored in client hash map
			Client* clientInDataBase = clients->retrieve(clientID);
			//if the client is not stored then invalid message is outputed
			if (clientInDataBase == NULL) {
				cout << "Invalid command type read on line " << lineCount << endl << endl;;
				continue;
			}
			clientInDataBase->printHistory();
			cout << endl;

		}
		else if (commandType == 'B' || commandType == 'R') {
			//process a borrow from the line read
			bool succesfulReturnOrBorrow = processReturnOrBorrow(line);
			//if the return or borrow is unsuccesful then invalid output message is sent 
			if(!succesfulReturnOrBorrow) {
				cout << "Invalid command type read on line " << lineCount << endl << endl;;
				continue;
			}
		}
		else {
			//the only commands known so far are 'H', 'I', 'B', and 'R'
			//therefore if its not a command of that type, output an error message
			cout << "Invalid command type read on line " << lineCount << endl << endl;;
		}
	}

}

// -------------------------------------------------processReturnOrBorrow-------------------------------------------------- 
// Description
// buildCommands: processes borrow and return commands
// preconditions: RentalStore exists
// postconditions: borrow and return commands are processed
// ----------------------------------------------------------------------------------------------------------------
bool RentalStore::processReturnOrBorrow(string line)
{
	char commandType = line.at(0);

	stringstream ss(line);
	string commandTypeString;
	ss >> commandTypeString;

	string clientIDString;
	ss >> clientIDString;		//gets the client id in string format
	int clientID;
	clientID = atoi(clientIDString.c_str());		//converts the client id into an int

	//attempts to get the client stored in database (hashmap)
	Client* clientInDataBase = clients->retrieve(clientID);
	//if there is no client in the database under command's client Id then output an error message
	if (clientInDataBase == NULL) {
		return false;
	}

	//get the media type in string type and then store it as a char
	string mediaTypeString;
	ss >> mediaTypeString;
	char mediaType;
	mediaType = mediaTypeString.at(0);

	//because the only format for media type as of now is DVD, if it is not a DVD media type
	//output an error message
	if (mediaType != 'D') {
		return false;
	}

	string movieTypeString;
	ss >> movieTypeString;
	char movieType;
	movieType = movieTypeString.at(0);
	char emptySpace;
	ss.get(emptySpace);

	RentalCommand* commandToProcess;
	if (movieType == 'C') {

		string movieMonthString;
		ss >> movieMonthString;		//gets the month in string format
		int movieMonth;		//converts the month into an int
		movieMonth = atoi(movieMonthString.c_str());
		//if it is an invalid month the command is invalid therfore return false
		if (movieMonth < 1 || movieMonth > 12) {
			return false;
		}

		string movieYearString;		//gets the year in string format
		ss >> movieYearString;	
		int movieYear;		//converts the year into an int
		movieYear = atoi(movieYearString.c_str());

		string movieActorFirstName;		//gets the actors first name
		ss >> movieActorFirstName;
		string movieActorLastName;		//gets the actors last name
		ss >> movieActorLastName;

		//attempts to find the classic movie in storage
		ClassicMovie* searchMovieTemp = new ClassicMovie(0, "", "", movieActorFirstName, movieActorLastName, movieMonth, movieYear);
		ClassicMovie* movieInStorage = classicMovieStorage->retrieve(searchMovieTemp);
		delete searchMovieTemp;
		searchMovieTemp = NULL;
		//if the movie is not in storage than the command is false therfore return false
		if (movieInStorage == NULL) {
			return false;
		}

		//creates the classic borrow or return rental command
		commandToProcess = new ClassicRentalCommand(commandType, clientID, mediaType, movieType, movieMonth,
			movieYear, movieActorFirstName, movieActorLastName);
		//of it is a return command then attempt to process the return
		if (commandType == 'R') {

			//validates the return 
			bool validReturn = clientInDataBase->validateReturn(commandToProcess);
			//if the return is not valid then invalid message is outputed
			if (validReturn == false) {
				delete commandToProcess;
				commandToProcess = NULL;
				return false;
			}
			else {
				//else the return is valid so increments stock and adds the command to the clients history
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->returnCopy();
				return true;
			}
		}
		else {
			//procceses a borrow command for classic movies that has stock under multiple actors
			//if the stock for requested movie under specific actor is out
			//then look for stock under another actor
			if (movieInStorage->getStock() < 1) {

				//creates a temp actors list for search for the correct actors list for command's classic movie
				ClassicActorsList* actorsListSearchTemp = new ClassicActorsList(movieInStorage->getTitle(), movieInStorage->getDirector(), movieInStorage->getMonth(), movieInStorage->getYear());
				//finds the actors list for found classical movie (must be stored as the movie was found)
				ClassicActorsList* actorsList = classicMovieActors->retrieve(actorsListSearchTemp);
				//no longer needs temp for searching therefore delete
				delete actorsListSearchTemp;
				actorsListSearchTemp = NULL;
				//gets the vector of the actor names for this classical movie
				vector<ActorName*>* actorListNames = actorsList->getActors();

				//goes through actors list to find stock under another actors name
				string otherActorsFirstName;
				string otherActorsLastName;
				for (int i = 0; i < actorListNames->size(); i++) {
					//gets actors name from list
					ActorName* otherActor = actorListNames->at(i);
					otherActorsFirstName = otherActor->getFirstName();
					otherActorsLastName = otherActor->getLastName();

					//creates a temp movie for searching for the movie under new actor name (only needs sorting values)
					searchMovieTemp = new ClassicMovie(0, "", "", otherActorsFirstName, otherActorsLastName, movieMonth, movieYear);
					//finds the classic movie in storage under new actors name
					movieInStorage = classicMovieStorage->retrieve(searchMovieTemp);
					//searching temp is no longer need so it is deleted
					delete searchMovieTemp;
					searchMovieTemp = NULL;

					//if the movie under new actors name has stock break search
					if (movieInStorage->getStock() > 0) {
						break;
					}
				}
				//if a classic movie under a different actors name has stock
				if (movieInStorage->getStock() > 0) {

					//rent out a copy and add the rental command to the clients history
					clientInDataBase->addToHistory(commandToProcess);
					movieInStorage->rentOutCopy();
					return true;
				}
				else {
					//else there was no stock under a different actors name
					delete commandToProcess;
					commandToProcess = NULL;
					return false;
				}
			}
			else {
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->rentOutCopy();
				return true;
			}
		}
	}
	else if (movieType == 'D') {

		//gets the movie director with the delimiter ','
		string movieDirector;
		getline(ss, movieDirector, ',');
		ss.get();

		//gets the movie title of the drama movie command and unappends the "," at the end
		string movieTitle;
		getline(ss, movieTitle);
		movieTitle = movieTitle.substr(0, movieTitle.length() - 1);

		//creates a movie only for the purpose of searching for the movie
		DramaMovie* searchMovieTemp = new DramaMovie(0, movieDirector, movieTitle, 0);
		//attempts to find the drama movie in storage
		DramaMovie* movieInStorage = dramaMovieStorage->retrieve(searchMovieTemp);
		delete searchMovieTemp;
		searchMovieTemp = NULL;

		//if the drama movie is not found in storage then output an error message
		if (movieInStorage == NULL) {
			return false;
		}

		//creates rental command to attempt to process
		commandToProcess = new DramaRentalCommand(commandType, clientID, mediaType, movieType, movieDirector, movieTitle);

		if (commandType == 'R') {
			//attempts to validate the return
			bool validReturn = clientInDataBase->validateReturn(commandToProcess);
			//if the return is not valid then invalid message is outputed and command is delted
			if (validReturn == false) {
				delete commandToProcess;
				commandToProcess = NULL;
				return false;
			}
			else {
				//else process return and add it to the clients history
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->returnCopy();
				return true;
			}
		}
		else {
			//attempts to process a borrow
			//if there is stock to borrow then process borrow and add it to the clients history
			if (movieInStorage->getStock() > 0) {
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->rentOutCopy();
				return true;
			}
			else {
				//else there is no stock so command is delted and false is returned
				delete commandToProcess;
				commandToProcess = NULL;
				return false;
			}

		}

	}
	else if(movieType == 'F') {
		//gets the remaining variables needed for a comedy rental command
		string movieTitle;		//gets the title
		getline(ss, movieTitle, ',');

		string movieYearString;
		ss >> movieYearString;		//gets the year in string format
		int movieYear;
		movieYear = atoi(movieYearString.c_str());		//converts the movie year to string format

		//creates temp comedy movie for searching 
		ComedyMovie* searchMovieTemp = new ComedyMovie(0, "", movieTitle, movieYear);
		//attempts to find the movie in storage
		ComedyMovie* movieInStorage = comedyMovieStorage->retrieve(searchMovieTemp);
		//searching temp is no longer needed so delete
		delete searchMovieTemp;
		searchMovieTemp = NULL;
		//if the comedy movie is not found in storage then output an error message
		if (movieInStorage == NULL) {
			return false;
		}
		 //create the command to process
		commandToProcess = new ComedyRentalCommand(commandType, clientID, mediaType, movieType, movieTitle, movieYear);

		if (commandType == 'R') {
			//attempt to validate the return
			bool validReturn = clientInDataBase->validateReturn(commandToProcess);
			//if the return is not valid then delete the command and return false
			if (validReturn == false) {
				delete commandToProcess;
				commandToProcess = NULL;
				return false;
			}
			else {
				//process the return and add the command to the clients history
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->returnCopy();
				return true;
			}
		}
		else {
			//process the borrowing of a comedy movie
			//if the movie has stock then process the borrow and add the command to the clients history 
			if (movieInStorage->getStock() > 0) {
				clientInDataBase->addToHistory(commandToProcess);
				movieInStorage->rentOutCopy();
				return true;
			}
			else {
				//if there is no stock return false
				delete commandToProcess;
				commandToProcess = NULL;
				return false;
			}

		}
	}
	else {
		//if it is not a valid movie type then return false
		return false;
	}
}

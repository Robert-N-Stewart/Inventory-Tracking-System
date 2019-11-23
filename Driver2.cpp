

#include <iostream>
#include <fstream>
#include "RentalStore.h"

using namespace std;

int main() {
	// part 1 tests with the dataUWB.txt not data31 
	ifstream infile1("data4movies.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}


	ifstream infile2("data4customers.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	RentalStore* store = new RentalStore();
	store->buildStock(infile1);
	store->buildClients(infile2);
	store->loadCommands(infile3);

	delete store;

}

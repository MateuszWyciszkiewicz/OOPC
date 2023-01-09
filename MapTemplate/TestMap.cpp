#include "Employee.h" // Defines class Employee
#include "Map.h"	  // Defines template Map<Key, Value>
#include "Book.h"
#include <iostream>

typedef unsigned int ID;			// Identification number of employee
typedef Map<ID, Employee> Database; // Database of employees

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);
void specialCases(Database& database);
void keyNotInBase(Database& database);
void keyMultipletimes(Database& database);
void libraryTest();

int main()
{
	Database database;
	addEmployees(database);

	Database newDatabase = database; // Make a copy of database

	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman",
										43)); // Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase; // Update original database

	cout << "Database after the assignment:" << endl << database << endl;
    libraryTest();
	specialCases(database);
};

void specialCases(Database& database)
{
	cout << "special cases tests\n" << endl;
	keyNotInBase(database);
	keyMultipletimes(database);
}

void addEmployees(Database& database)
{
	database.add(761028073,
				 Employee("Jan Kowalski", "salesman",
						  28)); // Add first employee: name: Jan Kowalski,
								// position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper",
									 54)); // Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary",
									 32)); // Add third employee
}

void modifyEmployees(Database& database)
{
	Employee* employeePtr;

	employeePtr = database.find(510212881); // Find employee using its ID
	employeePtr->position = "salesman";		// Modify the position of employee

	employeePtr = database.find(761028073); // Find employee using its ID
	employeePtr->age = 29;					// Modify the age of employee
}

void keyNotInBase(Database& database)
{
	cout << "key not in the database test:" << endl;
	try {
		database.find(122222);
	}
	catch (KeyDoesNotExistException e) {
		cout << "key not in database, exception caught\n" << endl;
	}
}

void keyMultipletimes(Database& database)
{
	cout << "key alredy in database test:" << endl;
	try {
		database.add(761028073, Employee("Jan Nowak", "Manager", 24));
	}
	catch (KeyAlreadyExistsException e) {
		cout << "key already in database, exception caught\n" << endl;
	}
}

void libraryTest(){
    cout << "library test\n" << endl;
    typedef string author;
    typedef Map<author, Book> Library;
    
    Library library;
    cout << "Initial library:" << endl;
    library.add("H. P. Lovecraft", Book("Call of Cuthulhu", "SciFi", 215, "bookshelf")); 
    library.add("J. R. R. Tolkien", Book("Hobbit", "Fantasy", 250, "bookshelf")); 
    library.add("Edgar Allan Poe", Book("The Raven", "Fantasy", 130, "borrowed"));
    library.add("Hazel Heald", Book("The Nightmares", "SciFi", 350, "borrowed")); 
    
    cout << library << endl;
    Library copyLibrary = library;
    
    cout << "Library after modifications:" << endl;
    copyLibrary.add("Bjarne Stroustrup", Book("The C++ Programming Language", "Education", 1500, "borrowed"));
    /*Book* bookPtr;
    bookPtr = copyLibrary.find("Edgar Allan Poe");
    bookPtr -> status = "bookshelf";*/
    cout << copyLibrary<< endl;
    }

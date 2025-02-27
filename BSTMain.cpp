// Robert Koenig
// Section 011

#include "BST.hpp"
#include "Book.hpp"
#include "Library.hpp"
#include <iostream>
using namespace std;

int main() {
	// Testing book comparisons
	//Book b1("Hi", "Koenig, Robert", 72, "me", 34567, 5.0);
	//Book b2("Birch Trees","Shmoe, Joe", 84, "Science Books",34567,4.0);
	//Book b3("Dogs Are My Best Friend","David, Alex",24, "Books for Children",22222,4.0);
	//cout << (b1 == b1) << endl;
	// cout << (b1 < b2) << endl;
	// cout << (b1 < b3) << endl;
	// cout << (b1 == b1) << endl;
	// cout << (b1 == b2) << endl;
	// cout << (b1 != b3) << endl;
	// cout << (b1 > b1);
	// cout << (b1 > b2);
	// cout << (b1 > b3);
	// cout << (b1 <= b1);
	// cout << (b1 <= b2);
	// cout << (b1 <= b3);
	// cout << (b1 >= b1);
	// cout << (b1 >= b2);
	// cout << (b1 >= b3);

	Library library("halloween.txt");
	library.menu();


	return 0;
}

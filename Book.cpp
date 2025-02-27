// Robert Koenig
// Section 011

#include "Book.hpp"
#include <iostream>
#include <string>
using namespace std;

/*
 * Book contructor with input
 * input: 3 string, 1 int, 1 long long, 1 float
 * output: not applicable
 * *This function does allocate memory
 */
Book::Book(string t, string auth, int yr, string pub, long long isbn, float rate) {
	title = t;
	author = auth;
	year = yr;
	publisher = pub;
	isbn13 = isbn;
	rating = rate;
	checked_out = false;
}

/*
 * Book contructor with no input
 * input: none
 * output: not applicable
 * *This function does allocate memory
 */
Book::Book() {
	title = "";
	author = "";
	year = 0;
	publisher = "";
	isbn13 = 0;
	rating = 0;
	checked_out = false;
}

/*
 * Function to return a book's rating
 * input: none
 * output: Book part rating
 */
float Book::getRating() {
	return rating;
}

/*
 * Function to print out the information of a book
 * input: none
 * output: none returned but does print
 */
void Book::printBook() {
	cout << "---------------------" << endl;
	cout << title << "\nAuthor: " << author << "\t\tYear: " << year << endl;
	cout << "Publisher: " << publisher << "\tISBN-13: " << isbn13 << "\tRating: " << rating << endl;
	cout << "Currently Available: " << (checked_out ? "No" : "Yes") << endl;
}

/*
 * Function to overload the < operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator< (Book b2) {
    if (this->author < b2.author || (this->author == b2.author && this->title < b2.title)){
        return true;
    }
	return false;
}

/*
 * Function to overload the > operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator> (Book b2) {
    if (this->author > b2.author || (this->author == b2.author && this->title > b2.title)){
        return true;
    }
    return false;
}

/*
 * Function to overload the == operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator==(Book b2) {
    if (this->author == b2.author && this->title == b2.title) {
        return true;
    }
    return false;
}

/*
 * Function to overload the != operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator!=(Book b2) {
    if (this->author != b2.author && this->title != b2.title) {
        return true;
    }
    return false;
}

/*
 * Function to overload the <= operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator<=(Book b2) {
    if (this->author < b2.author || (this->author == b2.author && this->title < b2.title)) {
        return true;
    }
    return false;
}

/*
 * Function to overload the >= operator
 * input: Book pointer
 * output: boolean
 */
bool Book::operator>=(Book b2) {
    if (this->author > b2.author || (this->author == b2.author && this->title > b2.title) || (this->author == b2.author && this->title == b2.title)) {
        return true;
    }
    return false;
}
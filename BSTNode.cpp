// Robert Koenig
// Section 011

#include <iostream>
#include <string>
#include "BSTNode.hpp"
using namespace std;

/*
 * BSTNode contructor with input
 * input: 3 string, 1 int, 1 long long, 1 float
 * output: not applicable
 * *This function does allocate memory
 */
BSTNode::BSTNode (string t, string auth, int yr, string pub, long long isbn, float rate) {
	book = new Book(t, auth, yr, pub, isbn, rate);
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = 0;
}

/*
 * BSTNode contructor with no input
 * input: none
 * output: not applicable
 * *This function does allocate memory
 */
BSTNode::BSTNode() {
	book = nullptr;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = 0;
}

/*
 * Book decontructor
 * input: none
 * output: not applicable
 * *This function deallocates memory
 */
BSTNode::~BSTNode(){
	cout <<"Deleting "<<book->title<<endl;
	delete book;
	book = nullptr;
}

void BSTNode::printNode(bool debug) {
	/* takes a boolean to decide whether to print extra information about the node - useful for debugging */
	book->printBook();
	if(debug) {
		cout << "Node: h=" << height ;
		cout << "\n\tParent: " << (parent ? parent->book->title + ": " + parent->book->author : "NODE IS ROOT");
		cout << "\n\tLeft: " << (left ? left->book->title + ": " + left->book->author : "--");
		cout << "\n\tRight: " << (right ? right->book->title + ": " + right->book->author : "--");
		cout << endl << endl;
	}
}




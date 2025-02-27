// Robert Koenig
// Section 011

#include "BST.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * BST contructor with no input
 * input: none
 * output: not applicable
 * *This function does allocate memory
 */
BST::BST() {
    root = nullptr;
}

/*
 * BST contructor with input
 * input: 3 string, 1 int, 1 long long, 1 float
 * output: not applicable
 * *This function does allocate memory
 */
BST::BST(string title, string author, int yr, string pub, long long isbn, float rate) {
    root = new BSTNode(title, author, yr, pub, isbn, rate);
}

/*
 * BST decontructor
 * input: none
 * output: not applicable
 * *This function does deallocate memory
 */
BST::~BST() {
	clearTree();
}

/*
 * Insert Function
 * input: 3 string, 1 int, 1 long long, 1 float
 * output: none
 */
void BST::insert(string title, string author, int yr, string pub, long long isbn, float rate) {
	BSTNode *newBook = new BSTNode(title, author, yr, pub, isbn, rate);
    BSTNode *temp = root;
    BSTNode *parent = nullptr;
    // incase of empty tree
    if (root == nullptr){
        root = newBook;
        return;
    }
    // increments through tree to find proper position
    while(temp != nullptr){
        parent = temp;
        if (newBook->book->author < temp->book->author || (newBook->book->author == temp->book->author && newBook->book->title < temp->book->title)){
            temp = temp->left;
        } else if (newBook->book->author >= temp->book->author){
            temp = temp->right;
        }
    }
    // Once parent is found, determines which side to insert new node
    if (newBook->book->author < parent->book->author  || (newBook->book->author == parent->book->author && newBook->book->title < parent->book->title)){
        parent->left = newBook;
        newBook->parent = parent;
    } else if (newBook->book->author >= parent->book->author){
        parent->right = newBook;
        newBook->parent = parent;
    }
    // sets height of new node
    setHeight(newBook);
}

/*
 * Find function
 * input: 2 strings
 * output: 1 BSTNode pointer
 */
BSTNode *BST::find(string title, string author) {
    // calls other find function
    BSTNode *temp = find(title, author, root);
    if(temp != nullptr){
        return temp;
    }
    return nullptr;
}

/*
 * Find function
 * input: 2 strings, 1 BSTNode pointer
 * output: 1 BSTNode pointer
 */
BSTNode *BST::find(string title, string author, BSTNode *start) {
    if(start == nullptr){
        return nullptr;
    } else if (start->book->title == title && start->book->author == author){
        return start;
    } else if (start->book->author == author && start->book->title > title){
        return find(title, author, start->left);
    } else if (start->book->author == author && start->book->title < title){
        return find(title, author, start->right);
    } else if (start->book->author > author){
        return find(title,author,start->left);
    } else {
        return find(title,author,start->right);
    }
}

/*
 * In Order Print helper function
 * input: 1 boolean
 * output: none
 */
void BST::printTreeIO(bool debug) {
    // incase of empty tree
	if (root == nullptr) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << "\nPrinting In-Order:" << endl;
        // calls main in order print function
		printTreeIO(root, debug);
	}
}

/*
 * In Order Print Function
 * input: 1 BSTNode pointer, 1 boolean
 * output: none
 */
void BST::printTreeIO(BSTNode *node, bool debug) {
    // recursivley calls print function until at bottom left of tree
    if (node->left != nullptr){
        printTreeIO(node->left, debug);
    }
    // prints middle node
    node->printNode(debug);
    // recursivley prints right side
    if (node->right != nullptr){
        printTreeIO(node->right, debug);
    }
}

/*
 * Pre Order Print helper function
 * input: 1 boolean
 * output: none
 */
void BST::printTreePre(bool debug) {
    // incase of empty tree
	if (root == nullptr) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl << "Printing Pre-Order:" << endl;
		printTreePre(root, debug);
	}
}

/*
 * Pre Order Print Function
 * input: 1 BSTNode pointer, 1 boolean
 * output: none
 */
void BST::printTreePre(BSTNode *node, bool debug) {
    // prints middle node
    node->printNode(debug);
    // goes through left
    if (node->left != nullptr){
        printTreePre(node->left, debug);
    }
    // goes through right
    if (node->right != nullptr){
        printTreePre(node->right, debug);
    }
}

/*
 * Post Order Print helper function
 * input: 1 boolean
 * output: none
 */
void BST::printTreePost(bool debug) {
    // incase of empty tree
	if (root == nullptr) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing Post-Order:" <<endl;
		printTreePost(root, debug);
	}
}

/*
 * Post Order Print Function
 * input: 1 BSTNode pointer, 1 boolean
 * output: none
 */
void BST::printTreePost(BSTNode *node, bool debug) {
    // goes through left
    if (node->left != nullptr){
        printTreePost(node->left, debug);
    }
    // goes through right
    if (node->right != nullptr){
        printTreePost(node->right, debug);
    }
    // prints middle node
    node->printNode(debug);
}

/*
 * Clear Tree helper function
 * input: none
 * output: none
 */
void BST::clearTree() {
    // incase of empty tree
	if (root == nullptr) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = nullptr;
	}
}

/*
 * Clear Tree function
 * input: 1 BSTNode pointer
 * output: none
 */
void BST::clearTree(BSTNode *node) {
    // exits once tree is empty
	if (node == nullptr) {
		return;
	}
    // iterates through tree deleting nodes
	else {
		clearTree(node->left);
		node->left = nullptr;
		clearTree(node->right);
		node->right = nullptr;
		node->printNode(true);
		delete node;
	}
}

/*
 * Check Out function
 * input: 2 strings
 * output: 1 boolean
 */
bool BST::checkOut(string title, string author) {
    // calls find() to find the desired book
    BSTNode *temp = find(title, author);
    while (temp){
        if (temp->book->checked_out == false){
            temp->book->checked_out = true;
            return true;
        }
        // calls find() again to find any repeats
        temp = find(title, author, temp->right);
    }
    return false;
}

/*
 * Check In function
 * input: 2 strings
 * output: 1 boolean
 */
bool BST::checkIn(string title, string author) {
    // calls find() to find the desired book
    BSTNode *temp = find(title, author);
    while (temp){
        if (temp->book->checked_out == true){
            temp->book->checked_out = false;
            return true;
        }
        // calls find() again to find any repeats
        temp = find(title, author, temp->right);
    }
    return false;
}

/*
 * Update Rating function
 * input: 2 strings, 1 float
 * output: none
 */
void BST::updateRating(string title, string author, float newRating) {
    // calls find() to find the desired book
    BSTNode *temp = find(title, author);
    while (temp != nullptr) {
        temp->book->rating = newRating;
        // checks for duplicates
        temp = find(title, author, temp->right);
    }
}

/*
 * Remove helper function for nodes with no kids
 * input: 1 BSTNode pointer
 * output: 1 BSTNode pointer
 */
BSTNode *BST::removeNoKids(BSTNode *node) {
    BSTNode *parent = node->parent;
    if (node == root){
        root = nullptr;
    } else if (parent->left == node){
        parent->left = nullptr;
    } else if (parent->right == node){
        parent->right = nullptr;
    }
    setHeight(parent);
    node->parent = nullptr;
	return node;
}

/*
 * Remove helper function for nodes with one kid
 * input: 1 BSTNode pointer, 1 boolean
 * output: 1 BSTNode pointer
 */
BSTNode *BST::removeOneKid(BSTNode *node, bool leftFlag) {
    BSTNode *parent = node->parent;
    BSTNode *child = nullptr;
    // if the left flag is false, the child is on the right
    if(leftFlag == false){
        child = node->right;
    // if it is true, te child is on the left
    }else if (leftFlag == true){
        child = node->left;
    }
    // deletes the node and points the deleted node's parent to the orphaned child
    if (parent->left == node){
        parent->left = child;
        child->parent = parent;
    } else if (parent->right == node){
        parent->right = child;
        child->parent = parent;

    } else {
        root = child;
    }
    setHeight(child);
    setHeight(parent);
    node->parent = nullptr;
	return node;
}

/*
 * Remove Function
 * input: 1 BSTNode pointer
 * output: 1 BSTNode pointer
 */
BSTNode *BST::remove(string title, string author) {
    BSTNode *temp = find(title, author);
    // incase of empty tree
    if (temp == nullptr){
        return nullptr;
    }
    // incase deleted node has no children, calls helper function
    if (temp->left == nullptr && temp->right == nullptr){
        return removeNoKids(temp);
    // incase deleted node has one child, calls helper function
    } else if (temp->left == nullptr || temp->right == nullptr){
        if (temp->left == nullptr){
            return removeOneKid(temp, false);
        } else {
            return removeOneKid(temp, true);
        }
    // other cases
    } else {
        BSTNode *replacement = temp->right;
        // finds left most node on the right of the deleted node
        while(replacement->left != nullptr){
            replacement = replacement->left;
        }
        if(replacement->right != nullptr){
            replacement->parent->left = replacement->right;
        }
        // replaces deleted node with new node
        if(temp->right != nullptr) {
            replacement->right = temp->right;
        }
        if(temp->left != nullptr){
            replacement->left = temp->left;
        }
        if(temp->parent != nullptr){
            replacement->parent = temp->parent;
        } else{
            root = replacement;
        }
        //delete temp;
        setHeight(replacement);
        return temp;
    }
}

/*
 * Set Height Function
 * input: 1 BSTNode pointer
 * output: none
 */
void BST::setHeight(BSTNode *node){
    BSTNode *temp = node;
    int temp2 = 1;
    while (temp != root){
        if(temp->height < temp2){
            temp->height = temp2;
        }
        temp = temp->parent;
        temp2++;
    }
    // iterates through tree to find heights
    if(root->height < temp2){
        root->height = temp2;
    }
}
# Binary Search Tree (BST) Project

### Overview
This project implements a Binary Search Tree (BST) that supports various operations for managing a collection of ordered data. The BST allows efficient 
searching, insertion, deletion, and traversal of nodes, making it a useful data structure for applications requiring quick lookup and dynamic data organization.

### Functionalities
- Insertion (insert(int key)): Adds a new node with the given key while maintaining BST properties.
- Deletion (delete(int key)): Removes a node by adjusting tree structure appropriately (handling leaf nodes, one-child nodes, and two-child nodes).
- Search (search(int key)): Finds and returns the node with the specified key.
- Traversal Methods: 
  - In-order Traversal (inOrderTraversal()) – Visits nodes in ascending order.
  - Pre-order Traversal (preOrderTraversal()) – Visits the root before its subtrees.
  - Post-order Traversal (postOrderTraversal()) – Visits subtrees before the root.
  - Level-order Traversal (levelOrderTraversal()) – Visits nodes level by level.
- Find Minimum and Maximum (findMin(), findMax()): Retrieves the smallest and largest keys in the BST.
- Height Calculation (getHeight()): Computes the height of the tree for depth analysis.

### Implementation Details
##### Node Structure (BSTNode.hpp)
- Represents a tree node with key, left, and right pointers.
##### Binary Search Tree Class (BST.hpp / BST.cpp)
- Implements BST logic and operations.
##### Driver Program (main.cpp)
- Provides a menu-driven interface for user interaction.

### Compilation & Execution
##### How to Compile
Ensure you have a C++ compiler installed (e.g., g++). Compile using:
 `g++ -o bst_program main.cpp BST.cpp -std=c++11`
##### How to Run
Run the compiled program:
 `./bst_program`

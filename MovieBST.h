
// ------------------------------------------------- MovieBST.h ----------------------------------------------------

// Robert Stewart 
// //

// 6/8/2017

// 6/8/2017

// --------------------------------------------------------------------------------------------------------------------

// The purpose of this file is class declaration for the MovieBST class

// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIEBST_H
#define MOVIEBST_H


#include <iostream>


using namespace std;

template<typename T>
class MovieBST {



public:

	// ------------------------------------------MovieBST Default Constructor------------------------------------------ 
	// Description
	// MovieBST: default constructor for the MovieBST
	// preconditions: none
	// postconditions: a new MovieBST is created with all variables empty
	// ----------------------------------------------------------------------------------------------------------------
	MovieBST();


	// --------------------------------------------MovieBST Deconstructor---------------------------------------------- 
	// Description
	// MovieBST: Deconstructor for the Client
	// preconditions: MovieBST exists
	// postconditions: a MovieBST deleted, then the memory is deallocated
	// ----------------------------------------------------------------------------------------------------------------
	~MovieBST();

	// -------------------------------------------------insert--------------------------------------------------------- 
	// Description
	// insert: method to insert a TreeNode to the MovieBST
	// preconditions: MovieBST exists
	// postconditions: a TreeNode is inserted into the MovieBST
	// ----------------------------------------------------------------------------------------------------------------
	bool insert(T*);

	// ---------------------------------------------------retrieve----------------------------------------------------- 
	// Description
	// retrieve: a TreeNode is retrieved from the MovieBST
	// preconditions: MovieBST exists
	// postconditions: a TreeNode is retrieved from the MovieBST
	// ----------------------------------------------------------------------------------------------------------------
	T* retrieve(const T*) ;

	// --------------------------------------------------printTree----------------------------------------------------- 
	// Description
	// printTree: Prints the MovieBST to the console
	// preconditions: MovieBST exists
	// postconditions: Prints the MovieBST to the console
	// ----------------------------------------------------------------------------------------------------------------
	void printTree();


private:

	struct TreeNode {
		T* data;
		TreeNode* left;
		TreeNode* right;

		TreeNode() {
			data = NULL;
			left = NULL;
			right = NULL;
		}

		TreeNode(T* movie) {
			data = movie;
			left = NULL;
			right = NULL;
		}

		~TreeNode() {
			delete data;
			left = NULL;
			right = NULL;
		}
	};

	TreeNode* root;

	// ------------------------------------------------insertHelper---------------------------------------------------- 
	// Description
	// insert: method to insert a TreeNode to the MovieBST
	// preconditions: MovieBST exists
	// postconditions: a TreeNode is inserted into the MovieBST
	// ----------------------------------------------------------------------------------------------------------------
	bool insertHelper(T*, TreeNode*&);

	// ------------------------------------------------retrieveHelper---------------------------------------------------- 
	// Description
	// retrieve: method to retrieve a TreeNode to the MovieBST
	// preconditions: MovieBST exists
	// postconditions: a TreeNode is retrieved into the MovieBST
	// ----------------------------------------------------------------------------------------------------------------
	T* retrieveHelper(const T*, TreeNode*&);

	// ------------------------------------------------destructorHelper---------------------------------------------------- 
	// Description
	// destructor: method to delete all TreeNodes
	// preconditions: MovieBST exists
	// postconditions: ll tree nodes are delted
	// ----------------------------------------------------------------------------------------------------------------
	void destructorHelper(TreeNode*&);

	// ------------------------------------------------printTreeHelper---------------------------------------------------- 
	// Description
	// destructor: method to print all TreeNodes
	// preconditions: MovieBST exists
	// postconditions: all elements of tree printed
	// ----------------------------------------------------------------------------------------------------------------
	void printTreeHelper(TreeNode*&);

};

// ------------------------------------------MovieBST Default Constructor------------------------------------------ 
// Description
// MovieBST: default constructor for the MovieBST
// preconditions: none
// postconditions: a new MovieBST is created with all variables empty
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
MovieBST<T>::MovieBST()
{
	root = NULL;
}

// --------------------------------------------MovieBST Deconstructor---------------------------------------------- 
// Description
// MovieBST: Deconstructor for the Client
// preconditions: MovieBST exists
// postconditions: a MovieBST deleted, then the memory is deallocated
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
MovieBST<T>::~MovieBST()
{
	destructorHelper(root);
}


// -------------------------------------------------insert--------------------------------------------------------- 
// Description
// insert: method to insert a TreeNode to the MovieBST
// preconditions: MovieBST exists
// postconditions: a TreeNode is inserted into the MovieBST
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
bool MovieBST<T>::insert(T * movie)
{
	return insertHelper(movie, root);
}

// ---------------------------------------------------retrieve----------------------------------------------------- 
// Description
// retrieve: a TreeNode is retrieved from the MovieBST
// preconditions: MovieBST exists
// postconditions: a TreeNode is retrieved from the MovieBST
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
T* MovieBST<T>::retrieve(const T * movie)
{
	return retrieveHelper(movie, root);
}

// --------------------------------------------------printTree----------------------------------------------------- 
// Description
// printTree: Prints the MovieBST to the console
// preconditions: MovieBST exists
// postconditions: Prints the MovieBST to the console
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
void MovieBST<T>::printTree()
{
	printTreeHelper(root);
}
// ------------------------------------------------insertHelper---------------------------------------------------- 
// Description
// insert: method to insert a TreeNode to the MovieBST
// preconditions: MovieBST exists
// postconditions: a TreeNode is inserted into the MovieBST
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
bool MovieBST<T>::insertHelper(T * movie, TreeNode *& root)
{
	if (root == NULL) {
		root = new TreeNode(movie);
		return true;
	}
	else if (*movie < *(root->data)) {
		return insertHelper(movie, root->left);
	}
	else  if (*movie > *(root->data)) {
		return insertHelper(movie, root->right);
	}
	else {
		return false;
	}
}

// ------------------------------------------------retrieveHelper---------------------------------------------------- 
// Description
// retrieve: method to retrieve a TreeNode to the MovieBST
// preconditions: MovieBST exists
// postconditions: a TreeNode is retrieved into the MovieBST
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
T * MovieBST<T>::retrieveHelper(const T* movie, TreeNode *& root)
{
	if (root == NULL) {
		return NULL;
	}
	else if (*movie == *(root->data)) {
		return root->data;
	}
	else if (*movie < *(root->data)) {
		return retrieveHelper(movie, root->left);
	}
	else {
		return retrieveHelper(movie, root->right);
	}
}

// ------------------------------------------------destructorHelper---------------------------------------------------- 
// Description
// destructor: method to delete all TreeNodes
// preconditions: MovieBST exists
// postconditions: ll tree nodes are delted
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
void MovieBST<T>::destructorHelper(TreeNode *& root)
{
	if (root == NULL) {
		return;
	}
	else {
		TreeNode* leftChild = root->left;
		TreeNode* rightChild = root->right;
		delete root;
		destructorHelper(leftChild);
		destructorHelper(rightChild);
	}
}

// ------------------------------------------------printTreeHelper---------------------------------------------------- 
// Description
// destructor: method to print all TreeNodes
// preconditions: MovieBST exists
// postconditions: all elements of tree printed
// ----------------------------------------------------------------------------------------------------------------
template<typename T>
void MovieBST<T>::printTreeHelper(TreeNode *& root)
{
	if (root == NULL) {
		return;
	}
	else {
		printTreeHelper(root->left);
		cout << *(root->data) << endl;
		printTreeHelper(root->right);
	}
}
#endif

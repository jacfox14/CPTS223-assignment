#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;


/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */

template <typename Comparable>
class BST
{
public:
	BST();
	~BST();
	void makeEmpty();

	const Comparable & findMin() const;
	const Comparable & findMax() const;

	bool contains(const Comparable & x) const;
	void insert(const Comparable & x);
	void remove( const Comparable & x);
	int treeSize() const;
	int treeHeight() const;
	void printInOrder() const;
	void printLevels() const;
	void printMaxPath() const;

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt): element(theElement), left(lt), right(rt) {}
		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt): element(move(theElement)), left(lt), right(rt) {}
	};

	BinaryNode *root;

	BinaryNode * findMin( BinaryNode * t ) const;
	BinaryNode * findMax( BinaryNode * t ) const;
	void makeEmpty( BinaryNode * & t );
	void insert( const Comparable & x, BinaryNode * & t );
	void remove( const Comparable & x, BinaryNode * & t );
	bool contains( const Comparable & x, BinaryNode *t ) const;
	int treeSize( BinaryNode *t ) const;
	int treeHeight( BinaryNode *t ) const;
	void printInOrder( BinaryNode *t ) const;
	void printLevels( BinaryNode *t ) const;
	void printMaxPath( BinaryNode *t ) const;
	int maxPathSum(BinaryNode *t) const;

};


/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */

// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(NULL) {}

// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
	makeEmpty();
}

// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// // public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMin(root)->element;
}

// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMax(root)->element;
}

// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMin(t->right);
    }
}

// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x ) const {
	cout << "**TODO**: contains function" << endl;
	
	return contains(x, root);
}

// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x) {
	cout << "**TODO**: insert function" << endl;

	insert(x, root);

}


// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x) {

	cout << "**TODO**: remove function" << endl;
	remove(x, root);
	
}

// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize() const {
	cout << "**TODO**: treeSize function" << endl;
	return treeSize(root);
}

// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight() const {
	cout << "**TODO**: treeHeight function" << endl;
	return treeHeight(root);
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const {
	cout << "**TODO**: printInOrder function\n" << endl;
	printInOrder(root);
}

// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
	cout << "**TODO**: printLevels function" << endl;
	printLevels(root);
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath() const {
	cout << "**TODO**: printMaxPath function" << endl;
	printMaxPath(root);
}

// private remove
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x, BinaryNode * & t ) {
	if (t == nullptr) {
		return;
	}

	if (x < t->element) {
		// Go left in the tree
		remove(x, t->left);
	}
	else if (x > t->element) {
		// Go right in the tree
		remove(x, t->right);
	}
	else {
		// Node found
		if (t->left != nullptr && t->right != nullptr) {
			// Node has two children
			t->element = findMin(t->right)->element;  // Replace with min of right subtree
			remove(t->element, t->right);             // Remove that node from the right subtree
		}
		else {
			// Node has one or no children
			BinaryNode* oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;  // Replace with child or nullptr
			delete oldNode;
		}
	}
}

// private insert
template<typename Comparable>
void BST<Comparable>::insert( const Comparable & x, BinaryNode * & t ) {
	if (t == nullptr) {
		t = new BinaryNode{x, nullptr, nullptr};
	}
	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (x > t->element) {
		insert(x, t->right);
	}
	else {
		// Duplicate, do nothing
	}
}

// private contains
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x, BinaryNode *t ) const {
	if (t == nullptr) {
		return false;
	}
	else if (x < t->element) {
		return contains(x, t->left);
	}
	else if (x > t->element) {
		return contains(x, t->right);
	}
	else {
		return true;
	}
}

// private treeSize
template<typename Comparable>
int BST<Comparable>::treeSize( BinaryNode *t ) const {
	if (t == nullptr) {
		return 0;
	}
	else {
		return 1 + treeSize(t->left) + treeSize(t->right);
	}
}

// private treeHeight
template<typename Comparable>
int BST<Comparable>::treeHeight( BinaryNode *t ) const {
	if (t == nullptr) {
		return -1;
	}
	else {
		return 1 + max(treeHeight(t->left), treeHeight(t->right));
	}
}

// private printInOrder
template<typename Comparable>
void BST<Comparable>::printInOrder( BinaryNode *t ) const {
	if (t != nullptr) {
		printInOrder(t->left);
		cout << t->element << " ";
		printInOrder(t->right);
	}
}

// private printLevels
template<typename Comparable>
void BST<Comparable>::printLevels(BinaryNode* t) const {
    if (t == nullptr) {
        return;
    }

    queue<BinaryNode*> q;
    q.push(t);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            BinaryNode* current = q.front();
            q.pop();

            cout << current->element << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
}

// private printMaxPath
template<typename Comparable>
void BST<Comparable>::printMaxPath( BinaryNode *t ) const {
	
	if (t == nullptr)
		return;

	
	if (maxPathSum(t->left) > maxPathSum(t->right)) {
		std::cout << t->element << " ";   // Print current node
		printMaxPath(t->left);            // Go left
	} else {
		std::cout << t->element << " ";   // Print current node
		printMaxPath(t->right);           // Go right
	}

}


// private maxPathSum
template<typename Comparable>
int BST<Comparable>::maxPathSum(BinaryNode *t) const {
    if (t == nullptr) {
        return 0;  // Base case
    }

    
    int leftSum = maxPathSum(t->left);
    int rightSum = maxPathSum(t->right);

    return t->element + std::max(leftSum, rightSum);
}




#endif

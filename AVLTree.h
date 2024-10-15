#pragma once

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template <typename Comparable>
class AVLTree
{
public:
    
    AVLTree();
    ~AVLTree();

    void makeEmpty();
    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;
    int computeHeight() const;
    int readRootHeight() const;
    bool isBalanced() const;
    bool isBST() const;
    int getBalance() const;

    double averageDepth() const;
    void removeByRank(int rank);

    // the next line follows textbook Figure 4.42, Line 19
    static const int ALLOWED_IMBALANCE = 1;
private:
    struct AVLNode  // refer to textbook, Figure 4.40
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt ): element(theElement), left(lt), right(rt) {}
        AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt ): element(move(theElement)), left(lt), right(rt) {}
    };

    AVLNode *root;

    AVLNode * findMin( AVLNode * t ) const;
    AVLNode * findMax( AVLNode * t ) const;
    void makeEmpty( AVLNode * & t );
    void insert( const Comparable & x, AVLNode * & t );
    void balance(AVLNode * & t);
    bool contains( const Comparable & x, AVLNode *t ) const;
    void rotateWithLeftChild( AVLNode * & t );
    void rotateWithRightChild( AVLNode * & t );
    void doubleWithLeftChild( AVLNode * & t);
    void doubleWithRightChild( AVLNode * & t);
    int getBalance(AVLNode *N)const;
    bool isBalanced(AVLNode *t) const;
    bool isBST(AVLNode *t) const;
    int computeHeight(AVLNode *t) const;
    int treeSize(AVLNode *t) const;
    double averageDepth(AVLNode *t, int depth) const;
    void removeByRank(int rank, AVLNode * & t);
    int readRootHeight(AVLNode *t) const;
    
   
};

// constructor
template <class Comparable>
AVLTree<Comparable>::AVLTree() : root(NULL) {}

// destructor
template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

// public makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root); 
}

// private recursive makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode * & t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// public findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}

// private findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMin(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMax() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element; 
}

// private findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMax(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// start our implementation:
// public contains: follow the contains in BST, referring to textbook, Figure 4.17 and Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x ) const{
   
    cout << "TODO: contains function" << endl;
    return contains(x, root);

}

// private contains: follow the contains in BST, referring to textbook, Figure 4.17 and Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x, AVLNode *t ) const {
    
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

// public insert: following BST, referring to textbook, Figure 4.17 and Figure 4.23
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x) {
    
    cout << "TODO: insert function" << endl;

    insert(x, root);

}

// private insert: following BST, referring to textbook, Figure 4.17 and Figure 4.23
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x, AVLNode * & t) {
    
    
    if (t == nullptr) {
        t = new AVLNode(x, nullptr, nullptr);
    }
    else if (x < t->element) {
        if(t->left == nullptr) {
            t->left = new AVLNode(x, nullptr, nullptr);
        }
        else {
            insert(x, t->left);
        }
    }
    else if (x > t->element) {
        if(t->right == nullptr) {
            t->right = new AVLNode(x, nullptr, nullptr);
        }
        else {
            insert(x, t->right);
        }
    }
    else {
        // do nothing
    }
    
    balance(t);

}

// public remove: refer to textbook, Figure 4.17 and Figure 4.26
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x ) {
    cout << "TODO: remove function" << endl;
    remove(x, root);
}

// private balance: refer to textbook, Figure 4.42, Line 21 - 40
// assume t is the node that violates the AVL condition, and we then identify which case to use (out of 4 cases)
template<typename Comparable>
void AVLTree<Comparable>::balance(AVLNode * & t) {
    cout << "TODO: balance function" << endl;

    if (t == nullptr) {
        return;
    } else if (isBalanced(t)) {
        cout << "Tree is balanced" << endl;
        return;
    } else if (computeHeight(t->left) - computeHeight(t->right) > ALLOWED_IMBALANCE) {
        if (computeHeight(t->left->left) >= computeHeight(t->left->right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (computeHeight(t->right) - computeHeight(t->left) > ALLOWED_IMBALANCE) {
        if (computeHeight(t->right->right) >= computeHeight(t->right->left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }

    t->height = max(computeHeight(t->left), computeHeight(t->right)) + 1;

}

// private rotateWithLeftChild: for case 1, referring to textbook, Figure 4.44 (code) and Figure 4.43 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode * & k2) {
    
    cout << "TODO: rotateWithLeftChild function" << endl;

    AVLNode *k1 = k2->left;

    if (k1 == nullptr) return;

    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(computeHeight(k2->left), computeHeight(k2->right)) + 1;
    k1->height = max(computeHeight(k1->left), k2->height) + 1;
    k2 = k1;
    

}

// private rotateWithRightChild: for case 4 (the mirrored case of case 1)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode * & k2) {
    
    cout << "TODO: rotateWithRightChild function" << endl;

    AVLNode *k1 = k2->right;

    if (k1 == nullptr) return;

    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(computeHeight(k2->left), computeHeight(k2->right)) + 1;
    k1->height = max(computeHeight(k1->right), k2->height) + 1;
    k2 = k1;

}

// private doubleWithLeftChild: for case 2, see textbook, Figure 4.46 (code) and Figure 4.45 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode * & k3) {
   
    cout << "TODO: doubleWithLeftChild function" << endl;
    rotateWithLeftChild(k3->left);
    rotateWithRightChild(k3);

}

// private doubleWithRightChild: for case 3 (the mirrored case of case 2)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode * & k3) {
    cout << "TODO: doubleWithRightChild function" << endl;
    rotateWithRightChild(k3->right);
    rotateWithLeftChild(k3);
}

// public isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced() const {
    cout << "TODO: isBalanced function" << endl;
    return isBalanced(root);
}

// public isBST
template <class Comparable>
bool AVLTree<Comparable>::isBST() const {
   
    cout << "TODO: isBST function" << endl;
    return isBST(root);
}

// public treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize() const {
   cout << "TODO: treeSize function" << endl;
    
    return treeSize(root);
}

// private treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize(AVLNode *t) const {
    if (t == nullptr) {
        return 0;
    }
    return 1 + treeSize(t->left) + treeSize(t->right);
}

// public computeHeight. See Figure 4.61 in Textbook
template <typename Comparable>
int AVLTree<Comparable>::computeHeight() const {
    cout << "TODO: computeHeight function" << endl;
    return computeHeight(root);
}

// private computeHeight
template <typename Comparable>
int AVLTree<Comparable>::computeHeight(AVLNode *t) const {
    if (t == nullptr) {
        return -1;
    }
    return 1 + max(computeHeight(t->left), computeHeight(t->right));
}

// public readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight() const {
    cout << "TODO: readRootHeight function" << endl;
    return readRootHeight(root);
}

// private readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight(AVLNode *t) const {
    if (t == nullptr) {
        return -1;
    }
    return computeHeight(t);
}

// public averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth() const {
    cout << "TODO: averageDepth function" << endl;
    return averageDepth(root, 0);
}

// private averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth(AVLNode *t, int depth) const {
    if (t == nullptr) {
        return 0;
    }
    return depth + averageDepth(t->left, depth + 1) + averageDepth(t->right, depth + 1);
}

// public removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank) {
    cout << "TODO: removeByRank function" << endl;
    removeByRank(rank, root);
}

// private removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank, AVLNode * & t) {
    if (t == nullptr) {
        return;  
    }

    int leftSize = treeSize(t->left);  

    if (rank < leftSize) {
        removeByRank(rank, t->left);
    } else if (rank > leftSize) {
        removeByRank(rank - leftSize - 1, t->right);
    } else {
        
        if (t->left == nullptr || t->right == nullptr) {
            AVLNode *temp = (t->left != nullptr) ? t->left : t->right; 
            delete t;  
            t = temp;  
        } else {
            
            AVLNode *minNode = findMin(t->right);  
            t->element = minNode->element;  
            removeByRank(0, t->right);  
        }

    }

    balance(t);
}


// public getBalance
template <typename Comparable>
int AVLTree<Comparable>::getBalance() const {
    return getBalance(root);
}

// private getBalance
template <typename Comparable>
int AVLTree<Comparable>::getBalance(AVLNode *N) const{ 
    if (N == nullptr) 
        return 0; 
    return computeHeight(N->left) - computeHeight(N->right); 
} 

// private isBalanced
template <typename Comparable>
bool AVLTree<Comparable>::isBalanced(AVLNode *t) const{

    int balance = getBalance();
    if (balance > 1 || balance < -1){
        return false;
    } else {
        return true;
    }

}

// private isBST
template <typename Comparable>
bool AVLTree<Comparable>::isBST(AVLNode *t) const{

    if (t == nullptr) {
        return true;
    }

    if (t->left != nullptr && t->left->element > t->element) {
        return false;
    }

    if (t->right != nullptr && t->right->element < t->element) {
        return false;
    }

    return isBST(t->left) && isBST(t->right);


}



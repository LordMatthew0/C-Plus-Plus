/*
Matthew Lord
z1848456
10/30/2018
Assignment 6
*/

#ifndef H_PROG6
#define H_PROG6

//#include "/home/cs340/progs/18f/p6/Node.h"
#include "Node.h"
template < class T > class binTree {
public:
    binTree ( ); // default constructor
    unsigned height ( ) const; // returns height of tree
    virtual void insert ( const T& ); // inserts node in tree
    void inorder ( void ( * ) ( const T& ) ); // inorder traversal of tree
protected:
    Node < T >* root; // root of tree
private:
    unsigned height ( Node < T >* ) const; // private version of height ( )
    void insert ( Node < T >*&, const T& ); // private version of insert ( )
    void inorder ( Node < T >*, void ( * ) ( const T& ) );// private version of inorder ( )
};

typedef enum { left_side, right_side } SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }

template < class T >
void binTree<T>::insert ( const T& x ){
    Node<T> *newNode, *prev, *curr;
    newNode = new Node<T>(x);
    if (root == NULL) root = newNode;
    else {
        if(rand() == 0){
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
    }
}
template < class T >
void inorder ( void ( * fnc ) ( const T& ) ){
    //fnc(T);
}

#endif

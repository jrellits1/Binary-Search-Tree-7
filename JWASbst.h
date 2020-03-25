//Joshua Stiller Project 7.
#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include "JWASNode.h"
#include <string>
using namespace std;

class BST
{
private:
    BSTNode * root;

protected:
    BSTNode * Insert(BSTNode * node, int key, string name);
    void PrintTreeInOrder(BSTNode * node);
    void PrintTreePreOrder(BSTNode * node);
    void PrintTreePostOrder(BSTNode * node);
    BSTNode * Search(BSTNode * node, int key);
    BSTNode * SearchForName(BSTNode * node, string name);
    int FindMin(BSTNode * node);
    int FindMax(BSTNode * node);
    int Successor(BSTNode * node);
    int Predecessor(BSTNode * node);
    BSTNode * Remove(BSTNode * node, int v);

public:
    BST();
    void Insert(int key, string name);
    void PrintTreeInOrder();
    void PrintTreePreOrder();
    void PrintTreePostOrder();
    bool Search(int key);
    bool SearchForName(string name);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
    void Remove(int v);
};
#endif // BSTNODE_H

/*
 _______________________________
|     - root : BSTNode          |
|_______________________________|
|     + BST : BST               |
|     + printtreeinorder : void |
|     + remove : void           |
|     + Search  : bool          |
|     + SearchForName : bool    |
|     + FindMin : int           |
|     + Find Max : int          |
|     + Successor : int         |
|     + Predecessor : int       |
_________________________________
|     #  insert : BSTNode       |
|     #  printtreeinorder : void|
|     #  search : BSTNode       |
|     #  searchforname : BSTNode|
|     #  findmin : int          |
|     #  findmax : int          |
|     #  successor : int        |
|     #  predecessor : int      |
|     #  remove : BSTNode       |
|_______________________________|
*/

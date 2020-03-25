//Joshua Stiller Project 7.
#include "JWASbst.h"
#include "JWASNode.h"

BST::BST() : root(NULL)
{
}

void BST::Insert(int key, string name)
{
    // Invoking Insert() function
    // and passing root node and given key
    root = Insert(root, key, name);
}

void BST::PrintTreeInOrder()
{
    // Traverse the BST
    // from root node
    // then print all keys
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

void BST::PrintTreePreOrder(){
    PrintTreePreOrder(root);
    std::cout << std::endl;
}

void BST::PrintTreePostOrder(){
    PrintTreePostOrder(root);
    cout << endl;
}

bool BST::Search(int key)
{
    // Invoking Search() operation
    // and passing root node
    BSTNode * result = Search(root, key);

    // If key is found, returns TRUE
    // otherwise returns FALSE
    return result == NULL ?
        false :
        true;
}

bool BST::SearchForName(string name){
    BSTNode * result = SearchForName(root, name);

    return result == NULL ?
        false :
        true;
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Successor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // successor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Successor(keyNode);
}

int BST::Predecessor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // predecessor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Predecessor(keyNode);
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}


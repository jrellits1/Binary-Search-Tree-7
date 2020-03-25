//Joshua Stiller Project 7
#include "JWASbst.h"
#include "JWASNode.h"
#include <string>
using namespace std;

BSTNode::BSTNode(){}

BSTNode::BSTNode(int key, string name) : Left(NULL), Right(NULL), Parent(NULL){}

BSTNode * BST::Insert(BSTNode * node, int key, string name)
{
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = new BSTNode();
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
        node->setname(name);
    }
    // If the given key is greater than
    // node's key then go to right subtree
    else if(node->Key < key)
    {
        node->Right = Insert(node->Right, key, name);
        node->Right->Parent = node;
    }
    // If the given key is smaller than
    // node's key then go to left subtree
    else
    {
        node->Left = Insert(node->Left, key, name);
        node->Left->Parent = node;
    }

    return node;
}

void BST::PrintTreeInOrder(BSTNode * node)
{
    // Stop printing if no node found
    if(node == NULL)
        return;

    // Get the smallest key first
    // which is in the left subtree
    PrintTreeInOrder(node->Left);

    // Print the key
    std::cout << node->Key << " " << node-> getname() << endl;

    // Continue to the greatest key
    // which is in the right subtree
    PrintTreeInOrder(node->Right);
}

void BST::PrintTreePreOrder(BSTNode * node){
    if(node == NULL)
        return;

    std::cout << node->Key << " " << node-> getname()<< endl;

    PrintTreePreOrder(node->Left);

    PrintTreePreOrder(node->Right);
}

void BST::PrintTreePostOrder(BSTNode * node){
    if(node == NULL)
        return;

    PrintTreePostOrder(node->Left);


    PrintTreePostOrder(node->Right);

    std::cout << node->Key << " " << node-> getname()<< endl;
}

BSTNode * BST::Search(BSTNode * node, int key)
{
    // The given key is
    // not found in BST
    if (node == NULL)
        return NULL;
    // The given key is found
    else if(node->Key == key)
        return node;
    // The given is greater than
    // current node's key
    else if(node->Key < key)
        return Search(node->Right, key);
    // The given is smaller than
    // current node's key
    else
        return Search(node->Left, key);
}

BSTNode * BST::SearchForName(BSTNode * node, string name){
    if (node == NULL)
        return NULL;

    else if(node->getname() == name)
        return node;

    else if(node->getname() < name)
        return SearchForName(node->Right, name);

    else
        return SearchForName(node->Left, name);
}

int BST::FindMin(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}

int BST::FindMax(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

int BST::Successor(BSTNode * node)
{
    // The successor is the minimum key value
    // of right subtree
    if (node->Right != NULL)
    {
        return FindMin(node->Right);
    }
    // If no any right subtree
    else
    {
        BSTNode * parentNode = node->Parent;
        BSTNode * currentNode = node;

        // If currentNode is not root and
        // currentNode is its right children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the successor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Predecessor(BSTNode * node)
{
    // The predecessor is the maximum key value
    // of left subtree
    if (node->Left != NULL)
    {
        return FindMax(node->Left);
    }
    // If no any left subtree
    else
    {
        BSTNode * parentNode = node->Parent;
        BSTNode * currentNode = node;

        // If currentNode is not root and
        // currentNode is its left children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the predecessor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

BSTNode * BST::Remove(BSTNode * node,int key)
{
    // The given node is
    // not found in BST
    if (node == NULL)
        return NULL;

    // Target node is found
    if (node->Key == key)
    {
        // If the node is a leaf node
        // The node can be safely removed
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        // The node have only one child at right
        else if (node->Left == NULL && node->Right != NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Right->Parent = node->Parent;

            // Bypass node
            node = node->Right;
        }
        // The node have only one child at left
        else if (node->Left != NULL && node->Right == NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Left->Parent = node->Parent;

            // Bypass node
            node = node->Left;
        }
        // The node have two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);

            // Replace node's key with successor's key
            node->Key = successorKey;

            // Delete the old successor's key
            node->Right = Remove(node->Right, successorKey);
        }
    }
    // Target node's key is smaller than
    // the given key then search to right
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    // Target node's key is greater than
    // the given key then search to left
    else
        node->Left = Remove(node->Left, key);

    // Return the updated BST
    return node;
}

void BSTNode::setname(string namestr){
    name = namestr;
}

string BSTNode::getname(){
    return name;
}

//Joshua Stiller Project 7
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class BSTNode
{
public:
    BSTNode();
    BSTNode(int key, string name);
    int Key;
    BSTNode * Left;
    BSTNode * Right;
    BSTNode * Parent;
    int Height;
    string name;
    void setname(string name);
    string getname();
private:
    string name;

//Here is the UML Diagram for the .h file.
/*
 ____________________________________
|   - name : string                  |
|____________________________________|
|   + BSTNode : BSTNode              |
|   + BSTNode : Left                 |
|   + BSTNode : Right                |
|   + BSTNode : Parent               |
|   + height : int                   |
|   + name : string                  |
|____________________________________|

*/
};
#endif // NODE_H

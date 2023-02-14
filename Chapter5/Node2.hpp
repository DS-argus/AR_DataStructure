#include <iostream>

class Node{
    Node* link;
    int data;

public:
    Node(int val=0): data(val) ,link(NULL){}

    Node* getLink(){return link;}

    void setLink(Node* p){link = p;}

    void display(){printf(" <%d>", data);}
};
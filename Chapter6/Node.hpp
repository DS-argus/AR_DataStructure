#include <iostream>

class Node{
    int data;
    Node* link;

public:
    Node(int data=0):data(data), link(NULL){}

    Node* getLink(){
        return link;
    }

    void setLink(Node* next){
        link = next;
    }

    void display(){
        std::cout << " <" << data << ">" << std::endl;
    }

    bool hasData(int val){
        return val == data;
    }

    void insertNext(Node* node){
        if (node != NULL)
        {
            node->link = link;
            link = node;
        }
        
    }

    Node* removeNext(){

        Node* removed = link;

        if (removed != NULL)
        {
            link = removed->link;
        }
        return removed;
    }
};
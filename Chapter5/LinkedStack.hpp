#include "Node.hpp"

class LinkedStack{
    Node* top;

public:
    LinkedStack(){
        top = NULL;
    }

    ~LinkedStack(){
        while (!isEmpty())
        {
            delete pop();
        }
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(Node* item){

        if (isEmpty())
        {   
            top = item;
        }
        else
        {
            item->setLink(top);
            top = item;
        }
    }

    Node* pop(){
        if (isEmpty())
        {
            return NULL;
        }
        
        Node* target = top;

        top = top->getLink();

        return target;
    }

    Node* peek(){
        if (isEmpty())
        {
            return NULL;
        }
        
        return top;
    }

    void display(){
        std::cout << "[LinkedStack]\n" << "\n";
        
        // 1. while 문 활용
        Node* curNode = top;
        while (curNode != NULL)
        {
            curNode->display();
            curNode = curNode->getLink();
        }

        // // 2. for loop 활용
        // for (Node *p = top; p != NULL; p=p->getLink())
        // {
        //     p->display();
        // }
        
        std::cout << "\n";
    }   
};
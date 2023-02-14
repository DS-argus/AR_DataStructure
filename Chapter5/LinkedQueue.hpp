#include "Node2.hpp"

class LinkedQueue{
    Node* front;
    Node* rear;

public:
    LinkedQueue(): front(NULL), rear(NULL){}

    ~LinkedQueue(){

        // 1.
        Node* p = front;

        while (p != NULL)
        {
            delete dequeue();

            p = p->getLink();
        }

        //2. 
        // while (!isEmpty())
        // {
        //     delete dequeue();
        // }
    };

    bool isEmpty(){
        return front == NULL;
    }

    void enqueue(Node* item){
        if (isEmpty())
        {
            rear = item;
            front = item;
        }
        else
        {
            rear->setLink(item);
            rear = item;
        }
    }

    Node* dequeue(){
        if (isEmpty()) return NULL;
        
        Node* target = front;

        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->getLink();
        }
        return target;
    }

    Node* peek(){
        return front;
    }

    void display(){
        printf("[LinkedQueue]\n");
        if (isEmpty()){
            printf("Empty\n");
            return; 
        } 
        
        for (Node* p = front; p != rear->getLink(); p = p->getLink())
        {
            p->display();
        }
        printf("\n");
    }

};
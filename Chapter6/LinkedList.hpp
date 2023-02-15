#include "Node.hpp"


class LinkedList{
    Node org;

public:
    LinkedList(): org(0) {}
    ~LinkedList(){clear();}
    
    void clear(){
        while (!isEmpty())
        {
            delete remove(0);
        }        
    }

    Node* getHead(){return org.getLink();}

    bool isEmpty(){return getHead() == NULL;}
    
    // pos에 해당하는 node가 없으면 가장 마지막 node return
    Node* getEntry(int pos){

        Node* n = &org;

        for (int i = -1; i < pos; i++)
        {
            if (n == NULL) {
                break;
            }

            n = n->getLink();
        }

        return n;
    }

    void insert(int pos, Node* node){
        Node* prev = getEntry(pos-1);
        if (prev != NULL)
        {
            prev->insertNext(node);
        }
    }

    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev->removeNext();
    }


    Node* find(int item){
        for (Node *p = getHead(); p != NULL; p=p->getLink())
        {
            if (p->hasData(item))
            {
                return p;
            }
        }
        return NULL;
    }

    void replace(int pos, Node* node){
        Node* prev = getEntry(pos-1);

        if (prev != NULL)
        {
            delete prev->removeNext();
            prev->insertNext(node);
        }
    }

    int size(){
        int count = 0;

        for (Node* p = getHead(); p != NULL; p = p->getLink())
        {
            count++;
        }

        return count;
    }

    void display(){
        std::cout << "[전체 항목 수 = " << size() << "]" << std::endl;
        for (Node* p = getHead(); p != NULL; p = p->getLink())
        {
            p->display();
        }       
        std::cout << std::endl; 
    }
};
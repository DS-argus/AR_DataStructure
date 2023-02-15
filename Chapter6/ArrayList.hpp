#include <iostream>
#define MAX_LIST_SIZE 100


class ArrayList{
    int data[MAX_LIST_SIZE];
    int length;

public:
    ArrayList(){
        length = 0;
    }

    int getEntry(int pos){
        return data[pos];
    }

    bool isEmpty(){
        return length == 0;
    }

    bool isFull(){
        return length == MAX_LIST_SIZE;
    }

    bool find(int item){
        for (int i = 0; i < length; i++)
        {
            if (data[i] == item)
            {
                return true;
            }
        }    
        return false;    
    }

    int size(){
        return length;
    }

    void replace(int pos, int item){
        data[pos] = item;
    }

    void insert(int pos, int item){
       if (!isFull() && pos >= 0 && pos <= length)
       {
            for (int i = length; i >pos; i--)
            {
                data[i] = data[i-1];
            }
            data[pos] = item;
            length++;
            
       }
       else{
        printf("ERROR: List is Full or Wrong Insert Location");
       }
    }

    void remove(int pos){
        if (!isEmpty() && pos >= 0 && pos < length)
        {
            for (int i = pos; i < length - 1; i++)
            {
                data[i] = data[i+1];
            }
            length--;
        }
        else{
            printf("ERROR: List is Empty or Wrong Remove Location");
        }        
    }

    void display(){
        std::cout << "[Total length of List implemented by array = "<< size() << "] : " << std::endl;
        for (int i = 0; i < length; i++)
        {
            std::cout << "[" << data[i] << "] ";
        }
        std::cout << std::endl;
    }

    void clear(){
        length = 0;
    }
};
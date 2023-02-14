#include "LinkedQueue.hpp"

int main(){
    LinkedQueue que;

    for (int i = 0; i < 10; i++)
    {
        que.enqueue(new Node(i));
    }

    que.display();

    delete que.dequeue();
    delete que.dequeue();
    delete que.dequeue();
    
    que.display();
    
}
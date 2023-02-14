#include "LinkedStack.hpp"

int main(){
    LinkedStack stack;

    stack.push(new Node(2015130007, "Peter", "CS"));
    stack.push(new Node(2018193831, "James", "Business"));
    stack.push(new Node(2012494013, "Damon", "Economics"));
    stack.display();

    Node* node = stack.pop();

    printf("[Pop element]\n");
    node->display();
    printf("\n");
 
    delete node;

    stack.display();
}
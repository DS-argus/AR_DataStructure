#include "Student.hpp"

class Node : public Student{
    Node* link;

public:
    // initializer
    Node(int id=0, std::string name="", std::string dept=""): Student(id, name, dept){
        link = NULL;
    }
    
    // destructor
    ~Node(void){}

    Node* getLink(){
        return link;
    }

    void setLink(Node* p){
        link = p;
    }
};
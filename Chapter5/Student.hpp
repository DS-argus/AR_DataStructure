#include <iostream>

class Student{
    int id;
    std::string name;
    std::string dept;

public:
    // initializer
    Student(int i=0, std::string n="", std::string d=""){
        set(i, n, d);
    }

    // destructor
    void set(int i, std::string n, std::string d){
        id = i;
        name = n;
        dept = d;
    }

    void display(){
        std::cout << "ID: " << id << " Name: " << name << " dept: " << dept << std::endl;
    }
};
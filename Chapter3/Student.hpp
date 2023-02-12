#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {

private:
	int id;
	string name;
	string dept;

public:

	Student() {
		id = 0;
		name = "";
		dept = "";
	}

	Student(int i, string n, string d):id(i), name(n), dept(d) {}

	
	void set(int i, string n, string d) {
		id = i;
		name = n;
		dept = d;
	}
	

	void display() {
		printf(" Student ID:%-15d Name:%-10s Major:%-20s\n", id, name.c_str(), dept.c_str());
	}
	
};
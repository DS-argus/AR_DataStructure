#pragma once

#include "Student.hpp"

class StudentStack {
private:
	int top;
	Student data[MAX_STACK_SIZE];

public:
	StudentStack() { top = -1; }
	
	bool isEmpty() { return top == -1; }

	bool isFull() { return top == MAX_STACK_SIZE; }

	void push(Student&& e) {
		if (isFull()) error("Full stack error");
		data[++top] = e;
	}

	Student& pop() {
		if (isEmpty()) 	error("Empty stack error");
		return data[top--];
	}

	Student& peek() {
		if (isEmpty()) error("Empty stack error");
		return data[top];
	}

	void display() {
		printf("[Total students = %2d]\n", top + 1);

		for (int i = 0; i <= top ; i++)
		{
			data[i].display();
		}
		printf("\n");
	}
};
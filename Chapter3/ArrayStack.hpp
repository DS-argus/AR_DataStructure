#pragma once
#include <iostream>

class ArrayStack {
private:
	int top;
	int data[MAX_STACK_SIZE];

public:
	ArrayStack() { top = -1; }
	~ArrayStack(){}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if (isFull())
		{
			error("Full stack error");
		}

		top += 1;
		data[top] = e;
		
	}

	int pop() {
		if (isEmpty())
		{
			error("Empty stack error");
		}

		top -= 1;
		return data[top + 1];
	}

	int peek() {
		if (isEmpty())
		{
			error("Empty stack error");
		}

		return data[top];
	}

	void display() {
		printf("[Number of stack elements = %2d] ==> ", top + 1);

		for (int i = 0; i <= top; i++)
		{
			printf("<%2d>", data[i]);
		}
		printf("\n");
	}

};
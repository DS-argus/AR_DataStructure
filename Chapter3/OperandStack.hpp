#pragma once
#include<iostream>

class OperandStack {
private:
	double data[MAX_STACK_SIZE];
	int top;

public:
	OperandStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(double e) {
		if (isFull()) error("Full stack error");
		data[++top] = e;
	}

	double pop() {
		if (isEmpty()) error("Empty stack error");
		return data[top--];
	}
};
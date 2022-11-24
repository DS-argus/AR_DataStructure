#pragma once
#include<iostream>

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() 함수는 저장+프로세스 종료 의미, exit(1)은 에러메세지 종료, exit(0)은 정상종료
}

const int MAX_STACK_SIZE = 100;

class OperandStack {
private:
	double data[MAX_STACK_SIZE];
	int top;

public:
	OperandStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(double e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}

	double pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
};
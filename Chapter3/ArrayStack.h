#pragma once
#include <iostream>

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() 함수는 저장+프로세스 종료 의미, exit(1)은 에러메세지 종료, exit(0)은 정상종료
}

const int MAX_STACK_SIZE = 20;

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
			error("스택 포화 에러");
		}

		top += 1;
		data[top] = e;
		
	}

	int pop() {
		if (isEmpty())
		{
			error("스택 공백 에러");
		}

		top -= 1;
		return data[top + 1];
	}

	int peek() {
		if (isEmpty())
		{
			error("스택 공백 에러");
		}

		return data[top];
	}

	void display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);

		for (int i = 0; i <= top; i++)
		{
			printf("<%2d>", data[i]);
		}
		printf("\n");
	}

};
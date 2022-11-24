#pragma once
#include "Student.h"
const int MAX_STACK_SIZE = 100;

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() 함수는 저장+프로세스 종료 의미, exit(1)은 에러메세지 종료, exit(0)은 정상종료
}

class StudentStack {
private:
	int top;
	Student data[MAX_STACK_SIZE];

public:
	StudentStack() { top = -1; }
	
	bool isEmpty() { return top == -1; }

	bool isFull() { return top == MAX_STACK_SIZE; }

	void push(Student&& e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}

	Student& pop() {
		if (isEmpty()) 	error("스택 공백 에러");
		return data[top--];
	}

	Student& peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	void display() {
		printf("[전체 학생의 수 = %2d]\n", top + 1);

		for (int i = 0; i <= top ; i++)
		{
			data[i].display();
		}
		printf("\n");
	}
};
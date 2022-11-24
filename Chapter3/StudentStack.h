#pragma once
#include "Student.h"
const int MAX_STACK_SIZE = 100;

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() �Լ��� ����+���μ��� ���� �ǹ�, exit(1)�� �����޼��� ����, exit(0)�� ��������
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
		if (isFull()) error("���� ��ȭ ����");
		data[++top] = e;
	}

	Student& pop() {
		if (isEmpty()) 	error("���� ���� ����");
		return data[top--];
	}

	Student& peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];
	}

	void display() {
		printf("[��ü �л��� �� = %2d]\n", top + 1);

		for (int i = 0; i <= top ; i++)
		{
			data[i].display();
		}
		printf("\n");
	}
};
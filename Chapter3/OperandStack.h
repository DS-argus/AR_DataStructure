#pragma once
#include<iostream>

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() �Լ��� ����+���μ��� ���� �ǹ�, exit(1)�� �����޼��� ����, exit(0)�� ��������
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
		if (isFull()) error("���� ��ȭ ����");
		data[++top] = e;
	}

	double pop() {
		if (isEmpty()) error("���� ���� ����");
		return data[top--];
	}
};
#pragma once
#include<iostream>
#include"Customer.h"
#define MAX_QUEUE_SIZE 100

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() �Լ��� ����+���μ��� ���� �ǹ�, exit(1)�� �����޼��� ����, exit(0)�� ��������
}

class CustomerQueue {
protected:
	int front;
	int rear;
	Customer data[MAX_QUEUE_SIZE];

public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }


	void enqueue(Customer val) {
		if (isFull())
		{
			error("error : ť�� ��ȭ�����Դϴ�\n");
		}
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	Customer dequeue() {
		if (isEmpty())
		{
			error("error : ť�� ��������Դϴ�\n");
		}
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	Customer peek() {
		if (isEmpty())
		{
			error("error : ť�� ��������Դϴ�\n");
		}
		else
		{
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}


	void display() {
		printf("ť ���� : ");

		int maxi;

		if (front < rear)
		{
			maxi = rear;
		}
		else
		{
			maxi = rear + MAX_QUEUE_SIZE;
		}

		for (int i = front + 1; i <= maxi; i++)
		{
			printf("[%d]", data[i % MAX_QUEUE_SIZE]);
		}
		printf("\n");

	}

};
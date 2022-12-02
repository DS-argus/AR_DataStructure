#pragma once
#include<iostream>
#include"Customer.h"
#define MAX_QUEUE_SIZE 100

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1); //exit() 함수는 저장+프로세스 종료 의미, exit(1)은 에러메세지 종료, exit(0)은 정상종료
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
			error("error : 큐가 포화상태입니다\n");
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
			error("error : 큐가 공백상태입니다\n");
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
			error("error : 큐가 공백상태입니다\n");
		}
		else
		{
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}


	void display() {
		printf("큐 내용 : ");

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
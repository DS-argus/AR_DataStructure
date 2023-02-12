#pragma once
#include <queue>
using namespace std;

double Fibonacci(int n) {
	
	queue<double> fiboqueue;

	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		fiboqueue.push(0);
		fiboqueue.push(1);
		
		for (int i = 2; i <= n; i++)
		{
			double a = fiboqueue.front();
			fiboqueue.pop();
			
			double b = fiboqueue.front();

			double c = a + b;
			fiboqueue.push(c);
		}

		fiboqueue.pop();

		return fiboqueue.front();
	}

}
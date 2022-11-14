#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
	clock_t start, finish;
	double duration;

	start = clock();

	for (int i = 0; i < 1000; i++)
	{
		cout << i << endl;

	}

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	cout << duration << "초 입니다" << endl;
}
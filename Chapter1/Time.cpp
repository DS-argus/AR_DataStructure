// 어떤 프로그램의 소요시간을 측정
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

double time() {

	clock_t start, finish;
	double duration;

	// 시작시간 
	start = clock();


	// 시작 : 소요시간을 측정할 부분
	for (int i = 0; i < 1000; i++)
	{
		cout << i << endl;

	}
	// 종료

	// 종료 시간
	finish = clock();

	// 소요시간 측정, double로 형변환하고 CLOCKS_PER_SEC로 SEC 단위로 변환
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	// cout << duration << endl;

	return duration;
}
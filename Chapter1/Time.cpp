// � ���α׷��� �ҿ�ð��� ����
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

double time() {

	clock_t start, finish;
	double duration;

	// ���۽ð� 
	start = clock();


	// ���� : �ҿ�ð��� ������ �κ�
	for (int i = 0; i < 1000; i++)
	{
		cout << i << endl;

	}
	// ����

	// ���� �ð�
	finish = clock();

	// �ҿ�ð� ����, double�� ����ȯ�ϰ� CLOCKS_PER_SEC�� SEC ������ ��ȯ
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	// cout << duration << endl;

	return duration;
}
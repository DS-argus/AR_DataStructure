#include <cstdio>
#include <iostream>

using namespace std;

void prtArr() {
	int two[10];

	for (int i = 0; i < 10; i++)
	{	
		int val = 1;

		for (int j = 0; j < i; j++)
		{
			val *= 2;
		}

		two[i] = val;
	}


	for (int val : two) {
		printf("%d\n", val);

	}
}
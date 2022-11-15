#include <iostream>
#include "Findmax1D.h"
#include "Findmax2D.h"

using namespace std;

int main()
{
	int a[4][5] = { {3,24,82,12,22},
		{34,7,12,19,21},
		{99,7,65,73,58},
		{20,7,9,48,20} };

	int maxval = findMaxPixelPointer(a, 4, 5);

	cout << maxval << endl;
}

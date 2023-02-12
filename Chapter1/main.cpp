#include <iostream>
using namespace std;

#include "Time.hpp"
#include "SequentialSearch.hpp"

int main() {

	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 11;

	int max = sequentialSearch(list, 10, key);

	cout << max << endl;

}
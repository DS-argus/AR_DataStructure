#include <iostream>
#include "Findmax1D.h"
#include "Findmax2D.h"
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial a, b, c;

	a.read();
	b.read();
	c.add(a, b);
	a.display("A= ");
	b.display("B= ");
	c.display("A+B= ");
}

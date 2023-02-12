#include <iostream>
#define _CRT_SECUER_NO_WARNINGS 

#include "Findmax1D.h"
#include "Findmax2D.h"
#include "Polynomial.h"
#include "ex3.h"
#include "ex6.h"
#include "ex7.h"
#include "ex8.h"



using namespace std;


int main()
{
	SparsePoly a, b, c;

	a.read();
	b.read();
	c.add(a, b);
	a.display("a = ");
	b.display("b = ");
	c.display("a+b = ");


}

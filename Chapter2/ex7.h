#pragma once
#define MAX_DEGREE 80

class Polynomial2 {

	int degree;
	float coef[MAX_DEGREE];

public:

	Polynomial2() { degree = 0; }

	void read();

	void display(const char* str);

	void add(Polynomial2 a, Polynomial2 b);

	void sub(Polynomial2 a, Polynomial2 b);

	void mult(Polynomial2 a, Polynomial2 b);

	void trim();

	bool isZero();

	void negate();

};
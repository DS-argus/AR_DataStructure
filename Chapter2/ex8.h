#pragma once
#define MAX_DEGREE 80

struct Term {
	int expon;
	float coeff;
};

class SparsePoly {
private:
	int num;
	Term coef[MAX_DEGREE];

public:
	void read();

	void add(SparsePoly a, SparsePoly b);

	void display(const char* str);

};
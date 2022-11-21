#include <cstdio>
#include "ex7.h"


void Polynomial2::read() {
	printf("다항식의 최고 차수를 입력하시오: ");
	scanf_s("%d", &degree);

	printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
	for (int i = 0; i <= degree; i++)
	{
		scanf_s("%f", coef + i);
	}
}

void Polynomial2::display(const char* str = "Poly = ") {
	printf("\t%s", str);
	for (int i = 0; i < degree; i++)
	{
		if (coef[i] == 0)
		{
			continue;
		}
		else if (coef[i] == 1)
		{
			printf("x^%d + ", degree - i);
		}
		else {
			printf("%5.1f x^%d + ", coef[i], degree - i);
		}
	}
	printf("%4.1f\n", coef[degree]);
}

void Polynomial2::add(Polynomial2 a, Polynomial2 b) {
	if (a.degree > b.degree)
	{
		*this = a;
		for (int i = 0; i <= b.degree; i++)
		{
			coef[i + (degree - b.degree)] += b.coef[i];
		}
	}
	else {
		*this = b;
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
}

void Polynomial2::sub(Polynomial2 a, Polynomial2 b) {
	if (a.degree > b.degree)
	{
		*this = a;
		for (int i = 0; i <= b.degree; i++)
		{
			coef[i + (degree - b.degree)] -= b.coef[i];
		}
	}
	else {
		*this = b;
		for (int i = 0; i <= a.degree; i++)
		{
			coef[i + (degree - a.degree)] -= a.coef[i];
		}

		for (int i = 0; i < b.degree; i++)
		{
			coef[i] = -coef[i];
		}
	}
}

void Polynomial2::mult(Polynomial2 a, Polynomial2 b) {
	
	*this = a;
	degree = a.degree + b.degree;

	for (int i = 0; i <= a.degree; i++)
	{
		for (int j = 0; j <= b.degree; j++)
		{
			coef[i + j] = 0;
		}
	}

	for (int i = 0; i <= a.degree; i++)
	{
		for (int j = 0; j <= b.degree; j++)
		{
			coef[i + j] += a.coef[i] * b.coef[j];
		}
	}

}


void Polynomial2::trim() {
	
	int i = 0;
	int n = 0;

	while (true)
	{
		if (coef[i] != 0)
		{
			break;
		}
		else {
			n += 1;
		}
		i += 1;
	}

	this->degree = degree - n;

	for (int i = 0; i <= degree; i++)
	{
		coef[i] = coef[i + n];
	}

}


bool Polynomial2::isZero() {
	return degree == 0;
}

void Polynomial2::negate() {
	for (int i = 0; i <= degree; i++)
	{
		coef[i] = -coef[i];
	}
}

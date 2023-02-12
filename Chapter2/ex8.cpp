#include<iostream>
#include"ex8.h"

using namespace std;


void SparsePoly::read() {
	printf("��� ���׽��� �� ������ �Է����ּ��� : ");
	scanf("%d", &num);

	printf("�� ���� (����, ���)�� �Է��Ͻÿ� (�� %d��): ", num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d, %f", &coef[i].expon, &coef[i].coeff);
	}
}


void SparsePoly::add(SparsePoly a, SparsePoly b) {
	
	// �ϴ� coef �迭�� a, b �迭 �� ä���
	//// ���� a �迭 ä���
	for (int i = 0; i < a.num; i++)
	{	
		this->coef[i] = a.coef[i];
	}

	this->num = a.num;

	//// ���� b �迭 ä��µ� expon ��ġ�� coeff ������
	for (int i = 0; i < b.num; i++)
	{
		for (int j = 0; j < a.num; j++)
		{
			if (this->coef[j].expon == b.coef[i].expon)
			{
				this->coef[j].coeff += b.coef[i].coeff;
				break;
			}

			if (j == a.num - 1)
			{
				this->coef[this->num] = b.coef[i];

				this->num += 1;
			}
		}
	}

	// ���� ����

	for (int i = 0; i < this->num - 1; i++)
	{	
		// ���� ĭ�� expon�� max�� ���
		int max = this->coef[i].expon;

		// ���� ĭ���� ������ �ϳ��� üũ�ϸ鼭
		for (int j = i + 1; j < this->num; j++)
		{	
			// max���� expon�� �� ū ĭ�� ������
			if (this->coef[j].expon > max)
			{
				Term temp = this->coef[i];
				
				// �ڸ��ٲٱ�
				this->coef[i] = this->coef[j];
				this->coef[j] = temp;

				// max ������
				max = this->coef[i].expon;
			}
		}

	}

}


void SparsePoly::display(const char* str = "SPoly = ") {
	printf("\t%s", str);
	for (int i = 0; i < this->num; i++)
	{

		if (i != this->num - 1)
		{
			printf("%5.1f x^%d + ", this->coef[i].coeff, this->coef[i].expon);
		}
		else if (this->coef[i].expon == 0)
		{
			printf("%5.1f", this->coef[i].coeff);
		}
		else
		{
			printf("%5.1f x^%d ", this->coef[i].coeff, this->coef[i].expon);
		}
	}
	printf("\n");
}


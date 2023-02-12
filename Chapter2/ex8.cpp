#include<iostream>
#include"ex8.h"

using namespace std;


void SparsePoly::read() {
	printf("희소 다항식의 항 개수를 입력해주세요 : ");
	scanf("%d", &num);

	printf("각 항의 (차수, 계수)를 입력하시오 (총 %d개): ", num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d, %f", &coef[i].expon, &coef[i].coeff);
	}
}


void SparsePoly::add(SparsePoly a, SparsePoly b) {
	
	// 일단 coef 배열에 a, b 배열 다 채우기
	//// 먼저 a 배열 채우기
	for (int i = 0; i < a.num; i++)
	{	
		this->coef[i] = a.coef[i];
	}

	this->num = a.num;

	//// 다음 b 배열 채우는데 expon 겹치면 coeff 더해줌
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

	// 순서 정렬

	for (int i = 0; i < this->num - 1; i++)
	{	
		// 시작 칸의 expon을 max로 잡고
		int max = this->coef[i].expon;

		// 다음 칸부터 끝까지 하나씩 체크하면서
		for (int j = i + 1; j < this->num; j++)
		{	
			// max보다 expon이 더 큰 칸이 있으면
			if (this->coef[j].expon > max)
			{
				Term temp = this->coef[i];
				
				// 자리바꾸기
				this->coef[i] = this->coef[j];
				this->coef[j] = temp;

				// max 재지정
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


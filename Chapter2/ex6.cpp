#include<iostream>

void transmat(int row, int col) {
	
	// 동적할당으로 matrix 생성
	float** mat = new float* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new float[col];
	}

	// matrix에 값 대입
	printf("mat 값을 입력하세요(총 %d개) : ", row * col );
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf_s("%f", & mat[i][j]);
		}
	}

	printf("mat 행렬 출력\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%5.1f\t", mat[i][j]);
		}
		printf("\n");
	}



	float** Tmat = new float* [col];

	for (int i = 0; i < col; i++)
	{
		Tmat[i] = new float[row];
	}


	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			Tmat[i][j] = mat[j][i];
		}
	}

	printf("Tmat 행렬 출력\n");
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%5.1f\t", Tmat[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;

	for (int i = 0; i < col; i++)
	{
		delete[] Tmat[i];
	}
	delete[] Tmat;



}
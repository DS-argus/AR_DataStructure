#include<iostream>

void transmat(int row, int col) {
	
	// �����Ҵ����� matrix ����
	float** mat = new float* [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new float[col];
	}

	// matrix�� �� ����
	printf("mat ���� �Է��ϼ���(�� %d��) : ", row * col );
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf_s("%f", & mat[i][j]);
		}
	}

	printf("mat ��� ���\n");
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

	printf("Tmat ��� ���\n");
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
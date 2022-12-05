#pragma once
#include<iostream>

int** alloc2DInt(int rows, int cols) {
	if (rows <= 0 || cols <= 0)
	{
		return NULL;
	}

	int** mat = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int [cols];
	} 
	return mat;
}

void free2DInt(int** mat, int rows, int cols=0) {
	if (mat != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i];
		}

		delete[] mat;
	}
}

void set2DRandom(int** mat, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = rand() % 100;
		}
	}
}


void print2DInt(int** mat, int rows, int cols) {
	printf("행의 수 = %d, 열의 수 = %d\n", rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
}



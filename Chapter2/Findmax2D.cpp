
// ���� ���̰� �����Ǿ� �־ ��������
int findMaxPixel(int a[][5], int h, int w) {
	int maxval = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] > maxval)
			{
				maxval = a[i][j];
			}
		}
	}
	return maxval;
};



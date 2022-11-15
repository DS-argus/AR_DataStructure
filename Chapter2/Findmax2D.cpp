
// 가로 길이가 고정되어 있어서 제한적임
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



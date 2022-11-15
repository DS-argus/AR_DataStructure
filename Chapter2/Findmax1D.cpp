int findMaxValue(int list[], int len) {
	int maxval = list[0];

	for (int i = 0; i < len; i++)
	{
		if (list[i] > maxval)
		{
			maxval = list[i];
		}
	}

	return maxval;
};
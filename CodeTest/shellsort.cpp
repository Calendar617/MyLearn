#include "shellsort.h"

void shellsort::sort(vector<int>& data)
{
	int gap, i, j;
	int temp;
	for (gap = data.size() >> 1; gap > 0; gap >>= 1)
	{
		for (i = gap; i < data.size(); i++)
		{
			temp = data[i];
			for (j = i - gap; j >= 0 && data[j] > temp; j -= gap)
			{
				data[j + gap] = data[j];
			}

			data[j + gap] = temp;
		}
	}
}

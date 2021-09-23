#include "shellsort.h"
/*
希尔排序，插入排序的变种
通过比较相隔一定距离的元素，每趟排序的间隔，逐步减小，直到只比较相邻的元素
*/
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

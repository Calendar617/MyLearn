#include "qsort.h"

/*
设定key,保证左侧小于key,右侧大于key
递归实现
非递归实现，用stack记录每次排序后的left,right
*/
int qsort::paritition(vector<int>& data, int left, int right)
{
	int key = data[left];
	while (left < right)
	{
		while (left < right && data[right] >= key)
		{
			--right;
		}
		data[left] = data[right];
		while (left < right && data[left] <= key)
		{
			++left;
		}
		data[right] = data[left];
	}
	data[left] = key;
	return left;
}

void qsort::sort(vector<int>& data, int left, int right)
{
	if (left < right)
	{
		int key = paritition(data, left, right);
		sort(data, left, key - 1);
		sort(data, key + 1, right);
	}
}

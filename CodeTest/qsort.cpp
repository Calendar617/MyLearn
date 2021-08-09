#include "qsort.h"

/*
选择Key,把序列拆分成两段，保证左侧小于key,右侧大于key，把key与中间值交换
把左侧和右侧分别拆分排序，循环执行步骤，直到所有的整个序列排序完成
递归实现
非递归实现，用stack记录每次排序后的left,right
快排优化
1.三数取中法
  选择key,选择序列第一，中间，最后 三个值的中间值
2.直接插入法
  如果序列比较小，可以直接使用插入排序
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

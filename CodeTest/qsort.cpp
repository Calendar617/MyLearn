#include "qsort.h"

/*
�趨key,��֤���С��key,�Ҳ����key
�ݹ�ʵ��
�ǵݹ�ʵ�֣���stack��¼ÿ��������left,right
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

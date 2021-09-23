#include "shellsort.h"
/*
ϣ�����򣬲�������ı���
ͨ���Ƚ����һ�������Ԫ�أ�ÿ������ļ�����𲽼�С��ֱ��ֻ�Ƚ����ڵ�Ԫ��
https://baike.baidu.com/item/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F/3229428?fr=aladdin
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
			//
			for (j = i - gap; j >= 0 && data[j] > temp; j -= gap)
			{
				data[j + gap] = data[j];
			}

			data[j + gap] = temp;
		}
	}
}

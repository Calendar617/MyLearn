#include "selectionsort.h"

/*
* ѡ������ ʱ�临�Ӷ�O(N^2)
* ʼ���ƶ���С(��)ֵ����ǰ��
* �������ڴ�
*/
void selectionsort::sort(vector<int>& data)
{
	for (int i = 0; i < data.size() - 1; ++i)
	{
		//��¼��С
		int min = i;
		for (int j = i + 1; j < data.size(); ++j)
		{
			if (data[j] < data[min])
			{
				//�滻��Сֵ
				min = j;
			}
		}
		std::swap(data[i], data[min]);
	}
}

#include "selectionsort.h"

/*
* 选择排序， 时间复杂度O(N^2)
* 始终移动最小(大)值在最前面
* 不消耗内存
*/
void selectionsort::sort(vector<int>& data)
{
	for (int i = 0; i < data.size() - 1; ++i)
	{
		//记录最小
		int min = i;
		for (int j = i + 1; j < data.size(); ++j)
		{
			if (data[j] < data[min])
			{
				//替换最小值
				min = j;
			}
		}
		std::swap(data[i], data[min]);
	}
}

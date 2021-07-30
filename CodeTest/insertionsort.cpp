#include "insertionsort.h"
/* 插入排序，时间复杂度O()

*/
void insertionsort::sort(vector<int>& data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		int min = data[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (data[j] > min)
			{
				data[j + 1] = data[j];
				data[j] = min;
			}
			else
			{
				break;
			}
		}
	}
}

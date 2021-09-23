#include "heapsort.h"
#include <algorithm>

void heapsort::max_heapify(int arr[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
		{
			son++;
		}
		if (arr[dad] > arr[son])
		{
			return;
		}
		else
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heapsort::process(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		max_heapify(arr, i, len - 1);
	}
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

void heapsort::sort(vector<int>& data)
{
	int arr[] = {1, 3, 0 , 100, 3, 10, 4};
	int len = (int)sizeof(arr) / sizeof(*arr);
	process(arr, len);
}

#pragma once
#include <vector>
using namespace std;

class heapsort
{
public:
	static void max_heapify(int arr[], int start, int end);
	static void process(int arr[], int len);
	static void sort(vector<int>& data);
};


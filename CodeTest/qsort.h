#pragma once
#include <vector>
using namespace std;

class qsort
{
public:
	static int paritition(vector<int>& data, int left, int right);

	static void sort(vector<int>& data, int left, int right);
};


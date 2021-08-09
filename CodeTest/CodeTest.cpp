// CodeTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "binaryTree.h"
#include "qsort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "breathfirstsearch.h"

using namespace std;

void swap(int& a, int& b)
{
	//异或 位相同为0,不同为1
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

bool IsPrimer(int val)
{
	bool flag = true;
	if (val == 1)
	{
		flag = false;
	}
	else
	{
		double max = sqrt(val);
		for (int i = 2; i < max; i++)
		{
			if (val % i == 0)
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}


void KMP()
{
	std::string t = "abcabefg";

	int j = 0, k = -1;
	int next[10];
	next[0] = -1;
	while (j < t.length() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];//回退，next[k]就是上次匹配到的索引
		}
	}
}

//随机产生数据
void generateData(vector<int>& data)
{
	data.clear();
	for (int i = 0; i < 10; i++)
	{
		data.push_back(rand() % 100);
	}
}

int main()
{
	std::vector<int> data;
	generateData(data);

	//快速排序
	int left = 0;
	int right = (int)data.size() - 1;
	qsort::sort(data, left, right);

	//选择排序
	generateData(data);
	selectionsort::sort(data);

	//插入排序
	generateData(data);
	insertionsort::sort(data);

	breathfirstsearch::search();

	bool result = IsPrimer(10);

	int a = 1;
	int b = 2;
	swap(a, b);

	KMP();

	BinaryTree tree;
	tree.Create();

    //std::cout << "Hello World!\n";
}

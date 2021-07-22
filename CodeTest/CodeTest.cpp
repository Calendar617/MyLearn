// CodeTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <math.h>
#include "binaryTree.h"

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

int main()
{
	bool result = IsPrimer(10);

	int a = 1;
	int b = 2;
	swap(a, b);

	KMP();

	BinaryTree tree;
	tree.Create();

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

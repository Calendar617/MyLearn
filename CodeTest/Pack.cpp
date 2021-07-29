#include <iostream>
#include "Pack.h"

void Pack::Process()
{
	vector<int> w;
	w.push_back(2);
	w.push_back(2); 
	w.push_back(6);
	w.push_back(5); 
	w.push_back(4);

	vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	v.push_back(6);
		
	int c = 10;

	vector<vector<int>> m;
	vector<int> x;

	m = Search(w, v, c);
	x = build(m, w, c);

	std::cout << "begin" << std::endl;
	for (int i = 0; i <= 4; i++)
	{
		std::cout<< x[i] << std::endl;
	}
	std::cout << "end" << std::endl;
}

vector<vector<int>> Pack::Search(vector<int> w, vector<int> v, int c)
{
	vector<vector<int>> m;

	int i, j, n = (int)w.size();

	//for (i = 1; i < n + 1; i++) {
	//	m[i][0] = 0;
	//}

	//for (j = 0; j < c + 1; j++) {
	//	m[0][j] = 0;
	//}

	for (i = 0; i < n + 1; i++)
	{
		m.push_back(vector<int>());
		for (j = 0; j < c + 1; j++)
		{
			m[i].push_back(0);
		}
	}

	int count = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= c; j++)
		{
			int index = i - 1;
			m[i][j] = m[index][j];
			if (w[index] <= j)
			{
				if (v[index] + m[index][j - w[index]] > m[index][j])
				{
					m[i][j] = v[index] + m[index][j - w[index]];
				}
			}
			count++;
		}
	}

	return m;
}

vector<int> Pack::build(vector<vector<int>> m, vector<int> w, int c)
{
	int i, j = c;
	int n = (int)w.size();

	vector<int> x(n);

	for (i = n; i >= 1; i--)
	{
		int index = i - 1;
		if (m[i][j] == m[index][j])
		{
			x[index] = 0;
		}
		else
		{
			x[index] = 1;
			j -= w[index];
		}
	}

	return x;
}
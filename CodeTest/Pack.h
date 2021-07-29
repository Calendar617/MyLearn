#pragma once
#include <list>
#include <array>
#include <vector>

using namespace std;

class Pack
{
public:
	void Process();

private:
	vector<vector<int>> Search(vector<int> w, vector<int> v, int c);

	vector<int> build(vector<vector<int>> m, vector<int> w, int c);

};

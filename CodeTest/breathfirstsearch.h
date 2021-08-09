#pragma once

#include <map>
#include <list>
#include <string>
using namespace std;

class breathfirstsearch
{
public:
	static void search();
	static int heuristic(string, string);
};


class simplegraph
{
public:
	static void init();
	static list<string> neighbors(string node);
	static int cost(string cur, string next);
private:
	static map<string, list<string>> edges;
};

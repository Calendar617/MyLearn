#include "breathfirstsearch.h"
#include <queue>
#include <set>
#include <unordered_set>

void breathfirstsearch::search()
{
	simplegraph::init();

	//优先级更高入队后，排在最前面
	priority_queue<string> frontier;
	//queue<int> frontier;
	frontier.push("A");
	map<string, string> reached;
	reached["A"] = "";
	map<string, int> costmap;
	costmap["A"] = 0;

	string goal = "E";

	while (!frontier.empty())
	{
		string cur = frontier.top();
		frontier.pop();

		if (cur == goal)
		{
			break;
		}
		list<string> next = simplegraph::neighbors(cur);
		for(auto it = next.begin(); it != next.end(); it++)
		{
			int newcost = costmap[cur] + simplegraph::cost(cur, *it);
			printf("current cost is %d\n", newcost);
			if (costmap.find(*it) == costmap.end() || newcost < costmap[*it])
			{
				costmap[*it] = newcost;
				int priority = newcost + heuristic(goal, *it);
				frontier.push(*it);
				reached[*it] = cur;
			}
		}
	}
}

int breathfirstsearch::heuristic(string goal, string next)
{
	return atoi(goal.c_str()) - atoi(next.c_str());
}

map<string, list<string>> simplegraph::edges;

void simplegraph::init()
{
	list<string> node1;
	node1.push_back("B");
	simplegraph::edges["A"] = node1;

	list<string> node2;
	node2.push_back("C");
	simplegraph::edges["B"] = node2;

	list<string> node3;
	node3.push_back("B");
	node3.push_back("D");
	node3.push_back("F");
	simplegraph::edges["C"] = node3;

	list<string> node4;
	node4.push_back("C");
	node4.push_back("E");
	simplegraph::edges["D"] = node4;

	list<string> node5;
	node5.push_back("F");
	simplegraph::edges["E"] = node5;

	list<string> node6;
	simplegraph::edges["F"] = node6;
}

std::list<std::string> simplegraph::neighbors(string node)
{
	map<string, list<string>>::iterator it = simplegraph::edges.find(node);
	if (it != simplegraph::edges.end())
	{
		return it->second;
	}

	return list<string>();
}

int simplegraph::cost(string cur, string next)
{
	return 1;
}

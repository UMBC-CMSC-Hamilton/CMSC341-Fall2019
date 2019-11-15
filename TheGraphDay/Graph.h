#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

struct GraphNode
{
	GraphNode()
		: previous(nullptr) {}
	int id;
	vector<GraphNode *> neighbors;
	GraphNode * previous;
};


class Graph
{
	public:
		Graph();
		~Graph();
		void BuildGraph(string filename);
		vector<GraphNode *> DepthFirstSearch(int id, int dest_id);
		vector<GraphNode *> BreadthFirstSearch(int id, int dest_id);

		vector<string> split(string s);
	private:
		vector<GraphNode * > the_nodes;
};


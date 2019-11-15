#include "Graph.h"
#include<iostream>
#include<stack>
#include<queue>

using namespace std;


Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::BuildGraph(string filename)
{
	int size;
	cout << "how many nodes do you have? " << endl;
	cin >> size;
	the_nodes.resize(size, nullptr);

	string s;
	getline(cin, s);

	for (unsigned int i = 0; i < the_nodes.size(); i++)
	{
		the_nodes[i] = new GraphNode();
		the_nodes[i]->id = i;
	}

	unsigned int x_value = 0;

	for (unsigned int i = 0; i < the_nodes.size(); i++)
	{

		cout << "what is the adjacency list for node " << i + 1 << "? ";
		getline(cin, s);
		for (string x : split(s))
		{
			x_value = stoi(x) - 1;
			if (0 <= x_value && x_value < the_nodes.size())
			{
				the_nodes[i]->neighbors.push_back(the_nodes[x_value]);
			}
		}
	}
}

vector<GraphNode*> Graph::DepthFirstSearch(int id, int dest_id)
{
	id -= 1;
	dest_id -= 1;
	vector<bool> visited(the_nodes.size(), false);
	vector<GraphNode *> path;
	stack<GraphNode * > the_stack;
	GraphNode * current = nullptr;
	if (0 <= id && id < (int)the_nodes.size())
	{
		current = the_nodes[id];
		the_stack.push(the_nodes[id]);
		visited[id] = true;
	}

	while (!the_stack.empty() && (current && current->id != dest_id))
	{
		current = the_stack.top();
		the_stack.pop();

		for (GraphNode * neighbor : current->neighbors)
		{
			if(!visited[neighbor->id])
			{
				the_stack.push(neighbor);
				visited[neighbor->id] = true;
				neighbor->previous = current;
			}
		}
	}
	if (current && current->id == dest_id)
	{
		while (current)
		{
			path.insert(path.begin(), current);
			current = current->previous;
		}
	}
	return path;
}

vector<GraphNode*> Graph::BreadthFirstSearch(int id, int dest_id)
{

	return vector<GraphNode*>();
}

vector<string> Graph::split(string s)
{
	vector<string> split_string;
	int start_string = -1;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (start_string == -1 && s[i] != ' ')
		{
			start_string = i;
		}
		else if (start_string != -1 && s[i] == ' ')
		{
			split_string.push_back(s.substr(start_string, i - start_string));
			start_string = -1;
		}
	}
	if (start_string != -1)
	{
		split_string.push_back(s.substr(start_string, s.length() - start_string));
	}
	return split_string;
}

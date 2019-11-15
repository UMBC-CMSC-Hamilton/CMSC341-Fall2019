#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
	string s;

	Graph g;
	g.BuildGraph(s);

	cout << "Where do you want to start and end?" << endl;
	int start, end;
	cin >> start >> end;
	for (GraphNode * gn : g.DepthFirstSearch(start, end))
	{
		cout << gn->id << " ";
	}
	cout << endl <<  "done, enter garbage now" << endl;
	cin >> s;
}
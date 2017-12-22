#include "Graph.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string filename;
	cout << "Enter filename" << endl;
	getline(cin, filename);
	T_Graph graph;

	graph.flink(filename);
	graph.fimport();
	vector<vector<int>> bicomponents = graph.findBicomponents();

	for (vector<vector<int>>::iterator it = bicomponents.begin(); it != bicomponents.end(); it++)
	{
		cout << "{ ";
		for (vector<int>::iterator that = it->begin(); that != it->end(); that++)
		{
			cout << *that << " ";
		}
		cout << "}" << endl;
	}


	system("pause");
	return 0;
}
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;



class T_Graph
{
	typedef	struct			T_Vertex	{
											int					key;
											T_Vertex			*next;

											T_Vertex() :		next(nullptr)					{};
											T_Vertex(int x) :	key(x),			next(nullptr)	{};
										};

	vector<T_Vertex*>		graph;


	int						*component;

	vector<int>				stack;

	vector<vector<int>> bicmp;


	string					f_name;

	void					push_back			(T_Vertex *&dest, int src);

	void					ErrorMessage		(int key);

public:

	void					flink				(string filename);
	
	string					get_fname			();

	void					fexport				();
	
	void					fimport				();

	vector<vector<int>>		findBicomponents	();

	void					DFS					(int i);

};

#endif
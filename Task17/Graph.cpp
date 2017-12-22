#include "Graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void				T_Graph::	ErrorMessage		(int	key		)
{
	switch (key)
	{
	case 0:
	{
		cout << "Couldn't open file." << endl;
	}
	case 1:
	{
		cout << "Graph doesn't exist." << endl;
	}
	}
}

void				T_Graph::	flink				(string	filename)
{
	f_name = filename;							//or f_name = filename;
};

string				T_Graph::	get_fname			()
{
	return f_name;
}

void				T_Graph::	fimport				()
{
	ifstream fin(f_name);

	if (!fin.is_open())
		ErrorMessage(0);
	
	char buff[20];
	int i = 0;
	T_Vertex *v;

	while (!fin.eof())	{
		fin >> buff;
		

		if (isdigit(buff[0])) {
			if (graph.size() <= atoi(buff))
				for (int j = graph.size(); j <= atoi(buff); j++)
					graph.push_back(nullptr);
			push_back(graph[i], atoi(buff));
		}
		else {
			i++;
			if (i == graph.size())
				graph.push_back(nullptr);
		}
	}
	fin.close();
}

void				T_Graph::	fexport				()
{
	ofstream fout(f_name);
	
	if (!fout.is_open())
		ErrorMessage(0);

	T_Vertex *v;
	for (vector<T_Vertex*>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		v = *it;
		while (v)
		{
			fout << v->key;
			fout << " ";
			v = v->next;
		}
		fout << "|";
	}


	fout.close();
}

vector<vector<int>>	T_Graph::	findBicomponents	()
{
	if (graph.size() < 1)
		ErrorMessage(1);

	component = new int[graph.size()];

	for (int i = 0; i < graph.size(); i++)
	{
		component[i] = -1;
		//stack.push_back(i);
	}
	
	

	for (int i = 0; i < graph.size(); i++)
	{
		if (!graph[i])
			bicmp.push_back({ i });			

		if (component[i] < 0)
			DFS(i);

		if (stack.size() == 0)
			continue;
		
		bicmp.push_back(stack);
		stack.clear();
	}
	
	

	return bicmp;
}

void				T_Graph::	DFS					(int i)
{
	if (component[i] < 0)
	{
		component[i] = i;
		stack.push_back(i);

		bool has_path = 0;


		T_Vertex *p = graph[i];
		while (p)
		{
			DFS(p->key);
			if (component[p->key] >= 0)
			{
				has_path = 1;
				component[i] = component[p->key];
			}
				
			p = p->next;
		}
		if (has_path == 0)
		{
			stack.erase(stack.end() - 1, stack.end());
			component[i] = -1;
			//bicmp.push_back(stack);
			//stack.clear();
		}
			
	}
	else
		return;
}

void				T_Graph::	push_back			(T_Vertex *&dest, int src)
{
	if (!dest)
	{
		dest = new T_Vertex(src);
		return;
	}
	T_Vertex *p = dest;
	while (p->next)
		p = p->next;
	p->next = new T_Vertex(src);
}
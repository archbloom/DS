#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	list<int> *adj;
	int vert;
	int *vis;
	list<int> :: iterator itr;
public:
	Graph(int v)
	{
		this->vert = v;
		adj = new list<int>[v];
		vis = new int[v];
		for(int i=0;i<v;i++)
			vis[i] = 0;
	}
	void addEdge(int v,int w)
	{
		this->adj[v].push_back(w);
	}
	void search(int s)
	{
		vis[s]=1;
		cout<<s<<" ";
		for(itr=adj[s].begin();itr!=adj[s].end();itr++)
		{
			if(!vis[*itr])
				search(*itr);
		}
	}
};
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	g.search(2);
	cout<<endl;
}

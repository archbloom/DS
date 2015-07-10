#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int v)
	{
		this->V=v;
		adj = new list<int>[v];
	}
	void addEdge(int v,int w)
	{
		adj[v].push_back(w);
	}
	void BFS(int s)
	{
		bool *vis = new bool[V];
		for(int i=0;i<V;i++)
			vis[i]=false;
		list<int> queue;
		vis[s]=true;
		queue.push_back(s);
		list<int>::iterator i;
		while(!queue.empty())
		{
			s=queue.front();
			cout<<s<<" ";
			queue.pop_front();
			for(i=adj[s].begin();i!=adj[s].end();++i)
			{
				if(!vis[*i])
				{
					vis[*i]=true;
					queue.push_back(*i);
				}
			}
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
	g.BFS(2);
	cout<<endl;
	return 0;
}

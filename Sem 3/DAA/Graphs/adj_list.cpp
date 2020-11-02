#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *L;

public:
    Graph(int V)
    {
        this->V = V;
        L = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        L[x].push_back(y);
        L[y].push_back(x);
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex : " << i << " -> ";
            for (list <int> :: iterator nbr = L[i].begin() ; nbr != L[i].end(); nbr++ ){
                cout << *nbr << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.printAdjList();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> L;

public:
    void addEdge(string x, string y, bool biDirectional, int weight)
    {
        L[x].push_back(make_pair(y, weight));
        if (biDirectional)
        {
            L[y].push_back(make_pair(x, weight));
        }
    }
    void printAdjList()
    {
        for (auto p : L)
        {
            string points = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << points << "-->";
            for (auto nbr : nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout << dest << " " << dist << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
}
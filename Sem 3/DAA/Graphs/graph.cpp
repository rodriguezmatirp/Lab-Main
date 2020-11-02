#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std;

int main()
{
    Graph g(0);
    int vertexCount = 4;

    // cout << "Enter the number of vertices\n";
    // cin >> vertexCount;

    //Add vertices for a graph
    for(int i = 0; i < vertexCount ;i++)
        g.addVertex();

    //Adding adges 
    g.addEdge(1, 3, 25);
    g.addEdge(3, 2, 10);
    g.addEdge(2, 0, 20);
    g.addEdge(0, 3, 15);
    g.addEdge(0, 1, 5);

    //Display Graph
    g.displayGraph();

    //Show adjacent Vertices for a given vertex
    // list < pair < int,int > > adjVer;
    // adjVer = g.findAdjVertices(1);

    // for( list < pair< int, int > >:: iterator it = adjVer.begin();it != adjVer.end() ;it++ ){
    //     cout<<(*it).first << " ";
    // }

    //Show vertices with particular degree
    // g.vertexWithDegree(2);

    //Sum of degree of all vertices
    // g.sumOfDegrees();

    //Find whether a vertex has path to another vertex
    // g.checkPath(1,2);    //returns bool value

    //DFS
    // cout<<"Depth First traversal : " << endl;
    // g.dfs(1);

    //BFS
    // cout<<"Breadth First traversal : "<<endl;
    // g.bfs(1);

    //Minimum Spanning Tree
    g.MST();


    return 0;
}
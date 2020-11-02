#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertexCount;
    vector< list < pair<int, int> > > vertices;

public:
    Graph(int);
    void addEdge(int, int, int);
    void displayGraph();
    void addVertex();
    list < pair < int,int >  > findAdjVertices(int);
    void vertexWithDegree(int);
    int sumOfDegrees();
    bool checkPath(int,int);
    void dfs(int);
    // void dfsHelper(int,vector <bool>);
    void bfs(int);
    void MST();
};

Graph ::Graph(int vertexCount = 0)
{
    this->vertexCount = vertexCount;
    // vertices.reserve(vertexCount);
    for (int i = 0; i < vertexCount; i++)
    {
        list<pair<int, int> > temp;
        pair<int, int> edge;
        int vertex;
        int weight;
        cout << "Enter adjacent vertices for vertex and the weight together,enter -1 to proceed to next vertex" << endl;

        while (1)
        {
            cin >> vertex;
            cin >> weight;
            if (vertex == -1)
                break;
            edge.first = vertex;
            edge.second = weight;
            temp.push_back(edge);
        }
        vertices.push_back(temp);
    }
}

void Graph :: addVertex(){
    list<pair<int,int> > temp;
    vertices.push_back(temp);
}

void Graph ::addEdge(int vertexA, int vertexB, int weight)
{
    pair<int, int> edge;
    edge.first = vertexB;
    edge.second = weight;
    vertices.at(vertexA).push_back(edge);
    edge.first = vertexA;
    vertices.at(vertexB).push_back(edge);
}


void Graph ::displayGraph()
{
    cout << "Graph having " << vertexCount <<" vertices " << endl;

    for(vector< list < pair< int,int> > > :: iterator it = vertices.begin();it != vertices.end(); it++){
        for( list <pair <int,int> >:: iterator jt = (*it).begin(); jt != (*it).end() ;jt++ )
            cout<<(*jt).first << " " ;
        cout<<endl;
    }    
}

list< pair < int,int> > Graph :: findAdjVertices(int vertex)
{
    return vertices.at(vertex);
}

void Graph :: vertexWithDegree(int degree)
{
    cout <<"Vertices with degree " << degree << " : ";
    for(int i = 0 ; i < vertices.size() ;i++){
        if(vertices.at(i).size() == degree){
           cout<<i << "," ;
        }
    }
    cout<<endl;
}

int Graph :: sumOfDegrees()
{
    int sum = 0;
    for(int i = 0;i < vertices.size();i++ ){
        sum += vertices.at(i).size();
    }
    return sum;
}

bool Graph :: checkPath(int vertex1,int vertex2)
{
    if(vertex1 == vertex2)
        return true;

    list <int> adjacent;
    vector <bool> visited(vertices.size(),false);
    vector <bool> inQueue(vertices.size(),false);

    int x = vertex1;
    adjacent.push_back(x);
    while(!adjacent.empty()){
        x = adjacent.front();
        
        for(list < pair < int,int > > :: iterator it = vertices.at(x).begin() ; it != vertices.at(1).end();it++){
            if((*it).first == vertex2)
                return true;

            if(visited.at((*it).first) != 1 && inQueue.at((*it).first) != 1){
                inQueue.at((*it).first) = 1;
                adjacent.push_back((*it).first);
            }
        }
        visited.at(x) = true;
        adjacent.pop_front();
    }
    return false;
}

void Graph :: dfs(int vertex)
{
    list<int> adjacent;     //stack
    vector<bool> visited(vertices.size(),false);
    vector<bool> inStack(vertices.size(),false);

    int x = 1;
    adjacent.push_front(x);
    while(!adjacent.empty()){
        x = adjacent.front();
        adjacent.pop_front();
         
        cout << x  << " ";
          
        for(list <pair<int,int> > :: iterator it = vertices.at(x).begin() ; it != vertices.at(x).end() ; it++){
            if(visited.at((*it).first) != 1 && inStack.at((*it).first) != 1){
                inStack.at((*it).first) = 1;
                adjacent.push_front((*it).first);
            }               
         } 
        visited.at(x) = true;   
    }
    cout<<endl;
}

void Graph :: bfs(int vertex)
{
    list<int> adjacent;     //Queue
    vector<bool> visited(vertices.size(),false);
    vector<bool> inQueue(vertices.size(),false);


    int x = vertex;
    adjacent.push_back(x);
    while(!adjacent.empty()){
        x = adjacent.front();

        cout << x  << " ";
        
        for(list<pair<int,int> >::iterator it = vertices.at(x).begin() ; it != vertices.at(x).end() ; it++){
            if(visited.at((*it).first) != 1 && inQueue.at((*it).first) != 1){
                inQueue.at((*it).first) = 1;
                adjacent.push_back((*it).first);
            }               
        }
        visited.at(x) = true;
        adjacent.pop_front();
    }
    cout<<endl;
}

void Graph :: MST() 
{ 
    //Prim's Algorithm
    priority_queue < pair < int,int> ,vector < pair <int,int > > ,greater<pair < int,int > > > pq;

    vector <int> parent(vertices.size(),-1); 
    vector <int> key(vertices.size(),INT_MAX); 
    vector <bool> inMst(vertices.size(),false);

    pq.push(make_pair(0,0));
    key[0] = 0; 

    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        // Include vertex in MST 
        inMst[u] = true;  

        for (list< pair<int, int> >::iterator i = vertices.at(u).begin(); i != vertices.at(u).end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller than current key of v 
            if (inMst[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u;
            } 
        } 
    } 
  
    // Print edges of MST using parent array 
    for (int i = 1; i < vertices.size(); ++i) 
        cout << parent[i] << " - " << i << endl;     
} 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;
    int wt = 0;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Pair
{

public:
    int vtx = 0;
    string psf;
    int wt = 0;

    Pair(int vtx, string psf, int wt)
    {
        this->vtx = vtx;
        this->psf = psf;
        this->wt = wt;
    }
};

class comp
{
public:
    bool operator()(Pair* a, Pair* b) 
    {
        return a->wt > b->wt;
    }
};

int main()
{

    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }
    int src;
    cin>>src;
    priority_queue<Pair*, vector<Pair*>, comp> pq;
    pq.push(new Pair(src,to_string(src),0));
    vector<bool> visited(vtces, false);

    while (!pq.empty())
    {
      Pair * top = pq.top();
      pq.pop();
      if(visited[top->vtx] == true){
        continue;
      }
      visited[top->vtx] = true;
      cout<<top->vtx<<" via "<<top->psf<<" @ "<<top->wt<<endl;
      for(Edge e : graph[top->vtx]){
        if(visited[e.nbr]==false){
          pq.push(new Pair(e.nbr,top->psf+to_string(e.nbr),top->wt+e.wt));
        }
      }
      
    }

    return 0;
}
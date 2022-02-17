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
    int par = 0;
    int wt = 0;

    Pair(int vtx, int par, int wt)
    {
        this->vtx = vtx;
        this->par = par;
        this->wt = wt;
    }
};

struct comp
{
public:
    bool operator()(Pair const &a, Pair const &b) const
    {
        return a.wt > b.wt;
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
    priority_queue<Pair, vector<Pair>, comp> pq;
    pq.push(Pair(0, -1, 0));
    vector<bool> visited(vtces, false);

    while (!pq.empty())
    {

        Pair rem = pq.top();
        pq.pop();
        if (visited[rem.vtx] == true)
        {
            continue;
        }
        visited[rem.vtx] = true;
        if (rem.par != -1) cout << "[" << rem.vtx << "-" << rem.par << "@" << rem.wt << "]" << endl;
            for (Edge e : graph[rem.vtx])
            {
                if (visited[e.nbr] == false)
                {
                    pq.push(Pair(e.nbr, rem.vtx, e.wt));
                }
            }
        
    }

    return 0;
}
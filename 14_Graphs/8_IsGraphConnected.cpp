#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void getcomps(vector<Edge> graph[], int src, vector<int> &comp, vector<bool> &visited)
{

    comp.push_back(src);
    visited[src] = true;
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            getcomps(graph, e.nbr, comp, visited);
        }
    }

}

int main()
{
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1;
        int v2;
        int wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    vector<vector<int>> comps;
    vector<bool> visited(vtces, false);
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == false)
        {
            vector<int> comp;
            getcomps(graph, i, comp, visited);
            comps.push_back(comp);
        }
    }

    if (comps.size() == 1)
    { 
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
#include <bits/stdc++.h>

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

void Hamiltonian(vector<vector<Edge>> &graph, int src, string psf, vector<bool> &vis, int csf, int osrc)
{

    if (csf == graph.size())
    {

        cout << psf;
        bool check = false;
        for (Edge e : graph[src])
        {
            if (e.nbr == osrc)
            {
                check = true;
            }
        }

        if (check)
        {
            cout << "*" << endl;
        }
        else
        {
            cout << "." << endl;
        }
        return;
    }
    vis[src] = true;

    for (Edge e : graph[src])
    {

        if (vis[e.nbr] == false)
        {
            string path = to_string(e.nbr);
            Hamiltonian(graph, e.nbr, psf + path, vis, csf + 1, osrc);
        }
    }

    vis[src] = false;
}

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
    cin >> src;
    vector<bool> vis(vtces, false);
    Hamiltonian(graph, src, to_string(src), vis, 1, src);

    return 0;
}

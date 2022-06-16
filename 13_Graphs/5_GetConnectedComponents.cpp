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

void getcomps(vector<Edge> graph[], int src, vector<int> &comp, vector<bool> &vis)
{
    vis[src] == true;
    comp.push_back(src);

    for (Edge e : graph[src])
    {

        if (vis[e.nbr] == false)
        {

            getcomps(graph, e.nbr, comp, vis);
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
    vector<bool> vis(vtces, false);

    for (int i = 0; i < vtces; i++)
    {

        if (vis[i] == false)
        {
            vector<int> comp;
            getcomps(graph, i, comp, vis);
            comps.push_back(comp);
        }
    }

    int count = 0;
    for (int i = 0; i < comps.size(); i++)
    {
        count += comps[i].size();
    }
    cout << "[";
    for (int i = 0; i < comps.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < comps[i].size(); j++)
        {
            if (j != comps[i].size() - 1)
                cout << comps[i][j] << ", ";
            else
                cout << comps[i][j];
        }
        cout << "]";
        if (i != comps.size() - 1)
            cout << ", ";
    }
    cout << "]";
}
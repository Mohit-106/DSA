// Recursive Solution is never relevent because here we only can 
//execute relevent calls not all irrrelevent also by dry run it can be proved that 
// recursive solution would not ATOMIC_WCHAR_T_LOCK_FREE

// if we use queue then chahe dono call revelent ho ya phir nahi dono hi add ho jagegi 
// so hm double occuring element se cyclic or not cyclic confirm kr skte hain.



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

bool iscyclic(vector<vector<Edge>> &graph, int src, vector<bool> &visited)
{
    
    if (visited[src] == true)
    {
        return true;
    }
    visited[src] = true;
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            iscyclic(graph, e.nbr, visited);
        }
    }

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

    vector<bool> visited(vtces, false);
    bool check = false;
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == false)
        {
            bool ans = iscyclic(graph, i, visited);
            if (ans)
            {
                check = true;
                break;
            }
        }
    }

    if (check)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
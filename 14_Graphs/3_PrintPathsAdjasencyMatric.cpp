#include <bits/stdc++.h>
using namespace std;

void printPath(vector<vector<int>> &graph, int src, int des, vector<bool> &vis, string ans)
{
    if (src == des)
    {
        cout << ans << endl;
        return;
    }
    vis[src] = true;

    for (int nbr = 0; nbr < graph.size(); nbr++)
    {
        if (graph[src][nbr] != 0 && vis[nbr] == false)
        {
            printPath(graph, nbr, des, vis, ans + to_string(nbr));
        }
    }

    vis[src] = false;
}

int main()
{
    int vtces;
    cin >> vtces;
    vector<vector<int>> graph(vtces, vector<int>(vtces));
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
    int src, dest;
    cin >> src >> dest;
    vector<bool> vis(vtces, false);
    printPath(graph, src, dest, vis, to_string(src));
    
}
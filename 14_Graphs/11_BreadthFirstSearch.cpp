#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

//also can be done by class pair 
// class Pair
// {
// public:
//   int src = 0;
//   string psf="";
//   Pair(int src, string psf)
//   {
//     this->src = src;
//     this->psf = psf;
//   }
// };

int main()
{
    int vtces;
    cin >> vtces;
    int edges;
    cin >> edges;
    vector<vector<Edge>> graph(vtces, vector<Edge>());

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }
    int src;
    cin >> src;

    vector<bool> visited(vtces, false);
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});
    while (q.size() != 0)
    {
        pair<int, string> top = q.front();
        q.pop();
        if (visited[top.first] == true)
        {
            continue;
        }
        visited[top.first] = true;
        cout << top.first << "@" << top.second << endl;
        for (Edge e : graph[top.first])
        {
            if (visited[e.nbr] == false)
            {
                q.push({e.nbr, top.second + to_string(e.nbr)});
            }
        }
    }

    return 0;
}
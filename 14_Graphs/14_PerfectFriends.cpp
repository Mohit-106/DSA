#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;

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
        cin >> v1 >> v2;
        graph[v1].push_back(Edge(v1, v2));
        graph[v2].push_back(Edge(v2, v1));
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
    int count=0;
    for(int i=0; i<comps.size(); i++){
        for(int j=i+1; j<comps.size(); j++){

            count+=(comps[i].size()*comps[j].size());

        }

    }

    cout<<count<<endl;









}
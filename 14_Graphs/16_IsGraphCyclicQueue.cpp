//in  queue approach we add all neighbour in the queue first 
//whether it is relevent or not 
// but in recursion we irrelevent calls not even excetuted once//
///--------Must dry run -------////////

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

bool iscyclic(vector<vector<Edge>>&graph, int src, vector<bool>&visited){

    queue<int>q;
    q.push(src);
    while(q.size()!=0){


        int rem =q.front();
        q.pop();
        if(visited[rem]==true){
            return true;
        }
        visited[rem]=true;
        for(Edge e : graph[rem]){

            if(visited[e.nbr]==false){
                q.push(e.nbr);
            }

        }


    }

    return false;

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
    for(int i=0;i<vtces; i++){
        if(visited[i]==false){
            bool ans = iscyclic(graph,i,visited);
            if(ans){
                cout<<"true"<<endl;
                return 0;
            }
        }

    }

    cout<<"false"<<endl;
    return 0;
   
}
#include <bits/stdc++.h>
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
    vector<bool>visited(vtces,false);
    stack<pair<int,string>>st;
    st.push({src,to_string(src)});
    while(!st.empty()){
        pair<int,string>rem=st.top();
        st.pop();
        if(visited[rem.first]==true){
            continue;
        }
        visited[rem.first]=true;
        cout << rem.first << "@" << rem.second << endl;
        for(Edge e : graph[rem.first] ){
            if(visited[e.nbr]==false){
                st.push({e.nbr,rem.second+ to_string(e.nbr)});
            }
        }


    }

    


 

    return 0;
}
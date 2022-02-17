#include<bits/stdc++.h>
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

bool isBipartitie(vector<vector<Edge>>&graph, vector<int>&visited, int src){

    queue<pair<int,int>>q;
    q.push({src,0});
    while(q.size()>0){
        pair<int,int> rem = q.front();
        q.pop();
        if(visited[rem.first]!=-1){

            if(visited[rem.first]!=rem.second){
                return false;
            }

        }else{
            visited[rem.first]=rem.second;
        }

        for(Edge e : graph[rem.first]){
            if(visited[e.nbr]==-1){

                q.push({e.nbr,rem.second+1});

            }
        }

    }

    return true;



}


int main() {                                                                        
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  

  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w;
 
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  } 

   vector<int>visited(vtces,-1);
    for(int i=0;i<vtces;i++){
        if(visited[i]==-1){
            bool check = isBipartitie(graph,visited,i);
            if(check==false){
                cout<<"false"<<endl;
                return 0;
            }
        }
    }

    cout<<"true"<<endl;




   return 0;
}
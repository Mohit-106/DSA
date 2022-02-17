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
  int src,t; 
  cin >> src;
  cin >> t;
  vector<int>visited(vtces,0);
  queue<pair<int,int>>q;
  q.push({src,1});
  int count=0;
  while(q.size()>0){

      pair<int,int> rem = q.front();
      q.pop();
      if(visited[rem.first]>0){

        continue;

      }else{
        visited[rem.first]=rem.second;
      }

      if(rem.second>t){
        break;
      }

      count++;

      for(Edge e : graph[rem.first]){
        if(visited[e.nbr]==0){
          q.push({e.nbr,rem.second+1});
        }
      }

  }

  cout<<count<<endl;



 
  return 0;
}
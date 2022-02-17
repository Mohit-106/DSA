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

void topologicalsort(vector<vector<Edge>>&graph, int src, stack<int>&st, vector<bool>&visited){

  visited[src]=true;
  for(Edge e : graph[src]){
    if(visited[e.nbr]==false){

      topologicalsort(graph,e.nbr,st,visited);

    }
  }

  st.push(src);

}

int main() {                                                                             
  
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  
  
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {  
    int u, v;  
    cin >> u >> v;   
 
    graph[u].push_back(Edge(u, v)); 
  }  

  vector<bool>visited(vtces,false);
  stack<int>st;
  for(int i=0;i<vtces;i++){
    if(visited[i]==false){
      topologicalsort(graph,i,st,visited);
    }
  }

  while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
  }

  return 0;
}
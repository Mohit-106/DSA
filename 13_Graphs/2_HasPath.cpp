#include<bits/stdc++.h>

using namespace std;
   class Edge {
       public:
          int src;
          int nbr;
          int wt;

      Edge(int src, int nbr, int wt){
         this->src = src;
         this->nbr = nbr;
         this->wt = wt;
      }
   };
   
    bool Haspath(vector<Edge> graph[] , int src , int des , vector<bool>vis){
        if(src == des){
            
            return true;
        }
        vis[src] = true;
        for(Edge ed : graph[src]){
            if(vis[ed.nbr] == false){
               
                bool check =Haspath(graph , ed.nbr , des , vis );
                if(check==true){
                    return true;
                }
                
            }
        }
        return false;
    }
 
   
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];

      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }

      int src;
      cin>>src;
      int dest;
      cin>>dest;
      vector<bool> vis(vtces , false);
      if(Haspath(graph , src , dest , vis)){
          cout<<"true"<<endl;
      }else{
          cout<<"false"<<endl;
      }

    }   



//1971. Find if Path Exists in Graph Leetcode

//     class Edge{
//     public:
//     int src;
//     int nbr;
//     Edge(int src, int nbr){
//         this->src = src;
//         this->nbr = nbr;
//     }
// };

// class Solution {
// public:
    
//     bool helper(vector<vector<Edge>>&graph, int src , int dst, vector<bool>&visited){
//         if(src==dst){
//             return true;
//         }
        
//         visited[src]=true;
//         for(Edge e : graph[src]){
//             if(visited[e.nbr]==false){
//                 bool check = helper(graph,e.nbr,dst,visited);
//                 if(check){
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }
    
    
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<vector<Edge>>Graph(n,vector<Edge>());
//         for(int i=0;i<edges.size();i++){
//             int src = edges[i][0];
//             int nbr = edges[i][1];
            
//             Graph[src].push_back(Edge(src,nbr));
//             Graph[nbr].push_back(Edge(nbr,src));
            
//         }
        
//         vector<bool>visited(n,false);
//         return helper(Graph,source,destination,visited);
       
        
        
//     }
// };                 
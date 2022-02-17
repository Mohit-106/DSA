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
   
    void printPath(vector<Edge> graph[] , int src , int des , vector<bool>vis, string ans){
        if(src == des){

            cout<<ans<<endl;
            return;
            
        
        }
        vis[src] = true;
        for(Edge ed : graph[src]){

            if(vis[ed.nbr] == false){

             printPath(graph , ed.nbr , des , vis , ans + to_string(ed.nbr));
            
            }
        }

        vis[src]==false;
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
      // write your code here
      vector<bool> vis(vtces , false);
      printPath(graph , src , dest , vis, to_string(src));

    }                                    
/// try using print paths using stack (that level approach)
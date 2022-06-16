#include <bits/stdc++.h>
using namespace std;

class Edge{
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



int main(){

   int vtces;
   cin>>vtces;

   vector<vector<Edge>> Graph(vtces,vector<Edge>());

   for(int i =0;i<vtces;i++){
      int src,nbr,wt;
      cin>>src>>nbr>>wt;
      Graph[src].push_back(Edge(src,nbr,wt));
      Graph[nbr].push_back(Edge(nbr,src,wt));

   }

   for(auto& v : Graph){
    for(auto & e : v){
        cout<<e.src<<"->"<<e.nbr<<"->"<<e.wt<<" ";
    }
    cout<<endl;
   }




   return 0;
}

//input (no directed graph)
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
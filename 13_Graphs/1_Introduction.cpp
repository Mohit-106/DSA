#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
   int src;
   int nbr;
   int wt;

   Edge(int src, int nbr, int wt)
   {
      this->src = src;
      this->nbr = nbr;
      this->wt = wt;
   }
};

int main()
{

   int vtces;
   cin >> vtces;
   vector<Edge> graph[vtces];

   // vector <data_type> V[size];
   // Array of Vectors
   // This is used in a case where we want fixed no. of rows and colums of varialbe numbers for
   // each row cell

   int edges;
   cin >> edges;
   for (int i = 0; i < edges; i++)
   {
      int v1;
      int v2;
      int wt;
      cin >> v1 >> v2 >> wt;
      graph[v1].push_back(Edge(v1, v2, wt));
      graph[v2].push_back(Edge(v2, v1, wt));
   }

   int src;
   cin >> src;
   int dest;
   cin >> dest;
}
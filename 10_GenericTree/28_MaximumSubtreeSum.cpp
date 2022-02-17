#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

class HeapMover
{   public:
    int msum = 0;
    int msumnode =0;
};
//1. Sab children se value lekar add kro 
//2 Then khudko add karo 
//3. then compare karo
int subsumtree(Node *node, HeapMover* mover)
{
   int sum=0;
   for(Node* child : node->children){
       int csum =   subsumtree(child, mover); // here children will there sums
       sum+=csum;

   }
   //here node will add itself
   sum+=node->data;
   if(sum>mover->msum){

       mover->msum=sum;
       mover->msumnode = node->data;

   }

   return sum;

    
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    HeapMover* mover= new HeapMover();
    subsumtree(root,mover);
    cout << mover->msumnode << "@" << mover->msum << endl;
}
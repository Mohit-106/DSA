#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node *> children;



  Node(int data)

  {

    this->data = data;

  }

};

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

Node *constructor01(vector<int> &arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node *> stack;

  stack.push_back(new Node(arr[0]));



  Node *root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node *node = stack.back();

      Node *nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}

//count Approach
vector<int> LOT(Node *node)
{
  queue<Node*>q;
  q.push(node);
  vector<int>res;
  while(q.size()>0){
    int count = q.size();
    while(count-->0){
      Node * front = q.front();
      q.pop();
      res.push_back(front->data);
      for(Node * child : front->children){
        q.push(child);
      }
    }

  }
  return res;

}

//pair approach
class Pair {
    public:
    Node * node ;
    int level;
    Pair(Node* node, int level){
        this->node = node;
        this->level=level;
    }

};

void LOT2(Node * root){
    queue<Pair*>q;
    Pair * newpair = new Pair(root,0);
    q.push(newpair);
    int currlevel = 0;
    while(q.size()>0){
        Pair * front = q.front();
        q.pop();
        if(front->level == currlevel){
            cout<<front->node->data<<" ";
        }else{
            cout<<endl;
            cout<<front->node->data<<" ";
            currlevel=front->level;
        }

        for(Node * child : front->node->children){
            q.push(new Pair(child,front->level+1));
        }

    }
}





void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root=constructor01(arr);
    
   vector<int>ans = LOT(root);
   for(int val : ans){
     cout<<val<<" ";
   }
   cout<<endl;
   LOT2(root);
    
}

int main()
{
    solve();
    return 0;
}
#include<bits/stdc++.h>
#include<climits>

using namespace std;

class Node
{
public:
  int data = 0;
  vector<Node*> children;

  Node(int data)
  {
    this->data = data;
  }
};


void display(Node* node)
{
  string s = "";
  s += to_string(node->data) + " Child: ";
  for (Node* child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node* child : node->children)
  {
    display(child);
  }
}


Node* constructor01(vector<int>& arr)
{
  if (arr.size() == 0)
    return NULL;

  vector<Node*> stack;
  stack.push_back(new Node(arr[0]));

  Node* root = stack[0];

  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] != -1)
    {
      Node* node = stack.back();
      Node* nnode = new Node(arr[i]);

      node->children.push_back(nnode);
      stack.push_back(nnode);
    }
    else
      stack.pop_back();
  }
  return root;
}

vector<int> nodeToRootPath(Node* node, int data)
{

    if(node->data==data){
        vector<int>arr;
        arr.push_back(node->data);
        return arr;
    }
    for(Node* child : node->children){
        vector<int> carr = nodeToRootPath(child,data);
        if(carr.size()>0){
            carr.push_back(node->data);
            return carr;
        }
    }
    vector<int>ans;
    return ans;

  
}



int lca(Node* node, int data1, int data2)
{

  vector<int>v1 = nodeToRootPath(node,data1);
  vector<int>v2=  nodeToRootPath(node,data2);

  int i = v1.size()-1;
  int j = v2.size()-1;
  while(i>=0 && j>=0 && v1[i]==v2[j]){

    i--;
    j--;

  }

  return v1[++i];


}

void solve()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < arr.size(); i++)
  {
    cin >> arr[i];
  }

  int data1;
  cin >> data1;
  int data2;
  cin >> data2;

  Node* root = constructor01(arr);
  int Lca = lca(root, data1, data2);
  cout << Lca << endl;
}

int main()
{
  solve();
  return 0;
}
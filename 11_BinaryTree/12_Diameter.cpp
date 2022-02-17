#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data = 0;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node *node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

//Display function
void display(Node *node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}

int diam = 0;

int diameter(Node *node)
{


  if (node == NULL)
  {

    return -1;
  }

  int lht = diameter(node->left);
  int rht = diameter(node->right);

  int ht = max(lht,rht);

  if (lht+rht + 2 > diam)
  {
    diam = lht + rht + 2;
  }
  return ht;


}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    if (tmp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(tmp);
    }
  }

  Node *root = constructTree(arr);

  
  int dia=diameter(root);
  cout << diam;
}
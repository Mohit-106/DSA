#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
  int data;
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

void levelOrder1(Node *node)
{ // Two queues approach

  queue<Node *> pq, cq;
  pq.push(node);
  while (pq.size() > 0)
  {

    Node *temp = pq.front();
    pq.pop();
    cout << temp->data << " ";
    if (temp->left != NULL)
    {

      cq.push(temp->left);
    }
    if (temp->right != NULL)
    {

      cq.push(temp->right);
    }
    if (pq.size() == 0)
    {
      swap(pq, cq);
      cout << endl;
    }
  }
}

void levelOrder2(Node *node)
{ // count approach

  queue<Node *> q;
  q.push(node);
  while (q.size() > 0)
  {

    int count = q.size();
    for (int i = 1; i <= count; i++)
    {
      Node *temp = q.front();
      q.pop();
      cout << temp->data << " ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
    }
    cout << endl;
  }
}

class Pair
{
public:
  Node *root;
  int level;
  Pair(Node *root, int level)
  {
    this->root = root;
    this->level = level;
  }
};

void levelOrder3(Node *node)
{

  Pair *pr = new Pair(node, 1);

  queue<Pair *> q;
  q.push(pr);
  int level = 1;
  while (q.size() > 0)
  {

    Pair *temp = q.front();
    q.pop();
    if (temp->level > level)
    {
      level = temp->level;
      cout << endl;
    }
    // print
    cout << temp->root->data << " ";
    // add children
    if (temp->root->left != NULL)
    {
      Pair *p = new Pair(temp->root->left, temp->level + 1);
      q.push(p);
    }
    if (temp->root->right != NULL)
    {
      Pair *p = new Pair(temp->root->right, temp->level + 1);
      q.push(p);
    }
  }
}

void levelOrder4(Node *node)
{ // Pair approach
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    string temp;
    cin >> temp;
    if (temp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(temp);
    }
  }
  Node *root = constructTree(arr);
  levelOrder3(root);

}

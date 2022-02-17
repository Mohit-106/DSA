
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  vector<Node *> children;
};

// -1 Pre and ++
// 0 to child.Size()-1 push child ++;
// child.size() Post ++
// child.size()+1

void iterativePreAndPostOrder(Node *root)
{
  stack<pair<Node *, int>> st;
  st.push({root, -1});
  string preorder;
  string postorder;
  while (st.size() > 0)
  {
    pair<Node *, int> top = st.top();
    st.pop();
    if (top.second == -1)
    {
      preorder += to_string(top.first->data) + " ";
      top.second++;
      st.push(top);
    }
    else if (top.second >= 0 and top.second < top.first->children.size())
    {
      pair<Node *, int> cp(top.first->children[top.second], -1);
      top.second++;
      st.push(top);
      st.push(cp);
    }
    else
    {
      postorder += to_string(top.first->data) + " ";
    }
  }
  cout << preorder << endl;
  cout << postorder << endl;
}

void iterativePreAndPostOrder2(Node *root)
{

  stack<pair<Node *, int>> st;
  st.push({root, -1});
  string preorder;
  string postorder;
  while (st.size() > 0)
  {
    pair<Node *, int> temp = st.top();
    st.pop();
    if (temp.second == -1)
    {
      preorder += to_string(temp.first->data);
      temp.second++;
      st.push(temp);
    }
    else if (temp.second >= 0 && temp.second < temp.first->children.size())
    {

      pair<Node *, int> cp(temp.first->children[temp.second], -1);

      temp.second++;
      st.push(temp);
      st.push(cp);
    }
    else
    {
      postorder += to_string(temp.first->data);
    }
  }
}

Node *construct(vector<int> &arr)
{
  Node *root = nullptr;

  stack<Node *> st;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == -1)
    {
      st.pop();
    }
    else
    {
      Node *t = new Node();
      t->data = arr[i];

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

int main()
{
  int n, x;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    arr.push_back(x);
  }
  Node *root = construct(arr);
  iterativePreAndPostOrder2(root);
}
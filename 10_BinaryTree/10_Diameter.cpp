#include <iostream>
#include <vector>

using namespace std;

class pr {

  public:
  int dia=0;
  int ht=0;

};

class Node
{
public:
    int data=0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

 class Pair {
    public:
    Node *node=nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
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





pr* diameter(Node *root)
{
  if(root==NULL){
     pr * base = new pr();
     base->dia = 0;
     base->ht= -1;
     return base;
  }

  pr * leftp =diameter(root->left);
  pr * rightp =diameter(root->right);

  int maxht = max(leftp->ht , rightp->ht)+1;
  int dia = leftp->ht + rightp->ht +2;
  int rdia = max(dia,max(leftp->dia,rightp->dia));
  pr * newpair = new pr();
  newpair->dia = rdia;
  newpair->ht=maxht;
  return newpair;

}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } else {
        arr[i] = stoi(tmp);
      }
    }
    
    
    Node * root = constructTree(arr);

    
    pr * ans =new pr();
    ans = diameter(root);
    cout<<ans->dia;
}
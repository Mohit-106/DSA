#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state)
  {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr) {

  if (idx == arr.size() || arr[idx] == -1) {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node) {
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

bool find(Node* node, int data) {

    if(node==NULL){

        return false;
        
    }

    if(node->data==data){
        return true;
    }

    bool lc = find(node->left,data);
    if(lc==true){
        return true;
    }

    bool rc = find(node->right,data);
    if(rc==true){
        return true;
    }

    return false;

  
}

vector<int> nodeToRootPath(Node* node, int data) {

    if(node==NULL){
        vector<int>v;
        return v;
    }

    if(node->data==data){
        vector<int>v;
        v.push_back(node->data);
        return v;
    }

    vector<int> lc = nodeToRootPath(node->left,data);
    if(lc.size()>0){
        lc.push_back(node->data);
        return lc;
    }
    

    vector<int> rc = nodeToRootPath(node->right,data);
    if(rc.size()>0){
        rc.push_back(node->data);
        return rc;
    }

    vector<int>v;
    return v;

}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(temp);
    }
  }

  Node* root = constructTree(arr);
  int data;
  cin >> data;
  bool found = find(root, data);
  found == 1 ? cout << "true" << endl : cout << "false" << endl;
  vector<int> path = nodeToRootPath(root, data);
  cout << "[";
  for (int i = 0; i < path.size(); i++) {
    cout << path[i];
    if (i != path.size() - 1) {
      cout << ", ";
    }
  }
  
  cout << "]" << endl;
}
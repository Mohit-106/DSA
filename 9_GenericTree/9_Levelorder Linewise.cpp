#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  vector<Node*>children;
};

Node* newNode(int key) {
  Node* temp = new Node;
  temp->data = key;
  return temp;

}

Node* construct(int arr[], int n ) {
  Node* root = NULL;
  stack<Node*>st;
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = newNode(arr[i]);
      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}

void levelorderlinewise(Node* node)
{

    queue<Node*>q,cq;
    q.push(node);
    while(q.size()>0){

        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        for(Node* child : temp->children){
            cq.push(child);
        }

        if(q.size()==0){
            swap(q,cq);
            cout<<endl;
        }
    }
    

}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = construct(arr, n);
  levelorderlinewise(root);
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

Node *newNode(int val)
{ // here we are just setting the data in the node
    Node *node = new Node;
    node->data = val;
    return node;
}
// Tree Constructor
Node *Constructor(vector<int> &arr, int n)
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
            if (st.size() == 0)
            {
                root = t;
            }
            else
            {

                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }

    return root;
}


void disp(Node* node){

    string str = to_string(node->data) + " -> ";
    for (Node* child : node->children) {
      str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<endl;

    for (Node* child : node->children) {
      disp(child);
    }

}









int main()
{

     
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=Constructor(arr,n);

    disp(root);


    return 0;
}



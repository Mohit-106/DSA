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
Node *Constructor(vector<int> arr, int n)
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
                root = t;  // this value will set when we add first element
            }
            else
            {

                st.top()->children.push_back(t);
            }
            st.push(t);
        }
    }
}

int main()
{

    // input a vector and give as an argument to constructor function
    return 0;
}


// Steps -->

//1 Create a Node class with data members int data and and vector(it will store addresses of children)
//2 Now Construct a new node and add value to it
//3 Create a Stack(it will store the address of node)
//4 Push the address of node to stack
//5 If any address already present on the top of stack then
// us address pr jo vector hai usme current node ka address dal do
// Dont Forget to create a root variable which will store topmost elements address
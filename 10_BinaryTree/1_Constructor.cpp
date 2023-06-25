#include <bits/stdc++.h>
using namespace std;
// state==1 set left child
// state==2 set right child
// state==3 pop()
// Add Child Process
// 1.creat a node
// 2. set data
// 3. link child node with parent node
// 4. set state of child node
// 4. update state of parent (state++)

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

    if(idx==arr.size() || arr[idx]==-1){
        idx++;
        return NULL;
    }

    Node * root = new Node(arr[idx]);
    idx++;
    root->left = constructTree(arr);
    root->right = constructTree(arr);

    return root;

}

class Pair
{
public:
    Node *node;
    int state;
    Pair(Node *node)
    {
        this->node = node;
        this->state = 1;
    }
};

Node *ConstructTree2(vector<int> &v)
{
    Node *root = new Node(v[0]);
    Pair *rp = new Pair(root);
    stack<Pair *> st;
    st.push(rp);
    int i = 1;
    while (st.size() > 0)
    {
        Pair *tos = st.top();
        if (tos->state == 1)
        {

            if (v[i] != -1)
            {
                Node *newNode = new Node(v[i]);
                tos->node->left = newNode;
                Pair *newPair = new Pair(newNode);
                st.push(newPair);
            }
            tos->state++;
            i++;
        }
        else if (tos->state == 2)
        {

            if (v[i] != -1)
            {
                Node *newNode = new Node(v[i]);
                tos->node->right = newNode;
                Pair *newPair = new Pair(newNode);
                st.push(newPair);
            }
            tos->state++;
            
        }else{
            st.pop();
        }
       
    }

    return rp->node;
}

void display(Node *node)
{
    if (node == NULL)
        return;
    string str = "<-" + to_string(node->data) + "->";
    string lcstr = node->left == NULL ? "." : to_string(node->left->data);
    string rcstr = node->right == NULL ? "." : to_string(node->right->data);
    cout << lcstr << str << rcstr << endl;

    display(node->left);
    display(node->right);
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

    Node *root = ConstructTree2(arr);
    display(root);
}
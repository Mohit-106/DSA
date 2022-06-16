#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void addNode(int val)
    {
        Node *temp = new Node(val, NULL);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        sz++;
    }
    void Diplay(){
        for(Node * temp = head; temp!=NULL; temp=temp->next){
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    LinkedList *l1 = new LinkedList();
    for(int i=10; i<=100; i+=10){
        l1->addNode(i);
    }
    l1->Diplay();
    cout<<l1->sz<<endl;
    cout<<l1->head->data<<" "<<l1->tail->data<<endl;
    LinkedList *l2 = l1;
    l2->Diplay();


    return 0;
}

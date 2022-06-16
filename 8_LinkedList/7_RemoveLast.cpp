#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int sz = 0;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addLast(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
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
    int size()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    void display()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
    void removeFirst()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (sz == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
        }

        sz--;
    }
    int getFirst()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int getLast()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
    int getAt(int idx)
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }else if(idx<0 || idx>sz-1){
            cout<<"Invalid arguments"<<endl;
            return -1;
        }else{
            Node * temp =head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }
            return temp->data;
        }
    }
    void addFirst(int val)
    {
        if(sz==0){
            addLast(val);
        }else{
            Node * node = new Node();
            node->data=val;
            node->next=head;
            head=node;
            sz++;
        }

    }
    void addAt(int idx, int val)
    {
        if(idx<0 || idx>sz){
            cout<<"Invalid arguments"<<endl;
            return;
        }
        if(idx==0){

            addFirst(val);

        }else if(idx==sz){

            addLast(val);

        }else{

            Node * node = new Node();
            node->data=val;
            Node* temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
            sz++;
        }
    }
    void removeLast()
    {
        if(sz==0){
            cout<<"List is empty"<<endl;
            return;
        }
        Node * temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        sz--;


    }
    void removeAt(int idx)
    {
    }
    void testList()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << endl;
        }
        cout << sz << endl;

        if (sz > 0)
        {
            cout << tail->data << endl;
        }
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    string s;
    cin >> s;
    while (s != "quit")
    {
        if (s == "addLast")
        {
            int val;
            cin >> val;
            list->addLast(val);
        }
        else if (s == "size")
        {
            cout << list->size() << endl;
        }
        else if (s == "display")
        {
            list->display();
        }
        else if (s == "removeFirst")
        {
            list->removeFirst();
        }
        else if (s == "getFirst")
        {
            int val = list->getFirst();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (s == "getLast")
        {
            int val = list->getLast();
            if(val!=-1){
                cout<<val<<endl;
            }
        }
        else if (s == "getAt")
        {
            int idx;
            cin >> idx;
            int val = list->getAt(idx);
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (s == "addFirst")
        {
            int val;
            cin >> val;
            list->addFirst(val);
        }
        else if (s == "addAt")
        {
            int idx, val;
            cin >> idx >> val;
            list->addAt(idx, val);
        }
        else if (s == "removeLast")
        {
            list->removeLast();
        }
        else if (s == "removeAt")
        {
            int idx;
            cin >> idx;
            list->removeAt(idx);
        }
        else if (s == "display")
        {
            list->display();
        }
        cin >> s;
    }

    return 0;
}
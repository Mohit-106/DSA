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
        }
        else if (idx < 0 || idx > sz - 1)
        {
            cout << "Invalid arguments" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }
    void addFirst(int val)
    {
        if (sz == 0)
        {
            addLast(val);
        }
        else
        {
            Node *node = new Node();
            node->data = val;
            node->next = head;
            head = node;
            sz++;
        }
    }
    void addAt(int idx, int val)
    {
        if (idx < 0 || idx > sz)
        {
            cout << "Invalid arguments" << endl;
            return;
        }
        if (idx == 0)
        {

            addFirst(val);
        }
        else if (idx == sz)
        {

            addLast(val);
        }
        else
        {

            Node *node = new Node();
            node->data = val;
            Node *temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            sz++;
        }
    }
    void removeLast()
    {
        if (sz == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        sz--;
    }

    Node * left;

    void foldHelper(Node * right , int state){

        if(right==NULL){
            return;
        }

        foldHelper(right->next, state+1);
        if(state>this->sz/2){
            Node * temp = left->next;
            right->next=left->next;
            left->next=right;
            left=temp;

        }else if(state==this->sz/2){
            tail=right;
            right->next=NULL;

        }
            

    }

    void fold(){
        left=this->head;
        foldHelper(this->head,0);
    }

    int addTolistsHelper(Node * h1, int state1, Node * h2, int state2,LinkedList* ansList){

        if(h1==NULL && h2==NULL){
            return 0;
        }

        if(state1>state2){

            int c = addTolistsHelper(h1->next,state1-1,h2,state2,ansList);
            int ans=h1->data+c;
            int carry = ans/10;
            int val = ans%10;
            ansList->addFirst(val);
            return carry;


        }else if(state1<state2){
            int c = addTolistsHelper(h1,state1,h2->next,state2-1,ansList);
            int ans=h2->data+c;
            int carry = ans/10;
            int val = ans%10;
            ansList->addFirst(val);
            return carry;
           

        }else{
           int c=  addTolistsHelper(h1->next,state1-1,h2->next,state2-1,ansList);
           int ans = h1->data+h2->data+c;
           int carry = ans/10;
           int val = ans%10;
           ansList->addFirst(val);
           return carry;
        }

    }

    LinkedList * addTolists(LinkedList *l1, LinkedList *l2){

        LinkedList *ans = new LinkedList();

        int carry = addTolistsHelper(l1->head,l1->sz,l2->head,l2->sz,ans);
        if(carry>0){
            ans->addFirst(carry);
        }
        return ans;
    }

 

};

int main()
{
    LinkedList *l1 = new LinkedList();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        l1->addLast(data);
    }
      LinkedList *l2 = new LinkedList();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;
        l2->addLast(data);
    }
    LinkedList * sum = sum->addTolists(l1,l2);
    int a,b;
    cin>>a>>b;
    l1->display();
    l2->display();
    sum->display();
    sum->addFirst(a);
    sum->addLast(b);
    sum->display();
    

    return 0;
}
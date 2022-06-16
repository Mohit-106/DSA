#include <bits/stdc++.h>
#include <exception>
using namespace std;

class Stack
{

public:
    int *arr;
    int tos;
    int MaxCapacity;

public:
    Stack(int size)
    {
        this->MaxCapacity = size;
        this->arr = new int[this->MaxCapacity];
        this->tos = -1;
    }

public:
    Stack()
    {
        Stack(10);
    }

public:
    int size()
    {
        return tos + 1;
    }

public:
    void push(int data)
    {
        if (tos == MaxCapacity - 1)
        {
            this->MaxCapacity = 2*MaxCapacity;
            int *arr2 = new int [MaxCapacity];
            for(int i=0; i<=tos; i++){
                arr2[i]=arr[i];
            }
            this->arr= arr2;
        }
        else
        {
            tos++;
            arr[tos] = data;
        }
    }

public:
    int top()
    {
        if (tos == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[tos];
    }

public:
    int pop()
    {
        if (tos == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int val = arr[tos];
        tos--;
        return val;
    }

public:
    void display()
    {
        if (tos == -1)
        {
            cout << " " << endl;
            return;
        }
        for (int i = tos; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    Stack st(n);
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        else if (str == "display")
        {
            st.display();
        }
        cin >> str;
    }
}
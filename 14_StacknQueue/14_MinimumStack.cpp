#include <bits/stdc++.h>
using namespace std;

class Minstack
{

    stack<int> allstack;
    stack<int> minstack;

public:
    int size()
    {
        return allstack.size();
    }

    void push(int data)
    {
        allstack.push(data);
        if (minstack.size() == 0 || data <= minstack.top())
        {
            minstack.push(data);
        }
    }

    int pop()
    {
        if (allstack.size() == 0)
        {
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
        if (allstack.top() == minstack.top())
        {
            int val = allstack.top();
            allstack.pop();
            minstack.pop();
            return val;
        }
        else
        {
            int val = allstack.top();
            allstack.pop();
            return val;
            
        }
    }

    int top()
    {
        if (allstack.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return allstack.top();
    }

    int min()
    {
        if (allstack.size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return minstack.top();
    }
};

int main()
{
   Minstack st;

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
        else if (str == "min")
        {
            int val = st.min();
            if (val != -1)
            {
                cout << val << endl;
            }
        }

        cin >> str;
    }
}

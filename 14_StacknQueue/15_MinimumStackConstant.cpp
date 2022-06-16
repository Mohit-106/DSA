#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> data;
    int minVal;

public:
    int size()
    {
        return data.size();
    }

public:
    void push(int val)
    {
        if (size() == 0)
        {
            data.push(val);
            minVal = val;
            return;
        }
        if (val >= minVal)
        {
            data.push(val);
        }
        else
        {
            int eval = val + (val - minVal);
            minVal = val;
            data.push(eval);
        }
    }

public:
    int pop()
    {
        if (size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        if (data.top() >= minVal)
        {
            int topVal = data.top();
            data.pop();
            return topVal;
        }
        else
        {
            int eVal = minVal;
            minVal = 2 * minVal - data.top();
            data.pop();
            return eVal;
        }
    }

public:
    int top()
    {
        if (size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        if (data.top() >= minVal)
        {

            return data.top();
        }
        else
        {
            return minVal;
        }
    }

public:
    int min()
    {
        if (size() == 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return minVal;
    }
};

int main()
{
    MinStack st;

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
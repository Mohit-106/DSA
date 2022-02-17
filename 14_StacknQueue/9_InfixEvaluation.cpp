#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{

    if (ch == '-' || ch == '+')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int operation(int v1, int v2, char ch)
{

    if (ch == '+')
    {

        return v1 + v2;
    }
    else if (ch == '-')
    {
        return v1 - v2;
    }
    else if (ch == '/')
    {
        return v1 / v2;
    }
    else
    {
        return v1 * v2;
    }
}

int main()
{

    string s;
    getline(cin, s);
    stack<int> vstack;
    stack<char> ostack;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            ostack.push(ch);
        }
        else if (ch >= '0' && ch <= '9')
        {
            vstack.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            while (ostack.size() > 0 && ostack.top() != '(' && precedence(ch) <= precedence(ostack.top()))
            { 
              //we need to write this ost.to()!='(' because + cant compate with precedence of bracket

                int v2 = vstack.top();
                vstack.pop();
                int v1 = vstack.top();
                vstack.pop();
                char op = ostack.top();
                ostack.pop();
                int ans = operation(v1, v2, op);
                vstack.push(ans);
            }

            ostack.push(ch);
        }
        else if (ch == ')')
        {

            while (ostack.size() > 0 && ostack.top() != '(')
            {

                int v2 = vstack.top();
                vstack.pop();
                int v1 = vstack.top();
                vstack.pop();
                char op = ostack.top();
                ostack.pop();
                int ans = operation(v1, v2, op);
                vstack.push(ans);
            }
            ostack.pop();
        }
    }
    while (ostack.size() > 0)
    {
        int v2 = vstack.top();
        vstack.pop();
        int v1 = vstack.top();
        vstack.pop();
        char op = ostack.top();
        ostack.pop();
        int ans = operation(v1, v2, op);
        vstack.push(ans);
    }
    cout << vstack.top() << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str;
    getline(cin, str);
    stack<char> st;
    for (char ch : str)
    {

        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.size() == 0)
            {
                cout << "false" << endl;
                return 0;
            }
            else if (st.top() == '[' || st.top() == '{')
            {
                cout << "false" << endl;
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        else if (ch == ']')
        {
            if (st.size() == 0)
            {
                cout << "false" << endl;
                return 0;
            }
            else if (st.top() == '(' || st.top() == '{')
            {
                cout << "false" << endl;
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        else if (ch == '}')
        {
            if (st.size() == 0)
            {
                cout << "fasle" << endl;
                return 0;
            }
            else if (st.top() == '[' || st.top() == '(')
            {
                cout << "false" << endl;
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }


    if(st.size()>0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }

    return 0;
}
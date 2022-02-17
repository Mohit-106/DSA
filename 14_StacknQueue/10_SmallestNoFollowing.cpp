#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    getline(cin, s);

    int num = 1;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {

        char ch = s[i];
        if (ch == 'd')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;
            while (st.size() > 0)
            {
                int val = st.top();
                st.pop();
                cout << val;
            }
        }
    }
    
    st.push(num);
    while (st.size() > 0)
    {
        int val = st.top();
        st.pop();
        cout << val;
    }

    return 0;
}
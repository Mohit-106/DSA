#include <bits/stdc++.h>
using namespace std;

int Encodings2(string str, int idx, vector<int> &dp)
{

    if (idx == str.size())
    {
        return dp[idx] = 1;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    char ch = str[idx];
    int count = 0;
    if (ch != '0')
    {
        count += Encodings2(str, idx + 1, dp);
        if (idx < str.size() - 1)
        {
            int num = (ch - '0') * 10 + (str[idx + 1] - '0');
            if (num <= 26)
            {
                count += Encodings2(str, idx + 2, dp);
            }
        }
    }
    return dp[idx] = count;
    
}

int main()
{

    string str;
    cin >> str;
    vector<int> dp(str.size() + 1, -1);
    cout << Encodings2(str, 0, dp);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &dp)
{

    for (int &val : dp)
    {
        cout << val << " ";
    }
}

int rec(int n, int m, vector<int> &dp)
{

    if (n < m)
    {
        dp[n] = 1;

        return 1;
    }
    if (n == m)
    {
        dp[n] = 2;
        return 2;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int val1 = rec(n - 1, m, dp);
    int val2 = rec(n - m, m, dp);
    int ans = val1 + val2;
    dp[n] = ans;
    return ans;
}

int memo(int & n, int & m)
{

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
    {
 
        if (i < m)
        {
            dp[i] = 1;
        }
        else if (i == m)
        {
            dp[i] = 2;
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - m];
        }
        

    }

    return dp[n];
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1);
    // cout<<rec(n,m,dp)<<endl;
    cout << memo(n, m) << endl;
   

    return 0;
}
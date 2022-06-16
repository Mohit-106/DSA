#include <bits/stdc++.h>
using namespace std;
int Fab(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        dp[n]=n;
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    // cout << n << endl;
    int a = Fab(n - 1, dp);
    int b = Fab(n - 2, dp);
    int c = a + b;
    dp[n]=c;
    return c;
}

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    int ans = Fab(n, dp);
    cout << ans << endl;

    // for(int val : dp){
    //     cout<<val<<" ";
    // }

    return 0;
}

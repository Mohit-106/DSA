#include <bits/stdc++.h>
using namespace std;

int Count(int n)
{

    vector<vector<int>> dp(2, vector<int>(n + 1));
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {

        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[1][i - 1] + dp[0][i - 1];
    }
    return dp[0][n] + dp[1][n];
}

int Count2(int n)
{

    int val1 = 1;
    int val2 = 1;
    for (int i = 2; i <= n; i++)
    {

        int temp1 = val2;
        int temp2 = val1 + val2;

        val1 = temp1;
        val2 = temp2;
    }
    return val1 + val2;
}

int main()
{

    int n;
    cin >> n;

    cout << Count(n);
    cout<<endl;
    cout<< Count(n);
  
    return 0;
}
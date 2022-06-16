// So im not going to solve for n tiles
// I will solve for only base cases 0,1,2
// Now if i can figure out how to solve for 0,1 and 2 width tiles
// I can solve for tile of width 3 using width 1 and 2
// And same for width 4 using tile of width 3 and 1
// and so on and so for.... till n
// Now i can easily get the solution for n*2 tiles
// Just by Breaking down tiles into pieces

#include <bits/stdc++.h>
using namespace std;

int memo(int n, vector<int> &dp)
{

    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    if (n == 1)
    {
        dp[1] = 1;
        return 1;
    }
    if (n == 2)
    {
        dp[2] = 2;
        return 2;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int val1 = memo(n - 1, dp);
    int val2 = memo(n - 2, dp);
    int ans = val1 + val2;
    dp[n] = ans;
    return ans;
}




int tab(int n)
{

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int &val : dp)
    {
        cout << val << " ";
    }
    cout<<endl;

    return dp[n];
}

int main()
{

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    int ans = memo(n, dp);
    cout << ans << endl;
    for (int &val : dp)
    {
        cout << val << " ";
    }
    cout<<endl;

    cout<<"----------"<<endl;

    int ans2 = tab(n);
    cout << ans2 << endl;
}
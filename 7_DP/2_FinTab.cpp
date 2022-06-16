#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{

    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = i;
            continue;
        }

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fib2(int n)
{

    if (n <= 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    for (int i = 0; i <n;i++){
        int c= a+b;
        a=b;
        b=c;
    }

    return a;

}

int main()
{

    int n;
    cin >> n;
    cout << fib2(n);

    return 0;
}
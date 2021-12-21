#include <bits/stdc++.h>
using namespace std;
int fib(int n)

{

    if (n == 0 || n == 1)
    {
        return n;
    }
    int x = fib(n - 1);
    int y = fib(n - 2);
    int ans = x + y;
    return ans;
    
}

int fibMemoized(int n, vector<int> &qb)

{

    if (n == 0 || n == 1)
    {
        return n;
    }

    if (qb[n] != 0)
    {
        return qb[n];
    }

    int x = fibMemoized(n - 1, qb);
    int y = fibMemoized(n - 2, qb);
    int ans = x + y;
    qb[n] = ans;
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> qb(n + 1);
    // cout << fib(n) << endl;
    cout << fibMemoized(n, qb);

    return 0;
}
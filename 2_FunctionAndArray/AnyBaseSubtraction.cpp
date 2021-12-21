#include <bits/stdc++.h>
using namespace std;
// constraint n>m


int DecimalSubtraction(int n, int m)
{

    int ans = 0, p = 1, borrow = 0;
    while (n != 0)
    {

        int sub = n % 10 - m % 10 + borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = -1;
        }
        else
            borrow = 0;

        ans += sub * p;
        p *= 10;
        n /= 10;
        m /= 10;
    }
    return ans;
}

int AnyBaseSubtraction(int n, int m, int b)
{

    int ans = 0, p = 1, borrow = 0;
    while (n != 0)
    {

        int sub = n % 10 - m % 10 + borrow;
        if (sub < 0)
        {
            sub += b;
            borrow = -1;
        }
        else
            borrow = 0;

        ans += sub * p;
        p *= 10;
        n /= 10;
        m /= 10;
    }
    return ans;
}

int main()
{

    int n, m, b;
    cin >> n >> m >> b;
    cout << DecimalSubtraction(n, m) << endl;

    return 0;
}
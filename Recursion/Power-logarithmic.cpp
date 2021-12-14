#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{

    if (n == 0)
    {
        return 1;
    }

    int z = power(x, n / 2);
    if (n % 2 == 0)
    {

        int ans = z * z;
        return ans;
    }
    else
    {

        int ans = x * z * z;
        return ans;
    }
}
int main()
{

    int x, n;
    cin >> x >> n;
    cout << power(x, n);
    return 0;
}
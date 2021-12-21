#include <bits/stdc++.h>
using namespace std;

void StringsByusingSpace(int n)
{

    vector<int> dp0(n + 1);
    vector<int> dp1(n + 1);

    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= n; i++)
    {

        dp0[i] = dp1[i - 1];
        dp1[i] = dp0[i - 1] + dp1[i - 1];
    }

    cout << dp0[n] + dp1[n] << endl;
}

void StringsWithoutUsingSpace(int n)
{

    int ew0 = 1;
    int ew1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int new0 = ew1;
        int new1 = ew1 + ew0;

        ew1 = new1;
        ew0 = new0;
    }

    cout << ew0 + ew1 << endl;
}

int main()
{

    int n;
    cin >> n;

    StringsByusingSpace(n);
    StringsWithoutUsingSpace(n);

    return 0;
}
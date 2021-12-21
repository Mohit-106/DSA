#include <bits/stdc++.h>
using namespace std;

int Gcd(int n1, int n2)
{

    while (n2 % n1 != 0)
    {
        int rem = n2 % n1;
        n2 = n1;
        n1 = rem;
    }

    return n1;
}

int Lcm(int n1, int n2)
{

    int GDC = Gcd(n1, n2);
    int LCM = (n1 * n2) / GDC;
    return LCM;
}

int main()
{

    int n1, n2;
    //n2>n1

    cin >> n1 >> n2;

    cout << Gcd(n1, n2) << endl;
    cout << Lcm(n1, n2) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void isPrime(int n)
{
    int count = 0;

    for (int i = 2; i*i <= n; i++)
    {

        if (n % i == 0)
        {

            count++;
            break;
            
        }
    }

    if (count == 1)
    {

        cout << "NotPrime" << endl;

    }

    else
    {

        cout << "Prime" << endl;

    }

}

int main()
{

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        isPrime(n);
    }

    return 0;
}
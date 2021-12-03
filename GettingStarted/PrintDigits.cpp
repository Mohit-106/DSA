#include <bits/stdc++.h>
using namespace std;
int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

void PrintDigit(int n)
{

    int p = 1;
    int dc = countDigit(n);
    int temp = dc;
    while (temp != 0)
    {
        int x = dc - p;
        int power = pow(10, x);
        int q = n / power;
        n = n % power;
        cout << q << endl;
        p++;
        temp--;
    }
}

int main()
{

    int n;
    cin >> n;
    PrintDigit(n);

    return 0;
}

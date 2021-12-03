#include <bits/stdc++.h>
using namespace std;

int Inverse(int n)
{
    int lastDigit;
    int ans = 0;
    int p=1;
    int index=1;
    while (n != 0)
    {

        lastDigit = n % 10;
       int  power=lastDigit-1;
        p=pow(10,power);

        ans+=index*p;
        index++;
        n/=10;

        
    }
    return ans;



}

int main()
{

    int n;
    cin >> n;
    cout << Inverse(n);

    return 0;
}
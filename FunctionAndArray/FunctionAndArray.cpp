#include <bits/stdc++.h>
using namespace std;


int Q1_DigitFreq(long long n, long long d)
{
    int lastDigit, count = 0;
    while (n != 0)
    {
        lastDigit = n % 10;
        n = n / 10;
        if (d == lastDigit)
        {
            count++;
        }
    }

    return count;
}


int DecimaltoBinary(int n)
{
    int rem, pow = 1, ans = 0;

    while (n != 0)
    {

        rem = n % 2;
        n = n / 2;
        ans += rem * pow;
        pow *= 10;
    }

    return ans;
}


int BinarytoDecimal(int n)
{
    int pow2=1, ans=0, rem;

    while(n!=0){

        rem=n%2;
        n=n/10;
        ans+=rem*pow2;
        pow2*=2;

    }
    return ans;
}


int main()
{

    int n;
    cin >> n;
    cout << BinarytoDecimal(n) << endl;

    return 0;
}

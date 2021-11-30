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
    int pow2 = 1, ans = 0, rem;

    while (n != 0)
    {

        rem = n % 2;
        n = n / 10;
        ans += rem * pow2;
        pow2 *= 2;
    }
    return ans;
}

int DecimalToAnyBase(int n, int b)
{

    int pow2 = 1, ans = 0, rem;

    while (n != 0)
    {

        rem = n % b;
        n = n / b;
        ans += rem * pow2;
        pow2 *= 10;
    }
    return ans;
}
int AnyBaseToDecimal(int n, int b, int a)
{
    int pow_b=1, ans=0, rem;

    while(n!=0){
        rem=n%a;
        ans+=rem*pow_b;
        n/=a;
        pow_b*=b;
    }
    return ans;
}

int main()
{

    int n, b;
    cin >> n >> b;
    cout << DecimalToAnyBase(n, b) << endl;

    return 0;
}

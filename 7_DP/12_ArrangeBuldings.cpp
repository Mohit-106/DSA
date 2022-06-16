#include <bits/stdc++.h>
using namespace std;
long Arrange(int n)
{

    long Val1 = 1;
    long Val2 = 1;
    for (int i = 2; i <= n; i++)
    {

        long temp1 = Val2;
        long temp2 = Val1 + Val2;
        Val1 = temp1;
        Val2 = temp2;
        
    }
    return (Val1 + Val2) * (Val1 + Val2);

}

int main()
{
    int n;
    cin >> n;
    cout << Arrange(n);
}
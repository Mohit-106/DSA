#include <bits/stdc++.h>
using namespace std;
int check(int n)
{

    if (n <= 1)
    {
        cout << "Base" << n << endl;
        return n + 3;
    }
    int count = 0;
    cout << "pre" << n << endl;
    count += check(n - 1);
    cout << "in" << n << endl;
    count += check(n - 2);
    cout << "post" << n << endl;
    return count + 3;
    
}

int main()
{

    int n;
    cin >> n;
    check(n);
    return 0;

}
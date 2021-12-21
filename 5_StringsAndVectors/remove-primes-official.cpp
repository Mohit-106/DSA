#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void RemovePrimes(vector<int> &arr)
{

    
    for (int i = arr.size() - 1; i >= 0; i--)
    {

        if (isPrime(arr[i]))
        {
            arr.erase(arr.begin() + i);
        }
    }
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {

        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    RemovePrimes(arr);
}
#include <bits/stdc++.h>
using namespace std;

void Subsets(vector<int> &arr)
{
    int n = arr.size();
    int j = pow(2, n);

    for (int i = 0; i < j; i++)
    {

        vector<int> v(n, 0);
        int val = n - 1;
        int temp = i;

        while (i != 0)
        {

            int rem = temp % 2;
            v[val] = rem;
            temp /= 2;
            val--;
        }

        for (int k = 0; k < n; k++)
        {
            if (v[i] == 0)
            {
                cout << "-"
                     << "\t";
            }
            else
            {
                cout << arr[i] << "\t";
            }
        }

        cout << endl;
    }
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

    Subsets(arr);

    return 0;
}
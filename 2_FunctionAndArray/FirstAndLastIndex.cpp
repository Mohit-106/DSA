
#include <bits/stdc++.h>
using namespace std;

int LastIndex(vector<int> &arr, int low, int high, int x)
{

    while (low <= high)
    {
        int mid = mid + high / 2;

        if (arr[mid] == x)
        {
        }
    }
}

void BinarySearch(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid, fi;
    while (low <= high)
    {

        mid = low + high / 2;

        if (arr[mid] == x)
        {

            fi = arr[mid];
            high = mid - 1;
        }
        else if (arr[mid] > x)
        {

            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }

    cout << fi << endl;
}

int main()
{

    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    BinarySearch(arr, x);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void CeilFloor(vector<int> &arr, int k)
{

    int n = arr.size();
    int floor = -1, ceil = -1, low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            cout << arr[mid];
            return;
        }
        else if (arr[mid] > k)
        {
            ceil = arr[mid];
            high = mid - 1;
        }
        else
        {
            floor = arr[mid];
            low = mid + 1;
        }
    }

    cout << ceil << endl;
    cout << floor << endl;
}

int main()
{

    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    CeilFloor(arr, k);

    return 0;
}
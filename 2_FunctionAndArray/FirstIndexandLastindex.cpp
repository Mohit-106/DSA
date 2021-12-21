#include <bits/stdc++.h>
using namespace std;
void FirstandLast(vector<int> &arr, int k)
{

    int n = arr.size();

    int low = 0, high = n - 1, li, fi;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            fi = mid;
            high = mid - 1;
        }
    }

    cout << fi << endl;

    low = 0;
    high = n - 1;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            li = mid;
            low = mid + 1;
        }
    }
    cout << li << endl;
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

    FirstandLast(arr, k);

    return 0;
}
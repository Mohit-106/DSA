#include <bits/stdc++.h>
using namespace std;

int swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Reverse(vector<int> &arr, int i, int j)
{

    while (i <= j)
    {
        swap(arr, i, j);
        i++, j--;
    }

}

void Rotate(vector<int> &arr, int k)
{
 int n = arr.size();
    k = k % n;
    if (k < 0)
    {
        k += n;
    }

   
    int i = 0, j = n - k - 1, l = n - k, m = n - 1;

    Reverse(arr, i, j);
    Reverse(arr, l, m);
    Reverse(arr, 0, n - 1);

   
}

void Display(vector<int>&arr){
     for (auto value : arr)
    {
        cout << value << " ";
    }
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

    Rotate(arr, k);
    Display(arr);

    return 0;
}
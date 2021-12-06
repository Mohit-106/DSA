#include <bits/stdc++.h>
using namespace std;

int MaxNo(vector<int> &arr)
{

    int n = arr.size();
    int Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        Max = max(arr[i], Max);
    }
    return Max;
}

void BarChart(vector<int> &arr)
{

    int n = arr.size();
    int rows = MaxNo(arr);

    for (int r = rows; r >= 1; r--)
    {

        for (int c = 0; c < n; c++)
        {

            if (arr[c] >= r)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }

        cout << endl;
    }

}

void InvertedBarChart(vector<int> &arr)
{

    int n = arr.size();
    int rows = MaxNo(arr);

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (arr[c] >= r)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
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

    BarChart(arr);
    cout<<endl;
    InvertedBarChart(arr);

    return 0;
}
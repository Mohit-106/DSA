#include <bits/stdc++.h>
using namespace std;

void SP(vector<vector<int>> &arr)
{

    int n = arr.size();

    for (int r = 0; r < n; r++)
    {

        int idx = 0;
        for (int c = 1; c < n; c++)
        {

            if (arr[r][c] < arr[r][idx])
            {

                idx = c;

            }

        }

        
        bool flag=true;
        for (int col = 0; col < n; col++)
        {

            if (arr[r][idx] < arr[col][idx])
            {
               flag=false;
               break;
            }
        }

        if(flag==true){
            cout<<arr[r][idx];
            return;
        }

        
    }

    cout << "Invalid input" << endl;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    SP(arr);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void paint(vector<vector<int>> &arr, int n, int k)
{

    vector<vector<int>> dp(n, vector<int>(k));

    for (int i = 0; i < k; i++)
    {
        dp[0][i] = arr[0][i];
    }

    int least = INT_MAX;
    int least2 = INT_MAX;
    for (int j = 0; j < k; j++)
    {
        if (arr[0][j] <= least)
        {
            least2 = least;
            least = arr[0][j];
        }
        else if (arr[0][j] <= least2)
        {
            least2 = arr[0][j];
        }
    }

    for (int i = 1; i < n; i++)
    {

        int nleast = INT_MAX;
        int nleast2 = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if (arr[i - 1][j] != least)
            {
                dp[i][j] += least;
            }
            else
            {
                dp[i][j] += least2;
            }

            if (dp[0][j] <= nleast)
            {
                nleast2 = nleast;
                nleast = dp[0][j];
            }
            else if (dp[0][j] <= nleast2)
            {
                nleast2 = dp[0][j];
            }
        }

        least=nleast;
        least2=nleast2;


    }
    cout<<least<<endl;


}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }

    paint(arr, n, k);

    return 0;
}

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int k;
//     cin >> k;
//     vector<vector<int>> arr(n, vector<int>(k, 0));
//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = 0; j < arr[0].size(); j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     // min values ;
//     int min = INT_MAX;
//     int smin = INT_MAX;
//     //get min and second min from first column
//     for (int j = 0; j < arr[0].size(); j++)
//     {
//         if (arr[0][j] <= min)
//         {
//             smin = min;
//             min = arr[0][j];
//         }
//         else if (arr[0][j] <= smin)
//         {
//             smin = arr[0][j];
//         }
//     }
//     // get answer
//     for (int i = 1; i < arr.size(); i++)
//     {
//         int cmin = INT_MAX;
//         int csmin = INT_MAX;

//         for (int j = 0; j < arr[i].size(); j++)
//         {
//             if (arr[i - 1][j] != min)
//             {
//                 arr[i][j] += min;
//             }
//             else
//             {
//                 arr[i][j] += smin;
//             }

//             if (arr[i][j] <= cmin)
//             {
//                 csmin = cmin;
//                 cmin = arr[i][j];
//             }
//             else if (arr[i][j] <= csmin)
//             {
//                 csmin = arr[i][j];
//             }
//         }

//         min = cmin;
//         smin = csmin;
//     }

//     cout << min;
// }
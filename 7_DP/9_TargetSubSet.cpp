#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
int vl = 0;
void targetSumPair(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (dp[i - 1][j] == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int val = arr[i - 1];
                    if (j >= val && dp[i - 1][j - val] == 1)
                    {
                        dp[i][j] = 1;
                    }
                }
            }
            // vl++;
        }
    }
    if (dp[n][target])
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    // cout<<vl<<endl;
}

int main()
{

    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;
   targetSumPair(vec, target);
   

   
    return 0;
}
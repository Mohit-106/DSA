#include <bits/stdc++.h>
using namespace std;

int Knapsack(vector<int> &runs, vector<int> &balls, int cap)
{

    int m = cap + 1;
    int n = runs.size() + 1;

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            int run = runs[i - 1];
            int ball = balls[i - 1];
            if (ball <= j)
            {

                dp[i][j] = max(run + dp[i - 1][j - ball], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] == dp[i - 1][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> runs(n);
    vector<int> balls(n);
    for (int i = 0; i < n; i++)
    {

        cin >> runs[i];
    }
    for (int i = 0; i < n; i++)
    {

        cin >> balls[i];
    }

    int cap;
    cin >> cap;

    cout << Knapsack(runs, balls, cap);

    return 0;
}
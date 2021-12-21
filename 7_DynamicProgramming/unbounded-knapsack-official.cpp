#include <bits/stdc++.h>
using namespace std;

int Knapsack(vector<int> &runs, vector<int> &balls, int cap)
{

    vector<int> dp(cap + 1);

    for (int i = 1; i <= cap; i++)
    {

        int Max = 0;

        for (int j = 0; j < balls.size(); j++)
        {

            if (balls[j] <= i)
            {

                int val = dp[i - balls[j]] + runs[j];
                Max = max(Max, val);
            }
        }

        dp[i] = Max;
    }

    return dp[cap];
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
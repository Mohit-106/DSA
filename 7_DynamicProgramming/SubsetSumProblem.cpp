#include <bits/stdc++.h>
using namespace std;

bool Subset(vector<int> &arr, int tar)
{

    int n = arr.size() + 1;
    int m = tar + 1;

    vector<vector<bool>> dp(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (i == 0 && j == 0)
            {

                dp[i][j] = true;
            }
            else if (i == 0)
            {

                dp[i][j] = false;
            }
            else if (j == 0)
            {

                dp[i][j] = true;
            }
            else
            {
               

                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else {
                    int val = arr[i - 1];
                    if(j>=val){
                        if(dp[i-1][j-val]==true){
                            dp[i][j]=true;
                        }
                    }
                   

                }

             
               
            }
        }
    }

    return (dp[n-1][m-1]);
}

int main()
{

    int n;
    cin >> n;
    vector<int>arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tar;
    cin >> tar;

    bool ans =Subset(arr, tar);
    if(ans==1){

        cout<<"true"<<endl;

    }else{
        cout<<"false"<<endl;
    }


    return 0;
}
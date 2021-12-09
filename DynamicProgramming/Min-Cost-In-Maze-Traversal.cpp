#include <bits/stdc++.h>
using namespace std;

int Maze(vector<vector<int>> &arr)

{
    int n=arr.size();
    int m=arr[0].size();
     vector<vector<int>>dp(n,vector<int>(m));

    for(int r=n-1; r>=0; r--){
        for(int c=m-1; c>=0; c--){

            if(r==n-1 && c==m-1){

                dp[r][c]=arr[r][c];

            }else if(r==n-1){

                dp[r][c]=arr[r][c]+dp[r][c+1];

            }else if(c==m-1){
                dp[r][c]=arr[r][c]+dp[r+1][c];

            }else{

                dp[r][c]=min(dp[r+1][c],dp[r][c+1])+arr[r][c];

            }



        }

    }

    return dp[0][0];


}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
   

    cout << Maze(arr);

    return 0;

}
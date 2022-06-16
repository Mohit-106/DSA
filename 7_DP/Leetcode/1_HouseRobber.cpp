// https://leetcode.com/problems/house-robber/
//  Test Case
// 200 7 9 100 8

#include <bits/stdc++.h>
using namespace std;
int HouseRob(vector<int> &arr, int i, vector<int> &dp)
{

    if (i == arr.size())
    {
        return dp[i] = 0;
    }
    if (i > arr.size())
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int val1 = arr[i] + HouseRob(arr, i + 2, dp);
    int val2 = HouseRob(arr, i + 1, dp);
    return dp[i]=max(val1,val2);
}


int memo(vector<int>&arr, int n){

    int inc=arr[0];
    int exe = 0;
    for(int i=1;i<n;i++){

        int tinc = exe;
        int texe = max(inc,exe);

        inc=tinc+arr[i];
        exe= texe;


    }

    return max(inc,exe);

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
    vector<int> dp(n + 1, -1);

    cout << HouseRob(arr, 0, dp)<<endl;
    cout<<memo(arr,n)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

int vl1 = 0;
int vl2 = 0;
bool rec(vector<int> &arr, int i, int j)
{

    if (i == 0 && j == 0)
    {

        return true;
    }
    if (i == 0)
    {

        return false;
    }
    if (j == 0)
    {

        return true;
    }
    if (j < 0)
    {
        return false;
    }

    bool val1 = rec(arr, i - 1, j);
    vl1++;
    if (val1 == true)
    {

        return true;
    }

    bool val2 = rec(arr, i - 1, j - arr[i - 1]);
    vl1++;
    if (val2 == true)
    {
        return true;
    }

    return false;
}


bool rec2(vector<int> &arr, int i, int j,vector<vector<int>>&dp)
{

    if (i == 0 && j == 0)
    {
       
        return true;
    }
    if (i == 0)
    {
       
        return false;
    }
    if (j == 0)
    {
        return true;
    }
    if (j < 0)
    {
        return false;
    }

    if(dp[i][j]!=-1){
        if(dp[i][j]==1){
            return true;
        }else{
            return false;
        }
    }

    

    bool val1 = rec2(arr, i - 1, j,dp);
    vl2++;
    if (val1 == true)
    {
        dp[i][j]=1;
        return true;
    }

    bool val2 = rec2(arr, i - 1, j - arr[i - 1],dp);
    vl2++;
    if (val2 == true)
    {
        dp[i][j]=0;
        return true;
    }
    dp[i][j]=0;
    return false;
}

int main()
{

    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;

    bool ans = rec(vec, n, target);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    cout<<vl1<<endl;
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

    bool ans2 = rec2(vec,n,target,dp);
    if (ans2)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout<<vl2<<endl;

    return 0;
}


//why code is efficient equally even when we dont use dp storage 
// It is because of dependency of any other cell is eithe above one or in the left
//To make dp storage relevent there should be multiple occurrance of same element 
//And such test cases are very rare
//But yes it can be there 

//This above code will not work for below given test case
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 10

//But the code with dp storage run well in all cases
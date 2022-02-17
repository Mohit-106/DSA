#include <bits/stdc++.h>
using namespace std;

void countisland(vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &visited)
{

    if(i<0 || j<0 || i>=arr.size() || j >= arr[0].size() || visited[i][j]==true || arr[i][j]==1){
        return;
    }

    visited[i][j] = true;
    countisland(arr, i+1, j, visited);
    countisland(arr, i, j+1, visited);
    countisland(arr, i-1, j, visited);
    countisland(arr, i, j-1, visited);
    
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++)
        {
            int res;
            cin >> res;
            ans.push_back(res);
        }
        arr.push_back(ans);
    }

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && arr[i][j] == 0)
            {
                countisland(arr, i, j, visited);
                count+=1;
            }
        }
    }

    cout << count << endl;
}
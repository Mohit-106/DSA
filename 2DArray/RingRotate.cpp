#include <bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

    }
}

void RingRotate(vector<vector<int>> &mat, int s, int r)
{

}

int main()
{

    int n, m, s, r;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> s >> r;
    RingRotate(mat, s, r);
    return 0;

}
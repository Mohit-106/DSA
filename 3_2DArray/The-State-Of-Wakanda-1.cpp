#include <bits/stdc++.h>
using namespace std;

void Wakanda(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    int row = 0, col = 0;

    while (col < m)
    {

        if (col % 2 == 0)
        {
            row = 0;
            while (row < n)
            {

                cout << mat[row][col] << endl;
                row++;
            }
        }
        else
        {
            row = n - 1;
            while (row >=0 )
                
            {
                cout << mat[row][col] << endl;
                row--;
            }
        }



        col++;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    Wakanda(mat);

    return 0;
}
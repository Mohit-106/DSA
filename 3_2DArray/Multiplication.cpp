#include <bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>> &mat)
{

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {

            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Multiplication(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{

    if(mat1[0].size()!=mat2.size()){
        cout<<"Invalid input"<<endl;
        return;
    }

    

    //r1==mat.size(), and c1==mat[0];
    int c1 = 0, r2 = 0, r1 = 0, c2 = 0;
    while (r1 < mat1.size())
    {

        while (r1 < mat1.size() && c2 < mat2[0].size())
        {

            int sum = 0;

            while (c1 < mat1[0].size() && r2 < mat2.size())
            {

                sum += mat1[r1][c1] * mat2[r2][c2];
                c1++;
                r2++;
            }
            cout << sum << " ";
            c1 = 0, r2 = 0;
            c2++;
        }
        cout<<endl;

        c2=0;

        r1++;
    }
}

int main()
{

    // columns of m1 == rows of m2
    // resultant matrix == rows of m1 * columns of m2

    int n, m, n2, m2;
    cin >> n >> m;

    vector<vector<int>> mat1(n, vector<int>(m));
  

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> mat1[i][j];
        }
    }
    cin>>n2>>m2;
    vector<vector<int>> mat2(n2, vector<int>(m2));

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {

            cin >> mat2[i][j];
        }
    }

    Multiplication(mat1, mat2);

    return 0;
}

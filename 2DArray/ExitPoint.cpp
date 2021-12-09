#include <bits/stdc++.h>
using namespace std;

void ExitPoint(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    int dir = 0;
    int i = 0; int j = 0;

    while (true)
    {

        dir+=mat[i][j];
        dir%=4;
        if(dir==0){
            j++;


        }else if(dir==1){
            i++;


        }else if(dir==2){
            j--;

        }else{
            i--;
        }

        if(i<0 || j<0 || i>=n || j>=m){
            break;
        }

    }

    if(j>=m){
        j--;
    }else if(j<0){
        j++;
    }else if(i>=n){
        i--;
    }else if(i<0){
        i++;
    }

    cout<<i<<endl;
    cout<<j<<endl;


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

    ExitPoint(mat);

    return 0;
}


//try by marking visited cell zero!! Happy coding!!
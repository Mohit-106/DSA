#include <bits/stdc++.h>
using namespace std;

void SpiralforSquare(  vector<vector<int>>&mat){

    int n=mat.size();
    int m=mat[0].size();

    int row=0,col=0,erow=n-1,ecol=m-1;
    int count=0;
    int total=m*n;
 while(count<total){


    for(int i=row; i<= erow;i++){
        cout<<mat[i][col]<<endl;
        count++;
    }
    col++;
    for(int j=col; j<=ecol; j++){
        cout<<mat[erow][j]<<endl;
        count++;
    }
    erow--;
    for(int k=erow; k>=row; k--){
        cout<<mat[k][ecol]<<endl;
        count++;
    }
    ecol--;
    for(int l=ecol; l>=col; l--){

        cout<<mat[row][l]<<endl;
        count++;

    }
    row++;
 }
   

}

void SpiralforAll(  vector<vector<int>>&mat){

    int n=mat.size();
    int m=mat[0].size();

    int row=0,col=0,erow=n-1,ecol=m-1;
    int count=0;
    int total=m*n;
 while(count<total){


    for(int i=row; i<= erow && count<total; i++){
        cout<<mat[i][col]<<endl;
        count++;
    }
    col++;
    for(int j=col; j<=ecol  && count<total; j++){
        cout<<mat[erow][j]<<endl;
        count++;
    }
    erow--;
    for(int k=erow; k>=row&& count<total; k--){
        cout<<mat[k][ecol]<<endl;
        count++;
    }
    ecol--;
    for(int l=ecol; l>=col&& count<total; l--){

        cout<<mat[row][l]<<endl;
        count++;

    }
    row++;
 }

}





int main(){

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

     SpiralforAll(mat);



    return 0;
}
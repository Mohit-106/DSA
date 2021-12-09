#include <bits/stdc++.h>
using namespace std;


void Display(vector<vector<int>>&mat){
    int n=mat.size();

    for(int i=0;i<n;i++){
        for(int j=n-1; j>=0; j--){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;

    }


}



void Rotate(vector<vector<int>>&mat){

    int n = mat.size();

    //transpose of the matrix
    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){
           int temp=mat[i][j];
           mat[i][j]=mat[j][i];
           mat[j][i]=temp;
        }


    }


    Display(mat);


}


int main(){

    int n;
    cin>>n;

    vector<vector<int>>mat(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];



        }
    }

    Rotate(mat);

    



    return 0;
}
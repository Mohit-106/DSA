#include <bits/stdc++.h>
using namespace std;

int fact(int n){

    return (n==0)?1:n*fact(n-1);
    // if(n==0){
    //     return 1;
    // }



    // int x= fact(n-1);
    // int ans =x*n;
    // return ans;




}



int main(){

    int n;
    cin>>n;
    cout<<fact(n);

    


    return 0;
}
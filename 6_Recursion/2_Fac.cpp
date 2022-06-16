#include <bits/stdc++.h>
using namespace std;

int fact(int n){

    if(n==0){
        return 1;
    }

    int x = fact(n-1);
    return x*n;

}

int fact2(int n){
    return n==0?1:fact2(n-1)*n;  // one line code;
}

int main(){

    int n;
    cin>>n;
   cout<<fact2(n);

}
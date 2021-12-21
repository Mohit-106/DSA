#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }

    }

    return true;

}

void  Prime(int n, int m){

    for(int i=n;i<=m;i++){

        if(isprime(i)==true){
            cout<<i<<endl;
        }

    }

    return;
}

int main(){

    int n,m;
    cin>>n>>m;
    Prime(n,m);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void  PrimeFactorisation(int n){

    for(int div=2;div*div<=n;div++){

        while(n%div==0){

            n=n/div;
            cout<<div<<endl;



        }
        
    }

    if(n!=0){
        cout<<n;
    }

    
}


int main(){

    int n;
    cin>>n;
    PrimeFactorisation(n);


    return 0;
}
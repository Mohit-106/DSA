#include <bits/stdc++.h>
using namespace std;


void printInc(int n){

    if(n==0){
        return;
    }
    
    printInc(n-1);
    cout<<n<<endl;

}


void printDec(int n){

    if(n==0){
        return;
    }
    cout<<n<<endl;
    printDec(n-1);
   
}







int main(){

    int n;
    cin>>n;
    printInc(n);
    printDec(n);


    return 0;
}
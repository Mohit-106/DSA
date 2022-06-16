#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    cout<<b<<endl;
    int x = power(a,b-1);
    return a*x;
}

int power2(int a, int b){
    return b==0?1:power2(a,b-1)*a;
}

int powerBtr(int a, int b){

    if(b==0){
        return 1;
    }
    cout<<b<<endl;
    int x = powerBtr(a,b/2);
    if(b%2==0){
        return x*x;
    }
    return x*x*a;
    
}

int main(){

    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    cout<<"_____________"<<endl;
    cout<<powerBtr(a,b);

    return 0;
}
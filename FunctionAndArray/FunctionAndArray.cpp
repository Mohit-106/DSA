#include<bits/stdc++.h> 
using namespace std;

int Q1_DigitFreq(long long  n, long long  d){
    int lastDigit, count=0;
    while(n!=0){
        lastDigit=n%10;
        n=n/10;
        if(d==lastDigit){
            count++;
        }
    }

    return count;



}


int main() {

    long long  n,d;
    cin>>n>>d;

   cout<< Q1_DigitFreq(n,d) <<endl;



return 0;
}
    
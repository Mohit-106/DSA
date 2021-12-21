#include <bits/stdc++.h>
using namespace std;

int Digits(int n){
    int count=0;
    while(n!=0){
        n/=10;
        count++;
    }
    return count;
}

//index:- ex. 8 7 6 5 4 3 2 1 

//right to left
int Inverse(int n)
{
    int lastDigit;
    int ans = 0;
    int p=1;
    int index=1;
    while (n != 0)
    {

        lastDigit = n % 10;
       int  power=lastDigit-1;
        p=pow(10,power);

        ans+=index*p;
        index++;
        n/=10;

        
    }
    return ans;



}

//index:- ex. 1 2 3 4 5 6 7 8 
//left to right
int Inverse2(int n){

    int ans=0;
    int digits =Digits(n);
    int index= digits;

    while(n!=0){
        int rem=n%10;
        n/=10;
        int power=digits-rem;
        ans+=index*pow(10,power);
        index--;

    }
    return ans;



}

int main()
{

    int n;
    cin >> n;
     cout << Inverse(n)<<endl;
    // cout<< Inverse2(n)<<endl;
   
    

    return 0;
}


// use remender to set index at its right position after a dry run.
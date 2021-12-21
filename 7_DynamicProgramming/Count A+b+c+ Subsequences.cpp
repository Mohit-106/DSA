#include <bits/stdc++.h>
using namespace std;

void   CountABC(string s){
    int n= s.size();

    int a=0,b=0,c=0;


    for(int i=0; i<n; i++){

        if(s[i]=='a'){

            a=2*a+1;



        }else if(s[i]=='b'){

            b=2*b+a;

        }else{

            c=2*c+b;

        }
    }

    cout<<c<<endl;



}



int main(){

    string s;
    cin>>s;

    CountABC(s);



    return 0;
}
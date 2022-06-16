#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string str , int s, int e){

    if(s>=e){
        return true;
    }

    if(str[s]==str[e]){
        bool check = isPallindrome(str,s+1,e-1);
        if(check){
            return true;
        }
    }

    return false;


}

int main(){

    string str ;
    cin>>str;

    if(isPallindrome(str,0,str.size()-1)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }




    return 0;
}
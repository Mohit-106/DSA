#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    unordered_map <char,int>m;

    for(int i=0;i<s.size(); i++){

        m[s[i]]++;

    }

    
    char ch;
    int maxval = INT_MIN;
    for(auto & mp : m){

        if(mp.second > maxval){
            maxval=mp.second;
            ch=mp.first;
        }

        

    }

    cout<<ch<<endl;

    



    return 0;
}

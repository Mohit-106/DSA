#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string>set;
    set.insert("abc");
    set.insert("avc");
    set.insert("adc");
    set.insert("abc");
    cout<<set.size()<<endl;

    //hashSet only store unique values

    return 0;
}
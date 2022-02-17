#include <bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<string,int>m;
    m.insert({"india",10});  // O(log(n))

    for(auto &val: m ){
        cout<<val.first<<" "<<val.second<<endl;
    }

    return 0;
}

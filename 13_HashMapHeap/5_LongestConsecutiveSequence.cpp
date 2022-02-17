#include <bits/stdc++.h>
using namespace std;

void lCS(vector<int>&v, unordered_map<int,bool>&m){

    for(int i=0;i<v.size();i++){
        if(m.find(v[i]-1)!=m.end()){

            m[v[i]]=false;

        }
    }
    int fele=0;
    int len=0;
    for(int i=0;i<v.size();i++){
        int cele=v[i];
        int clen=1;
        if(m[v[i]]==true){


            while(m.find(v[i]+clen)!=m.end()){
                   clen++;
            }

            


        }
        if(clen>len){
            len=clen;
            fele=cele;
        }

    }
    for(int i=0;i<len;i++){
        cout<<fele+i<<endl;
    }


}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    
    unordered_map<int, bool> m;

    for (int i = 0; i < n; i++)
    {
       
        cin>>v[i];
        m[v[i]] = true;
    }
    lCS(v,m);

    return 0;
}
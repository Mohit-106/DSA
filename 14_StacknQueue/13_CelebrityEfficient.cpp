#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<string>&v)
{

    int n = v.size();
    int i=0;
    int j=n-1;
    int win=-1;
    while(i<j){

        if(v[i][j]=='0'){
            win=i;
            j--;
        }else{
            win=j;
            i++;
        }
        
        

    }

  
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (win != i)
        {
            if (v[win][i] == '1' || v[i][win] == '0')
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        return win;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans = celebrity(s);
    if (ans != -1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "none" << endl;
    }

    return 0;
}

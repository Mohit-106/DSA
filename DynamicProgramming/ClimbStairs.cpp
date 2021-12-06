#include <bits/stdc++.h>
using namespace std;

int PathsTab(int n){


    vector<int>arr(n+1);
    arr[0]=1;
    

    for(int i=1;i<=n; i++){
        if(i==1){
            arr[i]=arr[i-1];

        }
        else if(i==2){
            arr[i]=arr[i-1]+arr[i-2];

        }
        else{
             arr[i]=arr[i-1]+arr[i-2]+arr[i-3];

        }

       

    }
    return arr[n];

}

int Paths(int n, vector<int> &qb)
{

    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    if (qb[n] != 0)
    {
        return qb[n];
    }

   

    int x = Paths(n - 1, qb);
    int y = Paths(n - 2, qb);
    int z = Paths(n - 3, qb);

    int ans = x + y + z;

    qb[n] = ans;

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> qb(n + 1);
    cout << Paths(n, qb) << endl;

    cout<<PathsTab(n)<<endl;

    return 0;
}
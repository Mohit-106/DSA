#include <bits/stdc++.h>
using namespace std;
int main()
{

    // priority_queue<int> pq;
    // vector<int> v(5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> v[i];
    //     pq.push(v[i]);

    // }

    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }

    // cout<<"---------"<<endl;

    priority_queue<int,vector<int>, greater<int>> spq;
    vector<int> v2(7);
    for (int i = 0; i < v2.size(); i++)
    {
        cin >> v2[i];
        spq.push(v2[i]);

    }

    while(!spq.empty()){
        cout<<spq.top()<<endl;
        spq.pop();
    }



    







    return 0;
}
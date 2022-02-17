#include <bits/stdc++.h>
using namespace std;
void Sort(int k, vector<int> &v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {

        if (i <= k)
        {

            pq.push(v[i]);
        }
        else
        {

            cout << pq.top() << endl;
            pq.pop();
            pq.push(v[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{

    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> k;

    Sort(k, v);

    return 0;
}
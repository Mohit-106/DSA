#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi; //1->data,2->list number,3->index in current list
vector<int> mergeKSortedLists(vector<vector<int>> &lists)
{
    
    vector<int> rv;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < lists.size(); i++)
    {

        pq.push({lists[i][0], {i, 0}});
    }

    while (!pq.empty())
    { //here we are using sapce of o(n)

        ppi curr = pq.top();
        pq.pop();

        int data = curr.first;
        int listno = curr.second.first;
        int idx = curr.second.second;

        rv.push_back(data);
        if (lists[listno].size() > idx + 1)
        {

            pq.push({lists[listno][idx + 1], {listno, idx + 1}});
        }
    }

    return rv;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> lists;
    for (int i = 0; i < k; i++)
    {
        vector<int> list;

        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int data;
            cin >> data;
            list.push_back(data);
        }

        lists.push_back(list);
    }

    vector<int> mlist = mergeKSortedLists(lists);
    for (int val : mlist)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
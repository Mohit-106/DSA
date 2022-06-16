#include <bits/stdc++.h>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> mergeSort(vector<int> &arr, int low , int high){
    if(low==high){
        vector<int>base;
        base.push_back(arr[low]);
        return base;
    }
    int mid = (low+high)/2;
    vector<int>left=mergeSort(arr,low,mid);
    vector<int>right=mergeSort(arr,mid+1,high);
    vector<int>ans = mergeTwoSortedArrays(left,right);
    return ans;

}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    vector<int> ans = mergeSort(A,0,n-1);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}
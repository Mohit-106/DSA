#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{

    if(A.size()==0 || B.size()==0){
        return A.size()==0?B:A;
    }
    int n = A.size();
    int m = B.size();
    int i=0,j=0,k=0;
    vector<int>res(m+n);
    while(i<n && j<m){
        if(A[i]<B[j]){
            res[k++]=A[i++];
        }else{
            res[k++]=B[j++];
        }
    }
    while(i<n){
        res[k++]=A[i++];
    }
    while(j<m){
        res[k++]=B[j++];
    }
    return res;

}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}
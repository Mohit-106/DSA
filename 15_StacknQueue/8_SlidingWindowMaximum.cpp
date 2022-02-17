#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int k;
	cin >> k;
   
    vector<int>nge(n);
    nge[n-1]=n;
    stack<int>st;
    st.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(st.size()>0 && arr[i]> arr[st.top()]){
            st.pop();
        }
        if(st.size()==0){
            nge[i]=n;
        }else{
            nge[i]=st.top();
        }


    }

    vector<int>ans(n-k+1);
    int j=0;
    for(int i=0;i<n-k;i++){
        if(j<i){
            j=i;
        }
        while(nge[j] < i + k){
            j=nge[j];
        }
        ans[i]=arr[j];
    }

    for(int val : ans){
        cout<<val<<endl;
    }






	return 0;
}
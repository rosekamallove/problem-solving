#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void update(int a[], int n, int updates[], int k) {
        for(int i=0; i<k; i++){
            a[updates[i]]++;
        }
        for(int i=2; i<n; i++){
            a[i] += a[i - 1];
        }
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
} 

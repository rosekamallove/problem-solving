class Solution {
public:
   void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int i=m-1;
		int j=n-1;
		int k = m+n-1;
		while(i >=0 && j>=0)
		{
			if(A[i] > B[j])
				A[k--] = A[i--];
			else
				A[k--] = B[j--];
		}
		while(j>=0)
			A[k--] = B[j--];
    }
    
    void naive(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++)
            nums1[m + i] = nums2[i];
        sort(nums1.begin(), nums1.end());
        
        
        cout<<'[';
        for(int i=0; i<n + m; i++){
            if(i == n+m-1){
                cout<<nums1[i];
            } else {
                cout<<nums1[i]<<',';
            }
        }
        cout<<']';
    }
};

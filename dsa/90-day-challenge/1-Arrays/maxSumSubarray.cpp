#include<iostream>
#include<vector>
using namespace std;

bool validate(vector<int> &v) {
    for(int &x: v) {
        if(x > 0) {
            return 1;
        }
    }
    return 0;
}

void solve(vector<int> nums) {
    if(!validate(nums)) {
        cout<<"Invalid Input"<<endl;;
        return;
    }

    int currSum(0), maxSum(0);

    for(int i=0; i<nums.size(); i++) {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }
    cout<<maxSum<<endl;
    return;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v) cin>>x;
    solve(v);
}


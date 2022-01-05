#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int maxMin(int k, vector<int> arr) {
    int result = INT_MAX;
    sort(arr.begin(), arr.end());

    for(int i=0; i<=arr.size() - k; i++)
        result = min(result, arr[i + k - 1] - arr[i]);
    return result;
}

int main() {
}


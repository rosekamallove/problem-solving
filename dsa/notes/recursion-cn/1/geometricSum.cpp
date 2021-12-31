#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

bool geometricSum(int k){
    if(k == 0) return 1;
    double ans = 1 / (double)pow(2, k) + geometricSum(k - 1);
    return ans;
}

int main(){
    int n; cin>>n;
    cout<<fixed<<setprecision(5);
    cout<<geometricSum(n)<<endl;
}


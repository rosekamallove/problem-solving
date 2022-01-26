#include<iostream>
using namespace std;

int countZeroes(int n){
    if(n == 0) return 1;
    if(n / 10 == 0) return 0; 
    if(n % 10 == 0) return 1 + countZeroes(n / 10);
    else return countZeroes(n / 10);
}

int main(){
    int n; cin>>n;
    cout<<countZeroes(n);
}


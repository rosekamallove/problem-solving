#include<iostream>
using namespace std;

int sumOfDigits(int n){
    if(n / 10 == 0) return n%10;
    int sum = n % 10;
    return sum + sumOfDigits(n / 10);
}

int main(){
    int n; cin>>n;
    cout<<sumOfDigits(n)<<endl;
}

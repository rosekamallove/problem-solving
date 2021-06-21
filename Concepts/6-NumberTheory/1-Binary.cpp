#include<iostream>
#include<climits>
using namespace std;

int main(){
    int a = (1LL<<31) - 1;
    cout<<a<<endl;
    cout<<(1LL<<32) - 1<<endl;
    cout<<INT_MAX<<endl;
}


#include<iostream>
#include<climits>
using namespace std;

int main(){
    /*
     * Left Shift:
     * 3 << 2  
     * 11 << 2
     * 1100
     *
     * Right Shift:
     *
     * 3 >> 1
     * 11 >> 1
     * 1
     *
     * 6 >> 1
     * 110 >> 1
     * 11
     */
    cout<<(3<<2)<<endl;
    cout<<(3>>1)<<endl;
    cout<<(6>>1)<<endl;

    // Trick to find the power of two
    int n = 12;
    cout<<(1<<n)<<endl;

    unsigned a = (1LL<<32) - 1;
    signed b = (1LL<<31) - 1;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<INT_MAX<<endl;
}


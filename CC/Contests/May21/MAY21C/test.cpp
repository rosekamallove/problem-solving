#include<iostream>
using namespace std;

int main()
{
    int k; cin>>k;

    int arr[2*k+1];

    int gcd[2*k+1];

    for(int i=1; i<2*k+1; i++)
        arr[i] = i*i + k;

    for(int i=1; i<2*k; i++)
        gcd[i] = __gcd(arr[i], arr[i+1]);
}

#include<iostream>
using namespace std;

void printBinary(int num) {
    for(int i=10; i >= 0; --i) {
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    printBinary(n);
}

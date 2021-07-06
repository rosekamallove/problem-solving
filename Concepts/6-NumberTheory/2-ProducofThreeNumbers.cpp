#include<iostream>
using namespace std;

void solve() {
    int n; cin>>n;
    int a(0),b(0);
    bool isIt(0);
    /*
     * Greedy:
     * a => smallest
     * b => next smallest
     * c => n/(axb)
     */
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            if(a == 0)
                a = i,n /= i;
            else
                b = i, n/=i;
            if(a < b and b < n) {
                isIt = 1;
                break;
            }
        }
    }
    if(isIt) {
        cout<<"YES"<<endl;
        cout<<a<<' '<<b<<' '<<n<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main() {
    int T(1);
    cin>>T;
    while(T--)
        solve();
}


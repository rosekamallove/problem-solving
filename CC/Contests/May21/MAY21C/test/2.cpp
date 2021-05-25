#include "iostream"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n,x,k;
        cin>>n>>x>>k;
        bool isit(0);

        if((x%k==0) or ((n+1-x)%k==0))
            isit = 1;
        
        cout<<(isit ? "YES" : "NO")<<endl;
    }
}

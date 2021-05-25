#include "iostream"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x,a,b;
        cin>>x>>a>>b;
        cout<<(a + (100-x)*b)*10<<endl;
    }
}

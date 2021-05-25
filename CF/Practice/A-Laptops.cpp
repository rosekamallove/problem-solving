#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    bool is(0);

    for(int i=0; i<n; i++)
    {
        int a,b; cin>>a>>b;
        if(a!=b)
            is = 1;
    }

    cout<<(is ? "Happy Alex" : "Poor Alex")<<endl;
}

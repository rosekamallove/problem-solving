#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr1[n];
    int arr2[n];
    int count(0);

    for(int i=0; i<n; i++)
    {
        int a,b; cin>>a>>b;
        arr1[i]=a;
        arr2[i]=b;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j and arr1[i]==arr2[j])
                count++;
    cout<<count<<endl;
}

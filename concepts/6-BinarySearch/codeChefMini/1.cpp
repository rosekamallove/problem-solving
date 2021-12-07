#include<iostream>
using namespace std;

int binarySearch(int n, int arr[], int key)
{
    int i(0), j(n-1);
    while(j-i > 1)
    {
        int mid = (i+j)/2;

        if(arr[mid]==key)
            return mid;

        else if(arr[mid]<key)
            i = mid;

        else if(arr[mid]>key)
            mid = j;
    }
    return -1;
}

void lineEquation()
{
    // find the value of x for which ax + b = y, where a, b, y are given. 
    int a,b,y,x(1);
    cin>>a>>b>>y;

    /*
    while(30--)
    {
        if()
    }
    */
}

int main()
{
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<binarySearch(n,arr,k)<<endl;
}

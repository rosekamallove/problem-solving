#include<iostream>
using namespace std;

int arraySum(int arr[], int n)
{
    int sum(0);
    for(int i=0; i<n; i++)
        sum+=arr[i];
    return sum;
}

int main()
{
    int n(0), time(0); cin>>n;
    int upper[n], lower[n]; 

    for(int i=0; i<n; i++)
    {
        int a,b; cin>>a>>b;
        upper[i] = a;
        lower[i] = b;
    }
    
    if(arraySum(upper,n)%2==0 and arraySum(lower,n)%2 == 0)
        cout<<0<<endl;
    else
        if(n==1 and (arraySum(upper,n)%2!=0 or  arraySum(lower,n)%2!=0))
        {
            time = -1;
            cout<<time<<endl;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(arraySum(upper,n)%2 == 0 and arraySum(lower,n)%2 == 0)
                    break;
                else if(arraySum(upper,n)%2 != 0 or arraySum(lower,n)%2 != 0)
                {
                    swap(upper[i], lower[i]);
                    if(arraySum(upper,n)%2 == 0 and arraySum(lower,n)%2 == 0)
                    {
                        time++;
                        cout<<time<<endl;
                        break;
                    }
                }
            }
            if(arraySum(upper,n)%2 != 0 or arraySum(lower,n)%2 != 0)
            {
                time = -1; 
                cout<<time<<endl;
            }
        }
}

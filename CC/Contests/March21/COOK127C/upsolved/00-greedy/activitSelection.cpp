#include<iostream>
#include<algorithm>
using namespace std;

/*
 * Given n activities with their starting and finish times. Select the
 * maximum nmuber of activities that can be performed by a single person,
 * assuming that a person can only work on a single actitvity at a time
 *
 */

int maxMeeting(int start[], int end[], int n)
{
    sort(end,end+n); 
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int start[n], end[n];

        for(int i(0); i<n; i++) 
            cin>>start[i];

        for(int i(0); i<n; i++) 
            cin>>end[i];

        int ans = maxMeeting(start,end,n);
        cout<<ans<<endl;
    }
}

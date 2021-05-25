#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
     * Queue -> FIFO (First In First Out) 
     *
     * q.push() => adds an element at the end of the queue
     * q.pop()  => removes the first element int the queue
     * q.front() => returns the element at the front of the queue
     */

    queue<string> q;
    q.push("abc");
    q.push("ggh");
    q.push("kdj");
    q.push("asd");
    q.push("dsf");

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}

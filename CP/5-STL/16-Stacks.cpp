#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
     * Stack -> LIFO (Last In First Out);
     * => We can access the size and the top element of the stack generally
     * s.push() => We added an element at the top of the stack
     * s.pop()  => We removed an element at the top of the stack
     * s.top()  => Returns the top element in a stack
     */

    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

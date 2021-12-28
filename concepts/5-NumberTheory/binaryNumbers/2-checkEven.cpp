#include <iostream>
using namespace std;

bool isEven(int n)
{
    if ((n ^ 1) == n + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isEvenAnd(int n)
{
    return (!(n & 1));
}

int main()
{
    int n;
    cin >> n;
    isEven(n)
        ? cout << "Even" << endl
        : cout << "Odd" << endl;
}

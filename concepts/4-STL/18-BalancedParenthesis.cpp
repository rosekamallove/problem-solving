#include <bits/stdc++.h>
using namespace std;

bool isBalaced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            st.push(s[i]);
        else if (st.empty())
            return 0;
        else if (st.top() == '(' and s[i] == ')')
            st.pop();
        else if (st.top() == '{' and s[i] == '}')
            st.pop();
        else if (st.top() == '[' and s[i] == ']')
            st.pop();
    }

    if (st.empty())
        return 1;

    return 0;
}

unordered_map<char, int> symbols = {
    {'[', -1},
    {'{', -2},
    {'(', -3},
    {']', 1},
    {'}', 2},
    {')', 3},
};

string balanced(string s)
{
    stack<char> st;
    for (char brackets : s)
    {
        if (symbols[brackets] < 0)
            st.push(brackets);
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[brackets] != 0)
                return "NO";
        }
    }

    if (st.empty())
        return "YES";
    return "NO";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        // cout<<(isBalaced(s) ? "YES" : "NO")<<endl;
        cout << balanced(s) << endl;
    }
}

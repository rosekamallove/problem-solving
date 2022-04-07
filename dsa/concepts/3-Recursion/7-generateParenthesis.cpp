#include <iostream>
#include <vector>
using namespace std;
/*
 * Given n pairs of parenthesis, write a function to generate all
 * combination of well formed parentheses
 *
 * Input : n=3
 * Output: [
 *          "((()))",
 *          "(()())",
 *          "(())()",
 *          "()(())",
 *          "()()()",
 *         ]
 */

vector<string> valid;

void generate(string &s, int opening, int closing)
{
    if (opening + closing == 0)
    {
        valid.push_back(s);
        return;
    }
    if (opening > 0)
    {
        s.push_back('(');
        generate(s, opening - 1, closing);
        s.pop_back();
    }
    if (closing > 0)
    {
        if (opening < closing)
        {
            s.push_back(')');
            generate(s, opening, closing - 1);
            s.pop_back();
        }
    }
}

int main()
{
    int n, count(0);
    cin >> n;
    string s;
    generate(s, n, n);

    cout << '[' << endl;
    for (auto &k : valid)
    {
        cout << ' ' << k << ',' << endl;
        count++;
    }
    cout << ']' << endl;
    cout << count << endl;
}

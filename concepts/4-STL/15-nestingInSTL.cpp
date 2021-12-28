#include <bits/stdc++.h>
using namespace std;

void basic()
{
    map<pair<int, int>, int> m; // map's key is now a pair.
    pair<int, int> p1({1, 2}), p2({2, 3});

    cout << (p2 < p2) << endl;

    map<set<int>, int> m2;
    set<int> s1({1, 2, 3}), s2({2, 3});

    cout << (s1 < s2);
}

void monkAndClassMarks();

void part2()
{
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        string fn, ln;
        cin >> fn >> ln >> cnt;
        for (int j = 0; i < cnt; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }
    for (auto &pr : m)
    {
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout << full_name.first << " " << full_name.second << " --- " << list.size() << endl;
        for (auto &element : list)
            cout << element << " ";
        cout << endl;
    }
}

int main()
{
    monkAndClassMarks();
}

void monkAndClassMarks()
{
    int n;
    cin >> n;
    map<int, multiset<string>> m;

    for (int i = 0; i < n; i++)
    {
        string name;
        int marks;
        cin >> name >> marks;
        m[marks].insert(name);
    }
    auto curr = --m.end();

    while (1)
    {
        auto &students = (*curr).second;
        int marks = (*curr).first;
        for (auto student : students)
            cout << student << " " << marks << endl;

        if (curr == m.begin())
            break;
        curr--;
    }
}

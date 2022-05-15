#include<bits/stdc++.h>
using namespace std;

bool space(char c) { return isspace(c); }
bool not_space(char c) { return !isspace(c); }

vector<string> split(const string& str) {
  vector<string> ret;
  string::const_iterator i = str.begin();

  while (i != str.end()) {
    i = find_if(i, str.end(), not_space);
    string::const_iterator j = find_if(i, str.end(), space);
    if (i != str.end())
      ret.push_back(string(i, j));
    i = j;
  }
  return ret;
}

string getPhone(string s) {
    string ans = "";

    map<string, char> mp = {
        {"one" ,   '1'},
        {"two" ,   '2'},
        {"three" , '3'},
        {"four" ,  '4'},
        {"five" ,  '5'},
        {"six" ,   '6'},
        {"seven" , '7'},
        {"eight" , '8'},
        {"nine" ,  '9'},
    };

    vector<string> v = split(s);

    for(int i=0; i<v.size(); i++) {
        if(v[i] == "double") {
            ans += mp[v[i + 1]];
            ans += mp[v[i + 1]];
            i++;
        } else  if(v[i] == "triple") {
            ans += mp[v[i + 1]];
            ans += mp[v[i + 1]];
            ans += mp[v[i + 1]];
            i++;
        } else {
            ans += mp[v[i + 1]];
        }
    }

    return ans;
}

int main(){
    string s;
    getline(cin, s);

    string ans = getPhone(s);
    cout<<ans<<endl;
}


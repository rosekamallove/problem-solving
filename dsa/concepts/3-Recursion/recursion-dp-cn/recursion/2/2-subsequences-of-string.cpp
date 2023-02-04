#include <iostream>
using namespace std;

int getAllSubsequence(string s, string o[]) {
  if (s.empty()) {
    o[0] = "";
    return 1;
  }

  string str = s.substr(1);
  int subSequenceSize = getAllSubsequence(str, o);

  for (int i = 0; i < subSequenceSize; i++) {
    o[i + subSequenceSize] = s[0] + o[i];
  }
  return 2 * subSequenceSize;
}

int main() {
  string inp;
  cin >> inp;
  string *output = new string[1000];
  int count = getAllSubsequence(inp, output);
  for (int i = 0; i < count; i++) {
    cout << output[i] << endl;
  }
}

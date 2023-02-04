#include <iostream>
using namespace std;

void print_subs(string input, string output = "") {
  if (input.empty()) {
    cout << output << endl;
    return;
  }

  print_subs(input.substr(1), output);
  print_subs(input.substr(1), output + input[0]);
}

int main() {
  string s;
  cin >> s;
  print_subs(s);
}

#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string output = "") {
  if (num == 0) {
    cout << output << endl;
    return;
  }
  string input;
  int n = num % 10;
  switch (n) {
  case 2:
    input = "abc";
    break;
  case 3:
    input = "def";
    break;
  case 4:
    input = "ghi";
    break;
  case 5:
    input = "jkl";
    break;
  case 6:
    input = "mno";
    break;
  case 7:
    input = "pqrs";
    break;
  case 8:
    input = "tuv";
    break;
  case 9:
    input = "wxyz";
    break;
  }

  for (int i = 0; i < input.size(); i++) {
    printKeypad(num / 10, input[i] + output);
  }
}

int main() {
  int num;
  cin >> num;
  printKeypad(num);
}

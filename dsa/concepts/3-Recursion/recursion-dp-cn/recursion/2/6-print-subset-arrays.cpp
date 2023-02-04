#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
  // Write your code here
  if (n == 0) {
    output[0][0] = 0;
    return 1;
  }

  int subSeqSize = subset(input + 1, n - 1, output);

  for (int i = 0; i < subSeqSize; i++) {
  G:
    w

        output[i + subSeqSize][j] = input[0] + output[i][j];
  }
}

int main() {
  int input[20], length, output[35000][20];
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for (int i = 0; i < size; i++) {
    for (int j = 1; j <= output[i][0]; j++) {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

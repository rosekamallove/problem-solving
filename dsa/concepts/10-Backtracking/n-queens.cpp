#include <iostream>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int column) {
  // same column
  for (int i = row - 1; i >= 0; i--) {
    if (board[i][column] == 1)
      return false;
  }

  // upper left diagnol
  for (int i = row - 1, j = column - 1; i >= 0 and j >= 0; i--, j--) {
    if (board[i][j] == 1)
      return false;
  }

  // upper right diagnol
  for (int i = row - 1, j = column + 1; i >= 0 and j < n; i--, j++) {
    if (board[i][j] == 1)
      return false;
  }
  return true;
}

void nQueenHelper(int n, int row) {
  if (row == n) {
    // we have reached some solution
    // print the board matrix
    // return
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << ' ';
      }
    }
    cout << endl;
    return;
  }

  // place at all possible positions and move on to smaller problems
  for (int j = 0; j < n; j++) {
    if (isPossible(n, row, j)) {
      board[row][j] = 1;
      nQueenHelper(n, row + 1);
      board[row][j] = 0;
    }
  }
  return;
}

void NQueens(int n) {
  memset(board, 0, 11 * 11 * sizeof(int));
  nQueenHelper(n, 0);
}

int main() {
  int n;
  cin >> n;
  NQueens(n);
}

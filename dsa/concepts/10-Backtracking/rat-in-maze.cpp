#include <iostream>
using namespace std;

void printSolution(int **solution, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << solution[i][j] << ' ';
    }
  }
  cout << endl;
}

void mazeHelp(int maze[][20], int n, int **solution, int x, int y) {

  if (x == n - 1 and y == n - 1) {
    solution[x][y] = 1;
    printSolution(solution, n);
    return;
  }

  solution[x][y] = 1;

  if (x >= n or x < 0 or y >= n or y < 0 or maze[x][y] == 0 or
      solution[x][y] == 1) {
    return;
  }

  mazeHelp(maze, n, solution, x - 1, y);
  mazeHelp(maze, n, solution, x + 1, y);
  mazeHelp(maze, n, solution, x, y - 1);
  mazeHelp(maze, n, solution, x, y + 1);
  solution[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n) {
  int **solution = new int *[n];
  for (int i = 0; i < n; i++) {
    solution[i] = new int[n];
  }

  mazeHelp(maze, n, solution, 0, 0);
}

int main() {
  int maze[20][20];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
    }
  }
}

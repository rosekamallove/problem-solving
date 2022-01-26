#include <iostream>
using namespace std;

#include <string.h>
void insertPi(char input[], int idx) {
    for (int i = strlen(input); i >= idx + 2; i--) {
        input[i + 2] = input[i];
    }
    input[idx] = '3';
    input[idx + 1] = '.';
    input[idx + 2] = '1';
    input[idx + 3] = '4';
}

void solve(char input[], int start) {
    if (input[start] == '\0' || input[start + 1] == '\0') {
        return;
    }

    solve(input, start + 1);

    if (input[start] == 'p' && input[start + 1] == 'i')
        insertPi(input, start);
}

void replacePi(char input[]) {
    solve(input, 0);
}


int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

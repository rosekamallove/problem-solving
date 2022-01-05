#include<iostream>
using namespace std;

#include<string.h>
int solve(char input[], int len) {
    if(len == 0) return input[len] - '0';
    int smallAns = solve(input, len - 1);
    int a = input[len] - '0';
    return smallAns * 10 + a;
}

int stringToNumber(char input[]) {
    int len = strlen(input);
    return solve(input, len - 1);
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}


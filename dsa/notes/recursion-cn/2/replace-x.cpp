#include<iostream>
using namespace std;

#include<string.h>
void solve(char input[], int start) {
    if(input[start] == '\0') return;
    solve(input, start + 1);

    if(input[start] == 'x'){
        int len = strlen(input);
        int i; 
        for(i = start + 1; i < len; i++){
            input[i - 1] = input[i];
        }
        input[i - 1] = '\0';
    }
}

void removeX(char input[]) {
    solve(input, 0);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}


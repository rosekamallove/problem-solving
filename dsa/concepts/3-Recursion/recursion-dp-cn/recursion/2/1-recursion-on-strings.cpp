#include<iostream>
using namespace std;

void removeX(char s[]) {
    if(s[0] == '\0') return;
    if(s[0] != 'x') {
        removeX(s + 1);
    } else {
        int i;
        for(i = 1; s[i] != '\0'; i++) {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeX(s);
    }
}

void replaceCharacter(char input[], char c1, char c2) {
    if(input[0] == '\0') return;
}

int length(char s[]) {
    if(s[0] == '\0') return 0;
    return 1 + length(s + 1);
}

int main(){
    char str[100];
    cin>>str;

    removeX(str);

    cout<<str<<endl;
}


#include<iostream>
using namespace std;

int strLen(char str[]) {
    int i = 0;
    while(str[i]) {
        i++;
    }
    return i;
}

bool solve(char input[], int start, int end) {
    if(start >= end) return 1;
    if(input[start] == input[end])
        return solve(input, start + 1, end - 1);
    else return 0;
}

bool checkPalindrome(char input[]) {
    int start(0), end(strLen(input) - 1);
    return solve(input, start, end);
}




int main() {
    int n;
    cin>>n;
    char input[n];
    cin>>input;

    cout<<(checkPalindrome(input)
           ? "Palindrome"
           : "Not Palindrome")<<endl;
}

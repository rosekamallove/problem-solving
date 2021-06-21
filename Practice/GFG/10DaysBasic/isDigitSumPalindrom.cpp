#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        int sum(0);
        while(N > 0){
            sum += N % 10;
            N /= 10;
        }
        int rev(0), num(sum);
        while(num > 0){
            int temp = num % 10;
            rev = (rev*10) + temp;
            num /= 10;
        }
        return sum == rev;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

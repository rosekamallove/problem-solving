/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(unsigned int n) {
         unsigned int lo(1), hi(n + 1), ans(0);
        
        while(lo < hi){
            int mid = lo + (hi - lo) /2;
            if(guess(mid) == 0){
                ans = mid;
                break;
            } else if(guess(mid) == -1){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

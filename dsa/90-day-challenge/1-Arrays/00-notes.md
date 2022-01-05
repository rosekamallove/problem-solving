**Minimize the Maximum Difference** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/angry-children)

- Minimising the difference between `max` and `min` element in an subarray of size `k`
- We would need to have the elements as close to each other as possible
- Hence, Sort
- Now, slide a window of length `k` and get the min.

**Left Rotation** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/array-left-rotation) |
[LeeCode](https://leetcode.com/problems/rotate-array/)

- Left Rotation is nothing but Right Rotation `r = n - l`
- p1 + p2 => (Breaking the array into two parts)
- p1^ + p2^ => (Reversing Individually)
- p2^^ + p1^^ => (Reversing Whole)
- p2 + p1 => (What we wanted)

**Rearrange the array for alternate +ve and -ve** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/rearrange-the-array-5)

- Bruteforce would be to use two arrays `+ve` and `-ve` to store the respective and then alternatively insert these
  elements in the original array. Basically merging two sorted array
- With O(1) extra space:
  - **Two Pointers (order not preserved):**
    - `i = 0` and `j = n - 1` => If you find that on `ith` pointer there is a `-ve` and on the `jth` there is `+ve`
      swap them. And, `i++, j--`.
    - Now the array has `+ve` on one side and `-ve` on the other side.
    - Swap again to make them alternative
  - **Approach 2 (order Preserved):**
    - Correct index for the element: `even for -ve` and `odd for +ve`.
    - wrong index ? right-shift : iterate
    - We shift because we need to preserve the order.

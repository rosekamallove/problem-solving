**1. Minimize the Maximum Difference** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/angry-children)

- Minimising the difference between `max` and `min` element in an subarray of size `k`
- We would need to have the elements as close to each other as possible
- Hence, Sort
- Now, slide a window of length `k` and get the min.

**2. Left Rotation** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/array-left-rotation) |
[LeeCode](https://leetcode.com/problems/rotate-array/)

- Left Rotation is nothing but Right Rotation `r = n - l`
- p1 + p2 => (Breaking the array into two parts)
- p1^ + p2^ => (Reversing Individually)
- p2^^ + p1^^ => (Reversing Whole)
- p2 + p1 => (What we wanted)

**3. Rearrange the array for alternate +ve and -ve** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/rearrange-the-array-5)

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

**4. Permuting Two Array:** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/two-arrays)

- Basically sort one array in Reverse order and one in normal order and the iterate to get the solution

**5. Sort 0 1 2** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/sort-01-2-array/submissions/code/1340437869) | [LeetCode](https://leetcode.com/problems/sort-colors/)

- We can do a count sort: count no. of 0s 1s and 2s and then update then insert 0s in the beginning then 1s and then 2s...
- Or with O(1) space we can do the following:
  - Three pointers: lo(0), mid(0), hi(n - 1)
  - [0, low - 1] all 0s
  - [high +1, n] all 2s

**Kth Largest and Smallest**[HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/kth-largestsmallest-number-3) | [LeetCode](https://leetcode.com/problems/kth-largest-element-in-an-array/)

- Either `sort` the array or use `priority-queue`

**Union of two Array** [HackerRank](https://www.hackerrank.com/contests/90-days-of-coding/challenges/union-of-2-arrays/submissions/code/1340469184)

- Simply iterate and check which one is smaller and push it to the the answer array, and if both are equal then add
  either one of them to the array.
- After this iteration completes since it will end at the smaller array.
- Push the remaining elements to the array.
- **Now to check for duplicates, also check the adjacent elements**

**Intersection of two arrays**

- Very simple, if both the elements are equal only then push to the array.

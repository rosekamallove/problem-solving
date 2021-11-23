### Problem Solving

<details>
<summary> How to build an intuition for Problem Solving</summary>

- **Step 1: Self Assesment**
- **Step 2: Review Data Structures & Algorithms**
- **Step 3: Create a consistent system to track progress**
  - Todo: New problems that you have not yet worked on
  - Repeat: Problems that you have worked on but are still making some mistakes on
  - Done: Problems that you have nailed and are confident about.
  - Time yourself.
  - Do 5 questions back to back (improve endurance)
  - Score Yourself
    - Did you need hints?
    - Did you finish within 30 minutes
    - Was the solution optimal
    - Were there any bugs?
  - Select Problems
- **Step 4: Practice using spaced repetition**
- **Step 5: Recognize common problem-solving patterns**
- **Step 6: Evaluation of readiness**
- **Step 7: Metacognition**

---

1. **<ins>Problem 1</ins>:**(Easy)

   **<ins>Problem Statement</ins>**:

   Given an array of integers `nums` and an integer `target`, return indices of the two numbers such
   that they add up to the `target`.

   You may assume that each input would have **exactly one solution**, and you may not use the same element twice .

   You can return the answer in any order.

   **Example 1:**
   <pre>
    <b>Input</b>: nums = [3,2,4], target = 6
    <b>Output</b>: [1,2]
   </pre>

   **Example 2:**
   <pre>
    <b>Input</b>: nums = [2,7,11,15], target = 9
    <b>Output</b>: [0,1]
   </pre>

   **Example 3:**
   <pre>
    <b>Input</b>: nums = [3,3], target = 6
    <b>Output</b>: [0,1]
   </pre>

   **<ins>Approach</ins>:**

   - First we try to brute force the solution and compare all the values.
     - O(n^2)
   - **`Techineque 1`** use your knowledge of various time complexities.
     - What's better than O(n^2)
       - ~~O(nlogn)~~ : Sort?
       - O(n) : This is what we're left of now.
       - ~~O(logn)~~ : Not sorted at all, no binary search :(
       - ~~O(1)~~: We just can't do it in constant time, because we HAVE to search
   - O(n) it is but how?
     - Maybe I can use some extra space?
     - There is an outer loop doing `n` and then an inner loop doing `n`. What if I replace the inner loop by constant
       time? **HashMaps** comes to mind.
     - At `0` from the array `[0,5,6,8,2,7]` have we seen a `9` yet in the array? No. I'll add `0` to the hashmap so
       that in the future if I get a `9` I know `0` was there.
     - We'll iterate like this and `voilla` Solved.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        vector<int> ret;
        int i;
        for (i=0; i<numbers.size(); i++) {
            if (map.find(numbers[i])==map.end())
                map[target-numbers[i]] = i;
            else {
                ret.push_back(map[numbers[i]]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
}
```

---

2. **<ins>Problem 2</ins>:**(Medium)

   **<ins>Problem Statement</ins>**:

   Given a string `s`, return the _longest palindromic substring_ in `s`

   **Example 1:**
   <pre>
    <b>Input</b>: s = 'babad'
    <b>Output</b>: 'bab'
    <b>Note:</b> 'aba' is also a valid answer
   </pre>

   **Example 2:**
   <pre>
    <b>Input</b>: s = 'cbbd'
    <b>Output</b>: 'bb'
   </pre>

   **Example 3:**
   <pre>
    <b>Input</b>: s = 'a'
    <b>Output</b>: 'a'
   </pre>

   **<ins>Approach</ins>:**

```cpp
class Solution {
public:
}
```

</details>

<details><summary>Array & Strings</summary>
- Basics Of Two Dimensional Arrays

- How are they stored?

- Traversal based Problems

  - Wave Form - https://www.codingninjas.com/codestudio/problems/return-in-row-wave-form_893285
  - Spiral Form - https://www.codingninjas.com/codestudio/problems/spiral-matrix_840698

- Basics Of Strings
  - How strings are stored?
  - Basic Questions
    - Reverse String
    - Check String Is Palindrome Or Not?
    - Remove Vowels
    - Link - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381763
- Sorting Algorithms
  - Selection Sort
  - Bubble Sort
  - Insertion Sort
  - Link - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382158
- Time And Space Complexity
- Algorithms Learn
  - Binary Search
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377974
  - Dutch National Flag Algorithm
    - Sort 0 1
    - Sort 0 1 2
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381861
  - Two Pointers Technique
    - Pair sum
    - Triplet Sum
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376553
  - Sliding Window Algorithm
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376573
  - Kadane's Algorithm
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381861
- Applications On Arrays
  - Overalapping Intervals
  - Second Largest Element In Array
  - Minimum Number Of Platforms
  - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381883
- Applications On Multi Dimensional Arrays
  - Search In Row Wise And Column Wise Sorted Matrix
    - Binary Search
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280160
  - Inplace Rotate Matrix By 90 degree
    - Adhoc Problem
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280165
  - Matrix Median
    - Binary Search
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280164
  - Other Questions Practice Link
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1281375
- Applications On Strings

  - Longest Substring Without Repeating Characters
    - Sliding Window
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111306/offering/1280180
  - Anagram Difference
    - Hashmap
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111306/offering/1280171
  - Shortest substring with all characters
    - Two Pointers
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111306/offering/1280173
  - Minimum operations to make strings equal
    - Hashmap
    - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111306/offering/1280177
  - Other Questions Practice Link - https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111306/offering/1376442
  </details>

<details><summary>Linked List</summary>
<b>PreRequisites</b>

- Arrays
- Recursion
- Time And Space Complexity
- Full Practice Link

  - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1382019

- Basic Operations On Linked List
  - Taking Input
  - Insert Element In Linked List
    - Iteratively
    - Recursively
  - Search Element In Linked List
    - Iteratively
    - Recursively
  - Delete Element In Linked List
    - Iteratively
    - Recursively
- Reverse Operations On Linked List
  - Reverse Linked List
    - Iteratively
    - Recursively
  - K-Reverse Linked List
    - Iteratively
    - Recursively
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381239
  - Add Two Linked Lists
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381244
  - Rearrange Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381253
- Standard Questions And Applications on Linked List
  - Slow And Fast Pointer
    - Delete Middle Node
      - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381207
    - Detect And Remove Loop
      - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381210
  - Merge Two Sorted Linked Lists
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381196
  - Merge Sort On Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1382021
  - Intersection Of Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381194
- More Applications Of Linked List
  - Count Inversion
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381232
  - Pair Swap
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381201
  - Add One To Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381204
  - Check Linked List Palindrome
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381193
- Other Types Of Linked List
  - Doubly Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118796/offering/1382155
  - Circular Linked List
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118796/offering/1382153
- Move On
- Stacks And Queues
- Linked List Implementation
- Trees
- Covert BST Into Sorted LL
</details>

<details><summary>
Stack and Queues
</summary>
- Implementation Of Stacks

- Using Array
- Using Linked List
  - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380936
- Implementation Of Queues

  - Using Array
  - Using Linked List

- Implementation Important Questions

  - Min Stack
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380937
  - Stack Using 2 Queues
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380940
  - Queue Using 2 Stacks
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380939
  - Two Stacks
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380938
  - Implement A Deque
    - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118796/offering/1381380

- Reverse Questions

  - Reverse A Queue https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380946

  - Revese A Stack Using Another Stack

  - Reverse First K Elements Of Queue https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380947

- Popular Applications

  - LRU Cache Implementation https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380941

  - Evaluation Of Postfix Experession https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380942

  - Next Greater Element https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380943

  - Valid Paranthesis https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380944

- Popular Interview Questions Sort A Stack - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380948 - Delete Middle Element From Stack - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380949 - Execution Time - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380951 - Find the nearest supporter - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380952 - Maximum of minimum for every window size - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380950 -
</details>

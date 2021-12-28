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

---

#### Topicwise Distribution

- [Arrays & Strings](https://dynalist.io/d/1MuHCTPPPSrIE6LFFym5tDrZ)
- [LinkedList](https://dynalist.io/d/tzlOTQkE5JtVQvpwh700LrNa)
- [Stack & Queues](https://dynalist.io/d/9Tf8SNBu1dAyFbflHwQhWItv)
- [Recursion and Bactracking](https://dynalist.io/d/AVjaz4rzNdrEAgLtmSb8cVQU)
- [Trees](https://dynalist.io/d/1WyU_QpKVlj5tWsG49Dg5srP)
- [Dynamic Programming](https://dynalist.io/d/oUozFv4iwdWiiEOIxeILGKMh)
- [Graphs](https://dynalist.io/d/1fW-Gy0LfCRR1izyy35YBHjl)

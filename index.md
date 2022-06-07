# DSA Notes

<details>
    <summary>
    <h3>Hashing</h3>
    </summary>

-   Two Sum
    [https://leetcode.com/problems/two-sum/](https://leetcode.com/problems/two-sum/)

    -   **Naive**
        -   Just generate all the pairs and return the pairs that add up to the target
        -   Complexity: O(n^2) time and O(1) space
    -   **Optimised**
        -   If we find the **diff =** `target - v[i]` then we only have to find this **diff** in the array
        -   We can create an unordered_set in which we’ll find the diff, and if we don’t find the diff we’ll insert **v[i]**
        -   Alternatively we can use a unordered_map in which we’ll insert the **diff** along with it’s index if not find, else if we find it then
        -   Complexity O(n) time and O(n) space
    -   **Code**

        ```cpp
        vector<int> unorderedSetSolution(vector<int>& nums, int target) {
                vector<int> ans(2);
                unordered_set<int> st;
                for(int i=0; i<nums.size(); i++){
                    int diff = abs(target - nums[i]);
                    if(st.find(diff) == st.end()){
                        st.insert(nums[i]);
                    } else {
                        ans[0] = *st.find(diff);
                        ans[1] = i;
                    }
                }
                for(int i=0; i<nums.size(); i++){
                    if(nums[i] == ans[0]){
                        if(ans[1] != i){
                            ans[0] = i;
                        }
                    }
                }
                return ans;
            }

        vector<int> twoSum(vector<int>& numbers, int target) {
                unordered_map<int, int> map;
                vector<int> ret;
                int i;
                for(i=0; i<numbers.size(); i++){
                    if(map.find(numbers[i])==map.end())
                        map[target-numbers[i]] = i;
                    else{
                        ret.push_back(map[numbers[i]]);
                        ret.push_back(i);
                        break;
                    }
                }
                return ret;
            }
        ```

-   Four Sum
    [https://leetcode.com/problems/4sum/](https://leetcode.com/problems/4sum/)

    -   **Naive**

        -   Sort ⇒ Three Pointers + Binary Search
        -   Three pointers being three nested loops k = j + 1, j = i + 1.
        -   Then store all the generated pairs in an Hash-Set (to remove duplicates)
        -   Get the sum of the values of these three pointers, now since the array is sorted we can binary search over this **diff = target - sum**
        -   O(1) space and O(N^3logN) + O(NlogN) time
        -   **Code**

            ```cpp
            class Solution {
            public:
                vector<vector<int>> fourSum(vector<int>& nums, int target) {

                    set<vector<int>> ans;

                    sort(nums.begin(), nums.end());

                    for(int i=0; i<nums.size(); i++) {
                        for(int j = i + 1; j<nums.size(); j++) {
                            for(int k = j + 1; k<nums.size(); k++) {
                                long long int sum = nums[i] + nums[j];
                                sum += nums[k];
                                long long diff = target - sum;

                                if(binary_search(nums.begin() + k + 1, nums.end(), diff)) {
                                    auto itr = lower_bound(nums.begin() + k + 1, nums.end(), diff) ;
                                    int idx = distance(nums.begin(), itr);

                                    if(nums[i] + nums[j] + nums[k] + nums[idx] == target) {
                                        vector<int> temp;
                                        temp.push_back(nums[i]);
                                        temp.push_back(nums[j]);
                                        temp.push_back(nums[k]);
                                        temp.push_back(nums[idx]);

                                        ans.insert(temp);
                                    }
                                }
                            }
                        }
                    }

                    vector<vector<int>> v(ans.begin(), ans.end());

                    return v;
                }
            };
            ```

    -   **Optimised**

        -   Remove the _Hash Set_
        -   We’ll sort the array and use two loops, and two pointers
        -   i and j will give us the two elements ⇒ v[i] + v[j] = **sum**
        -   now, **target - sum = diff** is what we need to find out, so let’s put two pointers _left(j +1)_ and _right(n - 1)_ and since the array is sorted:
            -   if v[left] + v[right] > sum ⇒ right—
            -   if v[left] + v[right] < sum ⇒ left++
            -   if v[left] + v[right] == sum ⇒ return ans.
        -   One thing to keep in mind is: **jump over the duplicates**
        -   Same thing with i and j ⇒ jump over the duplicates
        -   Code

            ```cpp
            class Solution {
            public:
                vector<vector<int>> fourSum(vector<int>& nums, int target) {
                    vector<vector<int>> ans;
                    if(nums.empty()) return ans;

                    int n = nums.size();
                    sort(nums.begin(), nums.end());

                    for(int i=0; i<n; i++) {
                        for(int j=i+1; j<n; j++) {
                            int l(j + 1), r(n - 1);

                            int diff = target - nums[j] - nums[i];

                            while(l < r) {
                                if(nums[l] + nums[r] < diff) l++;
                                else if(nums[l] + nums[r] > diff) r--;
                                else {
                                    vector<int> res(4, 0);

                                    res[0] = nums[i]; res[1] = nums[j];
                                    res[2] = nums[l]; res[3] = nums[r];

                                    ans.push_back(res);

                                    //Processing Duplicates
                                    while(l < r and res[2] == nums[l]) ++l;
                                    while(l < r and res[3] == nums[r]) --r;
                                }

                            }

                            while(j + 1 < n and nums[j] == nums[j + 1]) ++j;
                        }
                       while(i + 1 < n and nums[i] == nums[i + 1]) ++i;
                    }
                    return ans;
                }
            };
            ```

-   Longest Consecutive Sequence

    -   **Naive**

        -   We can sort the array
        -   Linearly iterate, then take the length of the max consecutive sequence
        -   Complexity: O(NlogN) + O(N) space for Sorting
        -   Code

            ```cpp
            class Solution {
            public:
                int longestConsecutive(vector<int>& nums) {
                    sort(nums.begin(), nums.end());

                    int globalMax(1), localMax(1);

                    for(int i=1; i<nums.size(); i++) {
                        if(nums[i] != nums[i - 1]) {
                            if(nums[i] == nums[i - 1] + 1) {
                                localMax++;
                            }
                            else {
                                globalMax = max(localMax, globalMax);
                                localMax = 1;
                            }
                        }
                    }
                    return max(globalMax, localMax);
                }
            };
            ```

    -   **Optimised**

        -   Create a hash-set and insert all elements into it.
        -   If v[i] - 1 is not present in the set then we’ll check for v[i] + 1 , then for v[i] + 2 until we reach to a point where the number doesn’t exit. And update out globalMax accordingly.
        -   Complexity: O(3 n) time and O(n) space
        -   Code

            ```cpp
            class Solution {
            public:
                int longestConsecutive(vector<int>& nums) {
            				if(num.empty()) return 0;
                    unordered_set<int> st;
                    int globalMax(1);

                    for(int &x : nums) {
                        st.insert(x);
                    }

                    for(int &x : nums) {
                        if(st.find(x - 1) == st.end()) {
                            int curr = x;
                            int localMax = 1;

                            while(st.find(curr + 1) != st.end()) {
                                localMax++;
                                curr++;
                            }
                            globalMax = max(localMax, globalMax);
                        }
                    }
                    return globalMax;
                }
            };
            ```

-   Largest Subarray with 0 Sum
    [https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/)

    -   Naive
        -   Generate all the sub-arrays
        -   Check which has zero sum and update the maxLen variable
        -   O(n^3) for generating sub-array or maybe O(n^2) if optimised
    -   Optimal

        -   Create a Hash Map which’ll store the prefix sum along with the index
        -   if the current sum already exist in the hash map that means that the current subarray has the sum zero since ⇒ s + x = s then x = 0
        -   if the sum is zero then the current subarray also has a sum of zero so we’ll update the global maxLen
        -   Code

            ```cpp
            class Solution{
                public:
                int maxLen(vector<int>&A, int n)
                {
                    unordered_map<int, int> mp;

                    int mxLen(0), sum(0);

                    for(int i=0; i<n; i++) {
                        sum += A[i];

                        if(sum == 0) mxLen = i + 1;

                        if(mp.find(sum) == mp.end()) {
                            mp.insert(make_pair(sum, i));
                        } else {
                            mxLen = max(mxLen, i - mp[sum]);
                        }
                    }
                    return mxLen;
                }
            };
            ```

-   Longest Subarray with the Given XOR
    [https://leetcode.com/problems/xor-queries-of-a-subarray/](https://leetcode.com/problems/xor-queries-of-a-subarray/)

    -   Code

        ````cpp
        class Solution {
        public:
        vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n, 0);

                    for(int i=0; i<n; i++) {
                        if(i == 0) {
                            prefixXor[i] = arr[i];
                        } else {
                            prefixXor[i] = arr[i] ^ prefixXor[i - 1];
                        }
                    }

                    vector<int> ans;

                    for(vector<int> x : queries) {

                        if(x[0] == 0) {
                            ans.push_back(prefixXor[x[1]]);
                            continue;
                        }

                        ans.push_back(prefixXor[x[0] - 1] ^ prefixXor[x[1]]);
                    }

                    return ans;
                }
            };
            ```

        [https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1](https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1)

        ````

    -   Naive
        -   Just create all the subarray and find the xor of each and update the counter
        -   O(n^3) for generating subarray (naive) and O(n^2) for optimised Subarray generation
    -   Optimised

        -   Create a Prefix Xor hashmap which stores the frequency of the xor too
        -   Then check if currXor == targetXor and update the counter
        -   And if currXor already exist in the HashMap then also update the counter with the frequency of that Xor
        -   Code

            ```cpp
            #include<map>

            int subarraysXor(vector<int> &arr, int x)
            {
            	map<int, int> prefixXor;
            	int prev(0), cnt(0);

            	for(int y : arr) {
            		prev = prev^y;

            		if(prev == x) cnt++;

            		if(prefixXor.find(prev ^ x) != prefixXor.end())
            			cnt += prefixXor[prev ^ x];

            		prefixXor[prev]++;
            	}
            	return cnt;
            }
            ```

-   Longest Substring Without repeating Characters
    [https://leetcode.com/problems/longest-substring-without-repeating-characters/](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

        -   Naive
            -   Generate all the substrings and find the longest substring without repeating characters and voila we have the answer
            -   O(n^3) or O(n^2)
        -   Optimised

            -   We’re gonna have two pointers l and r initialised both to zero
            -   Then we’re gonna check if s[r] is present int the hasSet or not
            -   if it is not present, it means that it is not repeating so we’ll update the maxLen with r - l + 1
            -   But if it is present, then we’ll increment l and remove s[l] from the set until s[r] is not present int the set. And then when it is not present in the set, we can update the maxLen again with r - l + 1
            -   Complexity: O(2N) time and O(N) Space
            -   Code

                ```cpp
                class Solution {
                public:
                    int lengthOfLongestSubstring(string s) {
                        set<char> st;

                        int l(0), r(0), maxLen(0);

                        while(l < s.size() and r < s.size()) {
                            if(st.find(s[r]) == st.end()) {
                                maxLen = max(r - l + 1, maxLen);
                                st.insert(s[r++]);
                            } else {
                                while(st.find(s[r]) != st.end()) {
                                    st.erase(s[l++]);
                                }
                                maxLen = max(r - l + 1, maxLen);
                                st.insert(s[r++]);
                            }
                        }
                        return maxLen;
                    }
                };
                ```

        -   Best

            -   We can optimise out approach more by removing the left pointer increment
            -   It would be nice if we can make a jump directly, without going through each character instead jump to the one which is non-repeating
            -   We can do this by storing the index too.
            -   Code

                ```cpp
                class Solution {
                public:
                    int lengthOfLongestSubstring(string s) {
                        map<char, int> mp;

                        int l(0), r(0), maxLen(0);

                        while(r < s.size()) {
                            if(mp.find(s[r])  != mp.end())
                                l = max(mp[s[r]] + 1, l);

                            mp[s[r]] = r;
                            maxLen = max(r - l + 1, maxLen);
                            r++;
                        }
                        return maxLen;
                    }
                };
                ```

    </details>

<details>
    <summary>
    <h3>Linked List</h3>
    </summary>

-   Reverse a Linked List
    [https://leetcode.com/problems/reverse-linked-list/submissions/](https://leetcode.com/problems/reverse-linked-list/submissions/)

    -   Iterative Approach
        -   We’ll store the next of head in next
        -   then, head → next is to be pointed at a newNode which points to null
        -   then make the next node the new head
        -   Code
            ```cpp
            class Solution {
            public:
                ListNode* reverseList(ListNode* head) {
                    ListNode* newNode = NULL;
                    while(head != NULL) {
                        ListNode* next = head -> next;
                        head -> next = newNode;
                        newNode = head;
                        head = next;
                    }
                    return newNode;
                }
            };
            ```
    -   Recursive Approach

        -   We’ll basically do what we did in each iteration in the iterative solution
        -   but we’ll pass newHead as the head → next instead of updating an iterator
        -   Code

            ```cpp
            class Solution {
            public:
                ListNode* reverse(ListNode* head) {
                    if(head == NULL or head -> next == NULL)
                        return head;

                    ListNode* smHead = reverse(head -> next);

                    head -> next -> next = head;
                    head -> next = NULL;

                    return smHead;
                }
                ListNode* reverseList(ListNode* head) {
                    reverse(head);
                }

            };
            ```

-   Middle of a Linked List
    [https://leetcode.com/problems/middle-of-the-linked-list/](https://leetcode.com/problems/middle-of-the-linked-list/)

    -   Naive

        -   Count the number of nodes in the linkedList
        -   Find the middle
        -   Find the node at this middle
        -   Complexity: O(N) + O(N/2) and O(1) Space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                ListNode* middleNode(ListNode* head) {
                    int size = 1;
                    ListNode* itr = head;
                    while(itr -> next != NULL){
                        itr = itr -> next;
                        size++;
                    }

                    size = size / 2 + 1;
                    int i = 1;

                    ListNode* ans = head;

                    while(i < size){
                        ans = ans -> next;
                        i++;
                    }

                    return ans;
                }
            };
            ```

    -   Optimised Method
        (Tortoise Method)

        -   Create two pointers i and j where, i increments by 1 and j increments by 2
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                ListNode* middleNode(ListNode* head) {
                    ListNode* fast = head; ListNode* slow = head;

                    while(fast != NULL and fast->next != NULL) {
                        slow = slow->next;
                        fast = fast->next->next;
                    }

                    return slow;
                }
            };
            ```

-   Merge Two Sorted Linked List
    [https://leetcode.com/problems/merge-two-sorted-lists/](https://leetcode.com/problems/merge-two-sorted-lists/)

    -   Naive
        -   We’ll have two pointers iterative over both the linked lists
        -   For each iteration we’ll check which one is greater equal or less
        -   Then, Add it to the new LinkedList accordingly
        -   Complexity: O(n1 + n2) time and O(n1 + n2) space
    -   In-Place

        -   We’ll make the linked list elements point to each other according to there value
        -   Let l1 and l2 represent both the lists
        -   l1 will have the smaller and l2 will have the larger
            -   Initially, create a node **temp = NULL**
            -   Keep moving the l1 node until **l2** is smaller than **l1**, and update **temp** in each iteration
            -   **temp** will be pointing to one less node than **l1**.
            -   Then, we’ll take the **temp’s** next and point it to l2
        -   After this we’ll check again and assign the smaller node to l1 and larger node to l2, and then we’re gonna do what we did before again.
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
                    if(l1 == NULL) return l2;
                    if(l2 == NULL) return l1;

                    if(l1->val > l2->val ) { //Swap
                        ListNode* temp = l1;
                        l1 = l2;
                        l2 = temp;
                    }

                    ListNode* res = l1;

                    while(l1 != NULL and l2 != NULL) {
                        ListNode* tmp = NULL;

                        while(l1 != NULL and l1->val <= l2->val) {
                            tmp =  l1;
                            l1 = l1->next;
                        }

                        tmp -> next = l2;

                        // Swap
                        ListNode* temp = l1;
                        l1 = l2;
                        l2 = temp;

                    }
                    return res;
                }
            };
            ```

-   Delete a Given Node
    -   Just make the node’s next point to next’s next.
    -   Code
        ```cpp
        if(node -> next) {
                    node->val = node->next->val;
                    node->next = node->next->next;
                } else {
                    node = NULL;
                }
        ```
-   Add two numbers as a Linked List
    [https://leetcode.com/problems/add-two-numbers/](https://leetcode.com/problems/add-two-numbers/)

    -   We need two variables `sum` and `carry`
    -   We check if l1 and l2 ≠ NULL and then adding it to sum. And also if there is anything remaining in the carry variable we add it too.
    -   Then if sum exceeds 9, transferring the carry to the carry variable, which will be
        sum / 10 and then add sum % 10 to the sum variable.
    -   Then create a new Linked List and add the sum as it’s first node
    -   Then move l1 and l2 one step ahead, then in this iteration assign sum = 0
    -   Code

        ```cpp
        /**
         * Definition for singly-linked list.
         * struct ListNode {
         *     int val;
         *     ListNode *next;
         *     ListNode() : val(0), next(nullptr) {}
         *     ListNode(int x) : val(x), next(nullptr) {}
         *     ListNode(int x, ListNode *next) : val(x), next(next) {}
         * };
         */
        class Solution {
        public:
            ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                ListNode* dummy = new ListNode();
                ListNode* temp = dummy;

                int carry = 0;
                while(l1 != NULL or l2 != NULL or carry) {
                    int sum = 0;

                    if(l1 != NULL) {
                        sum += l1 -> val;
                        l1 = l1 -> next;
                    }

                    if(l2 != NULL) {
                        sum += l2 -> val;
                        l2 = l2 -> next;
                    }

                    sum += carry;
                    carry = sum / 10;
                    ListNode* node = new ListNode(sum % 10);
                    temp -> next = node;
                    temp = temp -> next;
                }
                return dummy -> next;
            }
        };
        ```

-   Delete Nth Node from the last
    [https://leetcode.com/problems/remove-nth-node-from-end-of-list/](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

    -   Naive

        -   Find size
        -   Iterate till itr then we have to delete itr - n
        -   delete node accordingly ⇒ could be head or tail too
        -   Complexity: O(N) + O(N) and O(1) space
        -   Code

            ```cpp
            class Solution {
            public:
                    ListNode* removeNthFromEnd(ListNode* head, int N) {
                    if(head == NULL) return NULL;

                    int count(0);

                    ListNode* temp = head;
                    while(temp != NULL) {
                        count++;
                        temp = temp -> next;
                    }
                    count = count - N;

                    if(count == 0) return (head -> next);
                    ListNode* curr = head;
                    ListNode* prev = NULL;

                    while(count > 0) {
                        prev = curr;
                        curr = curr -> next;
                        count--;
                    }

                    prev->next = curr->next;
                    curr->next = NULL;
                    delete(curr);
                    return head;
                }

            };
            ```

    -   Optimised (Tortoise)

        -   Fast pointer and Slow pointer and a dummy node all pointing to the head
        -   Fast moves until n
        -   the, slow and fast moves until n is the last element in the linked list
        -   Then delete the node at the slow pointer
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                ListNode* removeNthFromEnd(ListNode* head, int n) {
                    ListNode* start = new ListNode();
                    start -> next = head;
                    ListNode* fast = start;
                    ListNode* slow = start;

                    for(int i=1; i<=n; ++i) {
                        fast = fast -> next;
                    }

                    while(fast -> next != NULL) {
                        fast = fast->next;
                        slow = slow->next;
                    }

                    slow -> next = slow -> next -> next;

                    return start -> next;
                }
            };
            ```

-   Intersection of two LinkedList
    [https://leetcode.com/problems/intersection-of-two-linked-lists/](https://leetcode.com/problems/intersection-of-two-linked-lists/)

    -   Naive
        -   We’ll have a nested loop, checking for each of possible combination of the two linkedLists if they are equal
        -   Complexity: O(MxN) time and O(1) space
    -   Optimised

        -   We’ll create a hashSet and insert the whole node in the set if it is not already there
        -   If the node is already present in the set then it is our answer
        -   Complexity: O(m + n) time and O(m + n) space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                    unordered_set<ListNode*> st;

                    while(headA or headB) {
                        if(headA) {
                            if(st.find(headA) == st.end()) {
                                st.insert(headA);
                                headA = headA -> next;
                            } else {
                                return headA;
                            }
                        }

                        if(headB) {
                            if(st.find(headB) == st.end()) {
                                st.insert(headB);
                                headB = headB -> next;
                            } else {
                                return headB;
                            }
                        }
                    }
                    return NULL;
                }
            };
            ```

    -   Best

        -   We’ll first find out the length of both the LinkedLists using two dummy nodes
        -   Then re-initialise these two dummy nodes then find out the difference between the longer and the shorter lengths of the LinkedList.
        -   Now move the dummy node of the longer linkedList by the difference
        -   No iterate both the linkedLists until headA == headB then return this.
        -   Complexity : O(1) space and O (2m + n) space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                    int a(0), b(0);

                    ListNode* A = headA;
                    ListNode* B = headB;
                    while(A) {
                        A = A -> next;
                        a++;
                    }
                    while(B) {
                        B = B -> next;
                        b++;
                    }
                    int diff = abs(a - b);

                    if(a > b) {
                        while(diff--) {
                            headA = headA -> next;
                        }
                    } else {
                        while(diff--) {
                            headB = headB -> next;
                        }
                    }

                    while(headA and headB) {
                        if(headA == headB) {
                            return headA;
                        }
                        headA = headA -> next;
                        headB = headB -> next;
                    }

                    return NULL;
                }
            };
            ```

    -   Better Approach still
        [https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34](https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34) (12:55)

        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                    if(!headA or !headB) return NULL;

                    ListNode* A = headA;
                    ListNode* B = headB;

                    while(A != B) {
                        A = A == NULL ? headB : A -> next;
                        B = B == NULL ? headA : B -> next;
                    }

                    return A;
                }
            };
            ```

-   Palindrome LinkedList
    [https://leetcode.com/problems/palindrome-linked-list/](https://leetcode.com/problems/palindrome-linked-list/)

    -   Naive

        -   We will create a second LinkedList which will be the reverse of the given LinkedList
        -   Then we’ll iterate both of then and check if each iteration is same or not, if not then not palindrome
        -   Or instead of create a second linkedList we can also create a vector and check if this vector is palindrome or not
        -   Complexity: O(2N) time and O(N) space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                bool isPalindrome(ListNode* head) {
                    vector<int> v;

                    ListNode* temp = head;
                    while(temp) {
                        v.push_back(temp -> val);
                        temp = temp -> next;
                    }

                    for(int i=0; i<v.size(); i++) {
                        if(v[i] != v[v.size() - 1 - i])
                            return false;
                    }
                    return true;
                }
            };
            ```

    -   Optimised

        -   At first we’ll find the middle of the linkedList
        -   Slow pointer will be pointing at the middle of the LinkedList
        -   Next, we will reverse the right half of the linkedList
        -   Then, move slow pointer by one step and create a dummy node at the head
        -   Then iterate this dummy node and slow pointer by one and their value should be equal.
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:

                ListNode* reverseList(ListNode* head) {
                    ListNode* newNode = NULL;
                    while(head != NULL) {
                        ListNode* next = head -> next;
                        head -> next = newNode;
                        newNode = head;
                        head = next;
                    }
                    return newNode;
                }

                bool isPalindrome(ListNode* head) {
                    if(!head or head -> next == NULL) return true;

                    ListNode* slow = head;
                    ListNode* fast = head;

                    while(fast -> next != NULL and fast -> next -> next != NULL) {
                        slow = slow -> next;
                        fast = fast -> next -> next;
                    }

                    slow -> next = reverseList(slow -> next);
                    slow = slow -> next;

                    while(slow) {
                        if(head -> val != slow -> val)
                            return false;
                        head = head -> next;
                        slow = slow -> next;
                    }

                    return true;
                }
            };
            ```

-   Detect a Cycle in a LinkedList
    [https://leetcode.com/problems/linked-list-cycle/](https://leetcode.com/problems/linked-list-cycle/)

    -   Naive

        -   We can create a hasSet of all the elements in the linkedList
        -   Then iterate over the linkedList and check if it is already present or not
        -   Complexity: O(N) time and O(N) space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                bool hasCycle(ListNode *head) {
                    unordered_set<ListNode*> st;

                    while(head) {
                        if(st.find(head) != st.end()) return true;
                        st.insert(head);
                        head = head -> next;
                    }

                    return false;
                }
            };
            ```

    -   Optimised

        -   **If we take two pointers one slow and one fast then if there is a cycle, then it is certain that the fast pointer and slow pointer will meet at a node**
        -   The reason is that, if the fast is behind the slow (which it will be if there is a cycle) then if s moves one step and fast moves two steps then they will meet.
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                bool hasCycle(ListNode *head) {

                    if(head == NULL or head -> next == NULL) return false;

                    ListNode* slow = head;
                    ListNode* fast = head;

                    while(fast -> next && fast -> next -> next) {
                        slow = slow -> next;
                        fast = fast -> next -> next;
                        if (slow == fast) return true;
                    }
                    return false;
                }
            };
            ```

-   Reverse k groups LinkedList
    [https://leetcode.com/problems/reverse-nodes-in-k-group/](https://leetcode.com/problems/reverse-nodes-in-k-group/)

    > **Note: We can’t reverse if the remaining nodes are less than k**

    -   Naive
        -   We can just individually reverse all the smaller linkedLists of size k
    -   Another Approach

        -   At first we need to count the length of the linkedList
        -   And then until the count is less than or equal to k, we’ll keep reversing k groups
        -   Complexit: O(1) space and O(N \* k) time
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                int size = 0;
                ListNode* reverseKGroup(ListNode* head, int k) {
                    ListNode* dummy = new ListNode(0);
                    dummy -> next = head;

                    ListNode* curr = dummy, *next = dummy, *pre = dummy;

                    int cnt = 0;

                    while(curr -> next) {
                        curr = curr -> next;
                        cnt++;
                    }

                    while(cnt >= k) {
                        curr = pre -> next;
                        next = curr -> next;

                        for(int i=1; i<k; i++) {
                            curr -> next = next -> next;
                            next -> next = pre -> next;
                            pre -> next = next;
                            next = curr -> next;
                        }
                        pre = curr;
                        cnt -= k;
                    }

                    return dummy -> next;
                }
            };
            ```

-   Find the index of intersection of cycle in linked list
    [https://leetcode.com/problems/linked-list-cycle-ii/](https://leetcode.com/problems/linked-list-cycle-ii/)

    -   Naive

        -   The basic approach would be to use a hashSet and store all the nodes in the set
        -   If the next of an elements point to an element in the set then that is our answer.
        -   O(N) time and O(N) space
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                ListNode *detectCycle(ListNode *head) {

                    if(!head or !(head -> next) or !(head -> next -> next)) return NULL;

                    unordered_set<ListNode*> st;

                    ListNode* temp = head;

                    while(temp) {
                        if(st.find(temp) != st.end()) {
                            return temp;
                        }
                        st.insert(temp);
                        temp = temp -> next;
                    }
                    return NULL;
                }
            };
            ```

    -   Optimised

        -   First step is to find the colliding point of fast and slow pointer
        -   Then we’ll take another pointer which starts from the head and since the slow pointer is inside the cycle, the point these two pointers collide is the point where the cycle is.
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode(int x) : val(x), next(NULL) {}
             * };
             */
            class Solution {
            public:
                ListNode *detectCycle(ListNode *head) {

                    if(!head or !(head -> next) or !(head -> next -> next)) return NULL;

                    ListNode* slow = head;
                    ListNode* fast = head;

                    ListNode* itr = head;

                    while(fast -> next != NULL and fast -> next -> next != NULL) {
                        slow = slow -> next;
                        fast = fast -> next -> next;
                        if(fast == slow) {
                            while(itr != slow) {
                                slow = slow -> next;
                                itr = itr -> next;
                            }
                            return itr;
                        }
                    }

                    return NULL;
                }
            }
            ```

-   Flattening of Linked List
    [https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)

    -   Let’s imagine a Linked List with just two node, which basically are two linked lists
    -   19 → 28
        | |
        12 35
        | |
        50 40
        |
        35
    -   What we have are two sorted LinkedList so, we’ll simply perform
        `Merge two sorted LinkedList`
    -   We’ll start from the end of the linkedList and sort two linked lists one by one
    -   Code

        ```cpp
        /* Node structure  used in the program

        struct Node{
        	int data;
        	struct Node * next;
        	struct Node * bottom;

        	Node(int x){
        	    data = x;
        	    next = NULL;
        	    bottom = NULL;
        	}

        };
        */
        Node *mergeTwoLists(Node* a, Node* b) {
            Node* temp = new Node(0);
            Node* res = temp;

            while(a and b) {
                if(a -> data < b -> data) {
                    temp -> bottom = a;
                    temp = temp -> bottom;
                    a = a -> bottom;
                } else {
                    temp -> bottom = b;
                    temp = temp -> bottom;
                    b = b -> bottom;
                }
            }

            if(a) temp -> bottom = a;
            else temp -> bottom = b;

            return res -> bottom;
        }

        Node *flatten(Node *root)
        {
            if(root == NULL or root -> next == NULL) {
                return root;
            }
            root -> next = flatten(root -> next);
            root = mergeTwoLists(root, root -> next);

            return root;
        }
        ```

-   Clone a Linked List with next and random pointer
    [https://leetcode.com/problems/copy-list-with-random-pointer/](https://leetcode.com/problems/copy-list-with-random-pointer/)

    -   Naive

        -   We would represent the given linkedList as a HasMap <Node, Node>
        -   We will traverse the linked list and create a node, but will not assign the next and random pointers to it. And the push this node with the linkedList’s node into the hashMap. The link between them is represented by the fact that they are present at the same level in the hashMap
        -   Then we’ll iterate the linkedList again, and update the next and random pointers of the new LinkedList with the correct ones using the properties of HashMap
        -   Complexity: O(N) time and O(N) space
        -   Code

            ```cpp
            /*
            // Definition for a Node.
            class Node {
            public:
                int val;
                Node* next;
                Node* random;

                Node(int _val) {
                    val = _val;
                    next = NULL;
                    random = NULL;
                }
            };
            */

            class Solution {
            public:
                Node* copyRandomList(Node* head) {
                    unordered_map<Node*, Node*> mp;

                    Node* temp = head;
                    while(temp) {
                        Node* cp = new Node(temp -> val);
                        mp[temp] = cp;
                        temp = temp -> next;
                    }

                    temp = head;
                    while(temp) {
                        mp[temp] -> next = mp[temp -> next];
                        mp[temp] -> random = mp[temp -> random];
                        temp = temp -> next;
                    }

                    return mp[head];
                }
            };
            ```

    -   Optimal Approach

        -   We’re gonna make copy nodes and insert them right after the original node
            1 → 2 → 3 → 4
            1 → 1’ → 2 → 2’ → 3 → 3’ → 4 → 4’
        -   In the second step, we’re gonna take an iterator say itr the, at every step we’re gonna perform the follow:
            itr → next → random (The copy node) = itr → random → next (Random’s copy node)
        -   In the final step we have to untangle the copy nodes from the original nodes getting back the original linkedList and the copied linkedList
        -   Code

            ```cpp
            /*
            // Definition for a Node.
            class Node {
            public:
                int val;
                Node* next;
                Node* random;

                Node(int _val) {
                    val = _val;
                    next = NULL;
                    random = NULL;
                }
            };
            */

            class Solution {
            public:
                Node* copyRandomList(Node* head) {
                      Node *iter = head;
                      Node *front = head;

                      // First round: make copy of each node,
                      // and link them together side-by-side in a single list.
                      while (iter != NULL) {
                        front = iter->next;

                        Node *copy = new Node(iter->val);
                        iter->next = copy;
                        copy->next = front;

                        iter = front;
                      }

                      // Second round: assign random pointers for the copy nodes.
                      iter = head;
                      while (iter != NULL) {
                        if (iter->random != NULL) {
                          iter->next->random = iter->random->next;
                        }
                        iter = iter->next->next;
                      }

                      // Third round: restore the original list, and extract the copy list.
                      iter = head;
                      Node *pseudoHead = new Node(0);
                      Node *copy = pseudoHead;

                      while (iter != NULL) {
                        front = iter->next->next;

                        // extract the copy
                        copy->next = iter->next;

                        // restore the original list
                        iter->next = front;

                        copy = copy -> next;
                        iter = front;
                      }

                      return pseudoHead->next;
                }
            };
            ```

            </details>

<details>
    <summary>
    <h3>Two Pointer</h3>
    </summary>

-   3 Sum
    [https://leetcode.com/problems/3sum/](https://leetcode.com/problems/3sum/)

    -   Brute Force
        -   Three nested loops checking for every possible permutation of three numbers
        -   i ≠ j ≠ k, then if the sum is equal to the target push it to the ans set
        -   then convert the set to a vector
        -   Complexity: O(N^3 \* logM) time and O(N) + O(M) space
    -   Better
        -   Make a HashTable with elements of the vector with their frequency in the vector
        -   We can use two nested loop to generate a and b
        -   for c we can say c = -(a + b) since a + b + c = 0
        -   Since we cannot use the same element more than one time, we would check if each of the element is present in the HashTable and decrement it’s frequency. Then increment it later on.
        -   This ensures that a and b are not repeating as c
        -   Then again, check for a[i] - a[j] then if we find a pair whose sum is equal to zero, then we will push it to a Hash Set
        -   Complexity: O(N \* logM) time and O(M) + O(N)
    -   Best

        -   For this, we’re gonna use the two pointer approach
        -   For this, we’ll need to sort the array.
        -   Then we’ll fix one of the elements then, a + b = -c
        -   Now we have the two sum problem at hand, not to find this a and b we can initialise two pointer left(i + 1) and right(n - 1)
        -   if v[left] + v[right] > - c ⇒ right —
            if v[left] + v[right] < -c ⇒ right ++
            if v[left] + v[right] == c ⇒ push to set the triplet
        -   Code

            ```cpp
            class Solution {
            public:
                vector<vector<int>> threeSum(vector<int>& nums) {
                    int n = nums.size();
                    sort(nums.begin(), nums.end());

                    vector<vector<int>> ans;

                    for(int i=0; i<n - 2; i++) {

                        if(i == 0 or (i > 0 and nums[i] != nums[i - 1])) {
                            int target = -nums[i];
                            int left(i + 1), right(n - 1);

                            while(left < right) {
                                if(nums[left] + nums[right] == target) {
                                    vector<int> temp {
                                            nums[i],
                                            nums[left],
                                            nums[right]
                                        };
                                    ans.push_back(temp);
            												// Skipping Duplicates
                                    while(left < right and nums[left] == nums[left + 1]) left++;
                                    while(left < right and nums[right] == nums[right - 1]) right--;

                                    left++; right--;
                                }
                                else if(nums[left] + nums[right] > target) right--;
                                else if(nums[left] + nums[right] < target) left++;
                            }
                        }
                    }

                    return ans;
                }
            };
            ```

-   Rotate Linked List by k steps

    -   Naive
        -   Pickup the last node, put it at the front
        -   And keep on repeating it until you have exhausted k
        -   Then result will be our rotated linkedList
        -   Complexity: O(k \* N) time and O(1) space
    -   Optimised

        -   There are two cases that we need to solve, k < n and k ≥ n
        -   if (k == n) don’t rotate
        -   if(k > n) k = k % n
        -   First step is to compute the length of the linked list
        -   Then if we observe carefully, we can see that we only need to break the link of the kth last node and point k - 1 th ( n - k) node to null and kth node to point to the head
        -   Code

            ```cpp
            /**
             * Definition for singly-linked list.
             * struct ListNode {
             *     int val;
             *     ListNode *next;
             *     ListNode() : val(0), next(nullptr) {}
             *     ListNode(int x) : val(x), next(nullptr) {}
             *     ListNode(int x, ListNode *next) : val(x), next(next) {}
             * };
             */
            class Solution {
            public:
                ListNode* rotateRight(ListNode* head, int k) {
                    if(!head or !(head -> next) or k == 0) return head;

                    ListNode* curr = head;
                    int len = 1;
                    while(curr->next and ++len)
                        curr = curr -> next;

                    curr -> next = head;
                    k = k % len;
                    k = len - k;
                    while(k--) curr = curr -> next;

                    head = curr -> next;
                    curr -> next = NULL;

                    return head;
                }
            };
            ```

-   Trapping Rain Water Problem
    [https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

    -   Naive
        -   We’ll tell us for every index what is the water trapped in the pit
        -   Then the answer will be the sum.
        -   The water store in a particular pit will be currHeight - whaterIsTheLargestInLeft
        -   waterAtCurrIndex = min(maxLeft[i], maxRight[i]) - a[i];
        -   and to find these maxLeft and maxRight we would need to iterate from i to 0 and i to n -1 respectively
        -   Complexity: O(n^2) time and O(1) space
    -   Optimised

        -   What we need is the leftMax and rightMax
        -   We can use a prefixMax and suffixMax arrays for that.
        -   This will allow us to get the rightMax and leftMax in O(1)
        -   Complexity: O(3N) time and O(N) space
        -   Code

            ```cpp
            class Solution {
            public:
                int trap(vector<int>& height) {
                    int n = height.size(), ans(0);
                    vector<int> prefixMax(n, 0), suffixMax(n, 0);

                    for(int i=0; i<n; i++) {
                        if(i == 0) {
                            prefixMax[i] = height[i];
                        } else {
                            prefixMax[i] = max(height[i], prefixMax[i - 1]);
                        }
                    }
                    for(int i=n - 1; i>=0; i--) {
                        if(i == n - 1) {
                            suffixMax[i] = height[i];
                        } else {
                            suffixMax[i] = max(height[i], suffixMax[i + 1]);
                        }
                    }

                    for(int i=0; i<n; i++) {
                        ans += min(prefixMax[i] , suffixMax[i]) - height[i];
                    }

                    return ans;
                }
            };
            ```

    -   Best

        -   First off we’re gonna initialise two pointers l(0) and r(n - 1)
        -   If height[l] ≤ height[r]
            if height[i] ≥ leftMax we’ll update the leftMax
            else we’ve found an empty place for water to be stored so we’ll update our water with leftMax - height[i]
        -   if height[l] > height[r]
            if height[r] > leftMax update rightMax to height[r]
        -   Complexity : O(N) time and O(1) space
        -   Code

            ```cpp
            class Solution {
            public:
                int trap(vector<int>& height) {
                    int n = height.size(), ans(0);
                    int left(0), right(n - 1), maxLeft(0), maxRight(0);

                    while(left <= right) {
                        if(height[left] <= height[right]) {
                            if(height[left] >= maxLeft) {
                                maxLeft = height[left];
                            } else {
                                ans += maxLeft - height[left];
                            }
                            left++;
                        } else {
                            if(height[right] >= maxRight) {
                                maxRight = height[right];
                            } else {
                                ans += maxRight - height[right];
                            }
                            right--;
                        }
                    }
                    return ans;
                }
            };
            ```

-   Remove Duplicates from Sorted Array

    -   Naive
        -   We can just use a set and push elements to it, then convert the set to a vector
        -   and at last return the size of the vector
        -   Complexity: O(N) time and O(N) space
    -   Optimised

        -   We will initialise two pointers, both from zero. One would iterate the whole array and the second will be the pointer which will tell us the duplicates removed array.
        -   Dry run code to understand better

        ```cpp
        class Solution {
        public:
            int removeDuplicates(vector<int>& nums) {
                        int idx(0), i(0);
                for(i = 0; i<nums.size(); i++){
                    if(i == 0 or nums[i] != nums[i - 1]){
                        nums[idx] = nums[i];
                        idx++;
                    }
                }
                return idx;

            }
        }
        ```

-   Max Consecutive Ones

    -   We will create two max variable one local and one global
    -   we will update the global variable if local is greater than global whenever we reach a 0 or the end of the array

    ```cpp
    class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int localMax(0), globalMax(0);

            for(int i=0; i<nums.size(); i++) {
                if(nums[i] == 0) {
                    globalMax = max(localMax, globalMax);
                    localMax = 0;
                } else {
                    localMax++;
                }
            }
            globalMax = max(localMax, globalMax);
            return globalMax;
        }
    };
    ```

    </details>

<details>
    <summary>
    <h3>Greedy</h3>
    </summary>

-   N Meetings in one Room
    [https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

    -   Solution

        -   The first approach that comes to mind is to see which meeting ends the earliest and then the second earliest and so on
        -   start = { 1 3 0 5 8 5 }
            end = { 2 4 6 7 9 9 }
            ans = { (1,2), (3,4), (5, 7), (8, 9) } ⇒ 4 Meetings.
        -   Complexity: O(NlogN) time and O(N) space
        -   Code

            ```cpp
            class Solution
            {
                public:
                //Function to find the maximum number of meetings that can
                //be performed in a meeting room.
                int maxMeetings(int start[], int end[], int n)
                {
                    if(n == 0) return 0;

                    vector<vector<int>> vec;

                    for(int i(0); i<n; i++) {
                        vector<int> v {end[i], start[i]};
                        vec.push_back(v);
                    }
                    sort(vec.begin(), vec.end());

                    int limit = vec[0][0];
                    int count(1);

                    for(int i(1); i<vec.size(); i++) {
                        if(vec[i][1] > limit) {
                            limit = vec[i][0];
                            count++;
                        }
                    }
                    return count;
                }
            };
            ```

-   Minimum Platforms
    [https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#)

    -   Check if `arrival` is sorted or not
    -   First we’ll sort `arrival` as well as `departure` array, but it will loose the correspondence with each other if we do this...
    -   Then we’re gonna have two pointers for arrival and departure, and when the arrival pointer value is greater than the departure pointer value, then we’ll increase the departure pointer
    -   While keeping the track of max value and current platform value
    -   Complexity: O(2NlogN) + O(2N)
    -   Code

        ```cpp
        class Solution{
            public:

            int findPlatform(int arr[], int dep[], int n) {
                sort(arr, arr + n); sort(dep, dep + n);

                int i(1), j(0);
                int plt(1), ans(1);

                while(i < n and j < n) {
                    if(arr[i] <= dep[j]) {
                        plt++;
                        i++;
                    } else if(arr[i] > dep[j]) {
                        plt--;
                        j++;
                    }
                    if(plt > ans) {
                        ans = plt;
                    }
                }
                return ans;
            }
        };
        ```

-   Job Scheduling Problem
    [https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)

    -   Let’t take the Job with the max Profit 4
    -   First step is to sort the array in descending order of the profits
    -   One thing to understand is that, we will perform the job with deadline say 6th on the 6th day so that we have 6 days to perform different tasks
    -   We can create an array with the size of the maxDeadline with -1 in it in starting
    -   Then we’ll iterate the array and if the jobs array has curr deadline empty we’ll simply update the ans and fill it.
    -   But if the jobs array is not empty we will decrease the index until it is empty, and if it reaches zero then we’ll break;
    -   Code

        ```cpp
        class Solution
        {
            public:
            //Function to find the maximum profit and the number of jobs done.
            vector<int> JobScheduling(Job arr[], int n)
            {
                //Sorting, profit increasing
                sort(arr, arr + n,
                [](Job a, Job b) {
                    return a.profit > b.profit;
                });

                int maxDead(0), ans(0), cnt(0);
                for(int i=0; i<n; i++) maxDead = max(maxDead, arr[i].dead);

                vector<int> jobs(maxDead + 1, -1);

                for(int i=0; i<n; i++) {
                    for(int j = arr[i].dead; j > 0; j--) {
                        if(jobs[j] == -1) {
                            jobs[j] = i;
                            cnt++;
                            ans += arr[i].profit;
                            break;
                        }
                    }
                }

                vector<int> v{cnt, ans};
                return v;
            }
        };
        ```

-   No of Coins
    [https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/#](https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/#)

    -   Solution

        -   We can sort the array of coins
        -   And then for every iteration of this coin array we’ll subtract coins[i] from the value until it is less than coins[i];
        -   Then we’ll do the same for every iteration
        -   Code

            ```cpp
            class Solution{
            public:
                vector<int> minPartition(int V)
                {
                    vector<int> coins{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
                    vector<int> ans;
            	    for(int i=9; i>=0; i--) {
            	        while(V >= coins[i]) {
            	            V -= coins[i];
            	            ans.push_back(coins[i]);
            	        }
            	        if(V == 0) break;
            	    }

            	    return ans;
                }
            };
            ```

-   Fractional Knapsack
    [https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)

            -   We will look for `value/weight` Maximum.
            -   So we’ll sort both the array this way.
            -   Code

                ```cpp
                class Solution
                {
                    public:
                    //Function to get the maximum total value in the knapsack.
                    double fractionalKnapsack(int W, Item arr[], int n)
                    {
                        sort(arr, arr + n,
                        [](Item a, Item b) {
                            double r1 = (double)a.value/(double)a.weight;
                            double r2 = (double)b.value/(double)b.weight;
                            return r1 > r2;
                        });

                        int currWeight(0);
                        double finalValue(0.0);

                        for(int i=0; i<n; i++) {
                            if(currWeight + arr[i].weight <= W) {
                                currWeight += arr[i].weight;
                                finalValue += arr[i].value;
                            }
                            else {
                                int r = W - currWeight;
                                finalValue += (arr[i].value / (double)arr[i].weight) * (double)r;
                                break;
                            }
                        }
                        return finalValue;
                    }
                };
                ```

    </details>

<details>
    <summary>
    <h3>Recursion</h3>
    </summary>

-   Subset Sums
    [https://practice.geeksforgeeks.org/problems/subset-sums2234/1](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)
    -   Naive
        -   Generate all the subsets and take their sum
        -   We can use Power Set to do this
        -   Complexity: O(2^N \* N) time ⇒ Non Recursive.
    -   Solution
        -   Let’s take the example array to be {3, 1, 2}
        -   Let’s think it like this: \_ \_ \_ there are three places to fill, we have to decide which index we’re gonna select for the subset
        -   And we can make this decision of selecting or not selecting an index using recursion
        -   In one recursion call we’ll add arr[i] to the sum and make the call with i + 1
        -   while in the other recursion call we will pass sum as it is with i + 1
    -   Code
        ```cpp
        public:
            vector<int> v;
            void solve(vector<int> arr, int sum, int i) {
                if(i == arr.size()) {
                    v.push_back(sum);
                    return;
                }
                solve(arr, sum, i + 1);
                solve(arr, sum + arr[i], i + 1);
            }
            vector<int> subsetSums(vector<int> arr, int N)
            {
                solve(arr, 0, 0);
                sort(v.begin(), v.end());
                return v;
            }
        };
        ```
-   Subset Generation ( Power Set)
    [https://leetcode.com/problems/subsets-ii/](https://leetcode.com/problems/subsets-ii/)

    -   Naive

        -   We are going to use the pick and no pick technique to generate all the 2^N subsets and then push it into a vector of vectors
        -   Then use set to remove duplicate vectors and the return this new vector of vectors
        -   Complexity: M \* Log M + 2 ^ N
        -   Code

            ```cpp
            class Solution {
            public:
                vector<vector<int>> powerSet = {{}};

                void helper(vector<int> nums, int i = 0, vector<int> v = {}) {
                    if(i == nums.size()) {
                        sort(v.begin(), v.end());
                        powerSet.push_back(v);
                        return;
                    }
                    helper(nums, i + 1, v);
                    v.push_back(nums[i]);
                    helper(nums, i + 1, v);
                }

                vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                    helper(nums);

                    set<vector<int>> st;
                    for(auto x : powerSet) st.insert(x);

                    vector<vector<int>> ans(st.begin(), st.end());

                    return ans;
                }
            };
            ```

    -   Optimised

        -   In the naive approach we are wasting our precious time on inserting the elements on the inserting our elements for remove duplicates.
        -   We will have to figure out a way to remove duplicates without the use of the set
        -   Let’s say we have [1, 2 ,2] as the input array. Now in our approach we would either choose or skip each index, let’s say we chose the `2` on the 1st index, then it won’t make sense to those `2` again on the 3rd index.
        -   Which means, whenever there are duplicate elements then we’ll only chose the first occurrence of the element
        -   Code

            ```cpp
            class Solution {
            public:
                vector<vector<int>> powerSet;

                void helper(vector<int> nums, int i = 0, vector<int> v = {}) {
                    powerSet.push_back(v);

                    for(int itr = i; itr < nums.size(); itr++) {
                        if(itr != i and nums[itr] == nums[itr - 1]) continue;

                        v.push_back(nums[itr]);
                        helper(nums, itr + 1, v);
                        v.pop_back();
                    }
                }

                vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                    sort(nums.begin(), nums.end());

                    helper(nums);
                    return powerSet;
                }
            };
            ```

-   Combination Sum 1
    [https://leetcode.com/problems/combination-sum/](https://leetcode.com/problems/combination-sum/)

    -   Approach

        -   The naive approach would be to generate all the subsequences by the
            `pick and skip` method, in which we can subtract the current element from the target, and then pass target - a[i] to the new recursion call or else we can pass the target as is, and when the target reaches 0 that’s one of our subsets.
        -   Complexity: O(2 ^ t \* k)
        -   Code

            ```cpp
            class Solution {
            public:
                vector<vector<int>> ans;

                void helper(vector<int> candidates, int target, int i = 0, vector<int> v = {}) {
                    if(i == candidates.size()) {
                        if(target == 0) {
                            ans.push_back(v);
                        }
                        return;
                    }

                    if(candidates[i] <= target) {
                        v.push_back(candidates[i]);
                        helper(candidates, target - candidates[i], i, v);
                        v.pop_back();
                    }
                    helper(candidates, target, i + 1, v);
                }

                vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                    helper(candidates, target);
                    return ans;
                }
            };
            ```

-   Combination Sum 2
    [https://leetcode.com/problems/combination-sum-ii/](https://leetcode.com/problems/combination-sum-ii/)

        -   The solution to this problem is similar to similar to Subset Generation II, so what we can do is, we can take the first occurrence of the element if there exists duplicates.
        -   Then if a[i] > target then we’ll just break out of the loop
        -   else we’ll do a recursion call with target - a[i]
        -   And the base case will be target == 0
        -   Complexity: **O(2^n\*k)**
        -   Code

            ```cpp
            class Solution {
            public:

                vector<vector<int>> ans;

                void helper(vector<int> candidates, int target, int i = 0, vector<int> v = {}) {
                    if(target == 0) {
                        ans.push_back(v);
                        return;
                    }

                    for(int idx = i; i<candidates.size(); i++) {
                        if(idx != i and candidates[i] == candidates[i - 1]) continue;

                        if(candidates[i] > target) break;

                        v.push_back(candidates[i]);
                        helper(candidates, target - candidates[i], i + 1, v);
                        v.pop_back();
                    }
                }

                vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                    sort(candidates.begin(), candidates.end());

                    helper(candidates, target);

                    return ans;
                }
            };
            ```

    </details>

<details>
    <summary>
    <h3>Binary Search</h3>
    </summary>

-   Single Element in sorted Array
    [https://leetcode.com/problems/single-element-in-a-sorted-array/](https://leetcode.com/problems/single-element-in-a-sorted-array/)

    -   Naive
        -   We can iterate over the whole keeping the count, and then iterate again to return one with count = 2
    -   Approach 1 (XOR)
        -   **x^x = 0**
        -   We can use this property to check when we find that the xor is not equal to zero
        -   Complexity O(n) time and O(1) space
    -   Optimised
        -   Observation, _odd_ index and _even_ index
        -   Before Pivot: first instance of the duplicate number is at the even index and the second is on the odd index.
        -   After Pivot: first instance odd and second even
    -   Code

        ```cpp
        class Solution {
        public:
            int singleNonDuplicate(vector<int>& nums) {
                int lo(0), hi(nums.size() - 2);

                while(lo <= hi) {
                    int mid = lo + (hi - lo) / 2;

                    if(mid % 2 == 0) {
                        if(nums[mid] != nums[mid + 1]) {
                            // Right half
                            hi = mid - 1;
                        } else
                            lo = mid + 1;
                    } else {
                       if(nums[mid] == nums[mid + 1]) {
                           // Right half
                           hi = mid - 1;
                       } else
                           lo = mid + 1;:
                    }
                }
                return nums[lo];
            }
        };
        ```

-   Search in Rotated Sorted Array
    [https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)

    -   Naive
        -   We can linearly search in the array and check if there exist the target
        -   If not then -1 and if there is then that element’s index.
    -   Optimised

        -   We can think of the array as two sorted arrays divided on the index of the smallest element.
        -   We can perform binary search in each of the index
        -   One thing that comes to mind is that we can find the index of the smallest element and perform two different binary searches, but it then defeats the purpose making the complexity O(n)
        -   So, we first check if left half (by checking the mid and the lo) and then check if target present in this sorted left half (nums[lo] ≤ target ≤ nums[mid])
        -   Code

            ```cpp
            class Solution {
            public:
                int search(vector<int>& nums, int target) {
                    int lo(0), hi(nums.size() - 1);

                    while(lo <= hi) {
                        int mid = (hi + lo) / 2;

                        if(nums[mid] == target) return mid;

                        if(nums[lo] <= nums[mid]) {// Left Half sorted
                            if(nums[lo] <= target and nums[mid] >= target)
                                hi = mid - 1;
                             else
                                lo = mid + 1;
                        } else {// Left half not sorted
                            if (nums[mid] <= target and target <= nums[hi])
                                lo = mid + 1;
                            else
                                hi = mid - 1;
                        }
                    }
                    return -1;
                }
            };
            ```

-   **Matrix Median**
    [https://www.interviewbit.com/problems/matrix-median/](https://www.interviewbit.com/problems/matrix-median/)
    -   Naive
        -   Push the matrix in a linear ds and then sort it
        -   Find the middle voilla we have the median
        -   Complexity: O(n*m) time and O(n*m) space

</details>

<details>
    <summary>
    <h3>Stack and Queues</h3>
    </summary>

-   Implementation

    -   Implement Stack using Array
        -   Simple AF don’t need to write anything here
        -   Code
            ```cpp
            class Stack {
              int size;
              int * arr;
              int top;
              public:
                Stack() {
                  top = -1;
                  size = 1000;
                  arr = new int[size];
                }
              void push(int x) {
                top++;
                arr[top] = x;
              }
              int pop() {
                int x = arr[top];
                top--;
                return x;
              }
              int Top() {
                return arr[top];
              }
              int Size() {
                return top + 1;
              }
            };
            ```
    -   Implement Queue using Array

        -   In this we need to focus on the edge case, and I want me to think about all the cases without writing them here.
        -   Front and Rear (Two Pointers) + cntOfCurrEls
        -   If cntOfCurrEls < size ⇒ rear = size % rear (Why?)
        -   Code

            ```cpp
            class Queue {
              int * arr;
              int start, end, currSize, maxSize;
              public:
                Queue() {
                  arr = new int[16];
                  start = -1;
                  end = -1;
                  currSize = 0;
                }

              Queue(int maxSize) {
                ( * this).maxSize = maxSize;
                arr = new int[maxSize];
                start = -1;
                end = -1;
                currSize = 0;
              }
              void push(int newElement) {
                if (currSize == maxSize) {
                  cout << "Queue is full\nExiting..." << endl;
                  exit(1);
                }
                if (end == -1) {
                  start = 0;
                  end = 0;
                } else
                  end = (end + 1) % maxSize;
                arr[end] = newElement;
                cout << "The element pushed is " << newElement << endl;
                currSize++;
              }
              int pop() {
                if (start == -1) {
                  cout << "Queue Empty\nExiting..." << endl;
                }
                int popped = arr[start];
                if (currSize == 1) {
                  start = -1;
                  end = -1;
                } else
                  start = (start + 1) % maxSize;
                currSize--;
                return popped;
              }
              int top() {
                if (start == -1) {
                  cout << "Queue is Empty" << endl;
                  exit(1);
                }
                return arr[start];
              }
              int size() {
                return currSize;
              }

            };
            ```

    -   Implement Stack using Queue

        -   We want’ the latest element that we inserted when we pop an element but Queues does the exact opposite
        -   We can work around this by re arranging the elements in such a way that we get latest element
        -   We can achieve this by pushing in the queue then from the queue removing it and then pushing it again.
        -   Complexity: O(N) space and O(N) time
        -   Code

            ```cpp
            class MyStack {
            public:
                queue<int> q;
                void push(int x) {
                    int s = q.size();
                    q.push(x);
                    for(int i=0; i<s; i++) {
                        q.push(q.front());
                        q.pop();
                    }
                }

                int pop() {
                    int n = q.front();
                    q.pop();
                    return n;
                }

                int top() {
                    return q.front();
                }

                bool empty() {
                    return q.empty();
                }
            };

            /**
             * Your MyStack object will be instantiated and called as such:
             * MyStack* obj = new MyStack();
             * obj->push(x);
             * int param_2 = obj->pop();
             * int param_3 = obj->top();
             * bool param_4 = obj->empty();
             */
            ```

    -   Implement Queue using stack (O(1) Amortised)

        -   Approach 1
            -   A naive approach would be use two stack (s1 and s2) and then perform the push operation as follows:
                -   s1 → s2
                -   x → s1
                -   s2 → s1
            -   Complexity O(N) time and O(2N) space
        -   Approach 2

            -   We are gonna be using a Input stack and an output stack
            -   push() will push into the input stack
            -   pop() will check if `output !empty()` it will pop from output else it will transfer input to output then pop()
            -   top() will check if `output !empty()` it will return from output else it will transfer input to output then return from output
            -   Complexity: O(1) Amortised time and O(2N) space
            -   Code

                ```cpp
                struct Queue {
                  stack <int> input, output;

                  // Push elements in queue
                  void Push(int data) {
                    // Pop out all elements from the stack input
                    while (!input.empty()) {
                      output.push(input.top());
                      input.pop();
                    }
                    // Insert the desired element in the stack input
                    cout << "The element pushed is " << data << endl;
                    input.push(data);
                    // Pop out elements from the stack output and push them into the stack input
                    while (!output.empty()) {
                      input.push(output.top());
                      output.pop();
                    }
                  }
                  // Pop the element from the Queue
                  int Pop() {
                    if (input.empty()) {
                      cout << "Stack is empty";
                      exit(0);
                    }
                    int val = input.top();
                    input.pop();
                    return val;
                  }
                  // Return the Topmost element from the Queue
                  int Top() {
                    if (input.empty()) {
                      cout << "Stack is empty";
                      exit(0);
                    }
                    return input.top();
                  }
                  // Return the size of the Queue
                  int size() {
                    return input.size();
                  }
                };
                ```

-   Valid Parenthesis
    [https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)

    -   Just go through the code once, it is a very easy problem
    -   Code

        ```cpp
        class Solution {
        public:
            bool isValid(string s) {
                stack<char> st;
                map<char, int> smbls = {
                    {'[', -1},
                    {'{', -2},
                    {'(', -3},
                    {']', 1},
                    {'}', 2},
                    {')', 3},
                };

                for(char br : s) {
                    if(smbls[br] < 0)
                        st.push(br);
                    else{
                        if(st.empty())
                            return 0;
                        char top = st.top();
                        st.pop();
                        if(smbls[top] + smbls[br] != 0)
                            return 0;
                   }
                }

                return st.empty();
            }
        };
        ```

-   Next Greater Element
    [https://leetcode.com/problems/next-greater-element-i/](https://leetcode.com/problems/next-greater-element-i/)
    Problem Statement:
    Given a circular integer array **A**, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn’t exist, return -1 for this element.

    -   Naive Approach
        -   For every element i = 0 to i = n - 1 we’ll iterate the array from i + 1 to the end to find the greater element and push it to the array
        -   If we don’t find any element we will just push -1 to the answer array
        -   Complexity O(N^2) time
        -   Code
            ```cpp
            class Solution {
            public:
                vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
                    vector<int> ans;
                    for(int i=0; i<n1.size(); i++) {
                        int check = 0;
                        for(int j=0; j<n2.size(); j++) {
                            if(n2[j] == n1[i]) {
                                for(int k=j+1; k<n2.size(); k++) {
                                    if(n2[k] > n1[i])  {
                                        check = 1;
                                        ans.push_back(n2[k]);
                                        break;
                                    }
                                }
                            }
                            if(check)
                                break;
                        }
                        if(!check)
                            ans.push_back(-1);
                    }
                    return ans;
                }
            };
            ```
    -   Optimised Approach

        -   We’ll start iterating form the back, and try to find the smaller elements in the stack than the curr element.
        -   If there are smaller element present we’ll pop all of them out until we find a number greater than current
        -   Then we’ll mark that greater element as NGE for curr element and push curr element into the stack
        -   Dry run on : [ 4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6 ] and notice all the patterns
        -   Code

            ```cpp

            ```

        -   Circular Array Variation

            -   This approach is going to be exactly the same, the only change will be to copy the entire array once again right after it, and then perform the above algorithm
            -   Understand the i%n (It has something to do with double size of the array)
            -   Code

                ```cpp
                class Solution {
                public:
                    vector<int> nextGreaterElements(vector<int>& nums) {
                        int n = nums.size();
                        vector<int> nge(n, -1);
                        stack<int> st;

                        for(int i= n*2 - 1; i>=0; i--) {
                            while(!st.empty()
                                  and st.top() <= nums[i % n]) st.pop();
                            if(i < n) {
                                if(!st.empty()) nge[i] = st.top();
                            }
                            st.push(nums[i%n]);
                        }
                        return nge;
                    }
                };
                ```

-   Implement LRU Cache
    Implement the **LRUCache** class:

    -   **LRUCache(int capacity)** we need to initialize the LRU cache with positive size **capacity**.
    -   **int get(int key)** returns the value of the **key** if the key exists, otherwise return **-1**.
    -   **Void put(int key,int value),** Update the value of the **key** if the **key** exists. Otherwise, add the **key-value** pair to the cache.if the number of keys exceeds the **capacity** from this operation, evict the least recently used key.
        The functions **get** and **put** must each run in **O(1)** average time complexity.
    -   Solution

        -   W’re gonna be using a doubly linked list to store the data, because it can happen that we need to delete a node in the middle and array doesn’t support that.
        -   The insertion will be right after the head for every element
        -   And to make get() O(1) we are gonna be using a hash map, which will also give us O(1) put()
        -   On every get() operation, we’ll delete the element in the dll and insert in right after head to maintain the the most recently used, then remove the old address from hash map and insert the new address.
        -   Code

            ```cpp
            class LRUCache {
                list<pair<int,int>> l;
                unordered_map<int,list<pair<int, int>>::iterator> m;
                int size;
            public:
                LRUCache(int capacity) {
                    size = capacity;
                }

                int get(int key) {
                    if(m.find(key) == m.end()) return -1;
                    l.splice(l.begin(), l, m[key]);
                    return m[key] -> second;
                }

                void put(int key, int value) {
                    if(m.find(key)!=m.end()) {
                            l.splice(l.begin(),l,m[key]);
                            m[key]->second=value;
                            return;
                        }
                        if(l.size()==size) {
                            auto d_key=l.back().first;
                            l.pop_back();
                            m.erase(d_key);
                        }
                        l.push_front({key,value});
                        m[key]=l.begin();
                }
            };

            /**
             * Your LRUCache object will be instantiated and called as such:
             * LRUCache* obj = new LRUCache(capacity);
             * int param_1 = obj->get(key);
             * obj->put(key,value);
             */
            ```

</details>

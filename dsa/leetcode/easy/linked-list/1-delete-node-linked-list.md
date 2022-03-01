**3. [Delete Node in a Linked List](https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/)**

<details><summary>Code: </summary>

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
    void deleteNode(ListNode* node) {
        if(node -> next) {
            node->val = node->next->val;
            node->next = node->next->next;
        } else {
            node = NULL;
        }
    }
};
```

</details>

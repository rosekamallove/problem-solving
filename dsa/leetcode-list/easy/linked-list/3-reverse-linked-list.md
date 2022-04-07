**3. [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)**

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
    /* Recursion Approach 2 */

    ListNode* reverse(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return head;

        ListNode* smHead = reverse(head -> next);

        head -> next -> next = head;
        head -> next = NULL;

        return smHead;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    };

    /* Recursive */
    void recurse(ListNode* &head, ListNode* curr, ListNode*prev) {
        if(curr == NULL) {
            head = prev;
            return;
        }
        ListNode* forward = curr -> next;
        recurse(head, forward, curr);
        curr -> next = prev;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        recurse(head, curr, prev);
        return head;
    }

    /* Iterative */
    ListNode* reverseListItr(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* itr = head;

        while(itr != NULL){
            ListNode* next = itr -> next;
            itr -> next = prev;
            prev = itr;
            itr = next;
        }
        head = prev;
        return head;
    }
};
```

</details>

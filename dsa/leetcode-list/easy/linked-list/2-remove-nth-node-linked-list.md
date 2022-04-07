**3. [Delete Nth Node from end in a Linked List](https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/)**

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
    ListNode removeNthFromEnd(ListNode* head, int N) {
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

</details>

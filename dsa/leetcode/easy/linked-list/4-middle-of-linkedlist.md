**4. [Middle of Linked List]()**

<details><summary>Code:</summary>

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

</details>

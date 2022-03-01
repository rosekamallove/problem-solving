**3. [Sort 0 1 2](https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)**

**Approach 1:**

- Simple count sort and then create a new linked list and return it.

**Approach 2:**

- Changin data not allowed
- We gotta change links then right?
- Now to do this, we can create three linked list, each for 0 1 and 2
- Now merge these linked list

<details><summary>Code: </summary>

```cpp
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.

    void insetAtTail(Node* &tail, Node* curr) {
        tail -> next = curr;
        tail = curr;
    }

    Node* segregate(Node *head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;

        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;

        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;


        Node * curr = head;

        while(curr != NULL) {
            int val = curr->data;

            if(value == 0) {
                insetAtTail(zeroTail, curr);
            }
            else if(value == 1) {
                insetAtTail(oneTail, curr);
            }
            else if(value == 2) {
                insetAtTail(twoTail, curr);
            }
        }
    }

    Node* segregate1(Node *head) {
    /********** Count Sort ***********/
        int zero(0), one(0), two(0);
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> data == 0) zero++;
            if(temp -> data == 1) one++;
            if(temp -> data == 2) two++;
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL) {
            if(zero != 0) {
                temp -> data = 0;
                zero--;
            } else if (one != 0) {
                temp -> data = 1;
                one--;
            } else if(two != 0) {
                temp -> data = 2;
                two--;
            }
            temp = temp -> next;
        }
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
```

</details>

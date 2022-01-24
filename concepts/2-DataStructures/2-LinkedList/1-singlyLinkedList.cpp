/*
 * -> A linked list is a data structure formed by nodes in the form of chain
 * -> Each node consist data and pointer to the next node
 *
 * -> The linked list in which each node has one pointer that has
 *    reference to next value is called as "singly linked list"
 *
 * -> It has unidirectional link
 *
 *
 * Operations:
 *
 * Inserion: Inserting a node (head, tail, after nth node)
 * Searching: Searching an element on the linked list
 * Deletion: Deleting a node from a linked list
 */

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node() {
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
    }
};

int size(Node* &head) {
    int size(0);
    Node * itr = head;
    while(itr != NULL) {
        itr = itr -> next;
        size++;
    }
    return size;
}

void InsertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void InsetAtIndex(Node* &head, int idx, int data) {
    Node * newNode = new Node(data);

    Node* prev = head;
    int cnt(1);

    while(cnt < idx - 1) {
        prev = prev -> next;
        cnt++;
    }

    /* Edge Cases */
    int len = size(head);
    if(idx > len) {
        cout<<"Invalid Index";
        return;
    }
    if(idx == len) {
        InsertAtTail(prev, data);
        return;
    }
    if(idx == 1) {
        InsertAtHead(head, data);
        return;
    }

    newNode -> next = prev -> next;
    prev -> next = newNode;
}

void deleteNode(int pos, Node* &head) {
    if(pos == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    } 
    int cnt(1);
    Node* curr = head;
    Node* prev = NULL;

    while(cnt < pos) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<' ';
        temp = temp -> next;
    }
    cout<<endl;
}


int main() {
    Node* Head = new Node(0);
    Node* Tail = Head;
    InsertAtTail(Tail, 1);
    InsertAtTail(Tail, 2);
    InsertAtTail(Tail, 3);
    InsertAtTail(Tail, 4);
    print(Head);
    deleteNode(1, Head);
    print(Head);
}

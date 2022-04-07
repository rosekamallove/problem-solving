/*
 * -> In doubly linked list along with the next pointer there is a previous pointer
 *    also which points to previous node. That  previous pointer allows us to move 
 *    backward/previous node in the linked list
 *
 * -> Advatages:
 *    - Bi-direcitional traversal
 *    - Deletion from back in O(1) operation.
 *
 *
 *  => Operations:
 *
 *  -> Add a new node (front, end)
 *  -> Remove a node 
 *  -> Search a node
 */

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int d) {
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }
};

int getLength(Node* head){
    int cnt(0);
    while(head != NULL){
        head = head -> next;
        cnt++;
    }
    return cnt;
}

void print(Node* head){
    Node* itr = head;

    while(itr != NULL){
        cout<<itr -> data<<' ';
        itr = itr -> next;
    }
    cout<<endl;

}

void insertAtHead(Node* &head, int data) {

    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
    }

    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, int data) {
    Node* tail = head;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }
    Node* newNode = new Node(data);
    tail -> next = newNode;
    newNode -> prev = tail;
}

void insertAtIdx(int idx, Node* &head, int data) {
    Node * newNode = new Node(data);

    Node* prev = head;
    int cnt(1);

    while(cnt < idx - 1) {
        prev = prev -> next;
        cnt++;
    }

    int len = getLength(head);

    if(idx > len or idx < 0){
        cout<<"Invalid Index"<<endl;
        return;
    }
    if(idx == len) {
        insertAtTail(head, data);
        return;
    }
    if(idx == 1) {
        insertAtHead(head, data);
        return;
    }

    prev -> next -> prev = newNode;
    newNode -> next = prev -> next;
    newNode -> prev = prev;
    prev -> next = newNode;
}

void deleteNode(int pos, Node* &head) {
    if(pos == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
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
    curr -> prev = NULL;
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtIdx(1, head, 17);
    print(head);
    deleteNode(1, head);
    print(head);
    deleteNode(4, head);
    print(head);
    cout<<getLength(head);
}

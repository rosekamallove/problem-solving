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

struct Node {
    Node* next;
    int data;
};

Node* head = NULL;

/* Insertion */
void insertTail(int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL) {
        //making temp to be the last elementin in the linked list
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void insertHead(int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAfterNode(int value, int data) {
    value--;
    Node* newNode = new Node();
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* nth = head;
    while(nth->next!=NULL and value>0) {
        nth = nth->next;
        value--;
    }
    Node* prev = nth->next;
    nth->next = newNode;
    newNode->next = prev;
}

/* Searching */
bool searchNode(int value) {
    Node* itr = head;
    if(itr->data == value)
        return 1;

    while(itr->next!=NULL) {
        itr = itr->next;
        if(itr->data == value)
            return 1;
    }
    return 0;
}

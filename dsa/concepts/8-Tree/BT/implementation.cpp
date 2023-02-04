#include "BinaryTreeNode.h"
#include <cstddef>
#include <iostream>
#include <queue>
using namespace std;

void printTree(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << ":";
  if (root->left) {
    cout << "L" << root->left->data;
  }
  cout << ",";
  if (root->right) {
    cout << "R" << root->right->data;
  }
  cout << endl;

  printTree(root->left);
  printTree(root->right);
}

BinaryTreeNode<int> *takeInput() {
  int rootData;
  cout << "Enter the data" << endl;
  cin >> rootData;

  if (rootData == -1)
    return NULL;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int> *left = takeInput();
  BinaryTreeNode<int> *right = takeInput();

  root->left = left;
  root->right = right;

  return root;
}

BinaryTreeNode<int> *takeInputLevelWise() {
  int rootData;
  cin >> rootData;

  if (rootData == -1)
    return NULL;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendinNodes;
  pendinNodes.push(root);

  while (pendinNodes.size()) {
    BinaryTreeNode<int> *front = pendinNodes.front();
    pendinNodes.pop();

    cout << "Enter left child of " << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1) {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
      front->left = child;
      pendinNodes.push(child);
    }

    cout << "Enter right child of " << front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if (leftChildData != -1) {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
      front->right = child;
      pendinNodes.push(child);
    }
  }

  return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
  queue<BinaryTreeNode<int> *> pendinNodes;
  pendinNodes.push(root);

  while (pendinNodes.size()) {
    BinaryTreeNode<int> *front = pendinNodes.front();
    pendinNodes.pop();

    cout << front->data << ":";

    if (front->left) {
      BinaryTreeNode<int> *child = front->left;
      cout << "L:" << child->data << ",";
      pendinNodes.push(child);
    } else {
      cout << "L:" << -1 << ",";
    }
    if (front->right) {
      BinaryTreeNode<int> *child = front->right;
      cout << "R:" << child->data;
      pendinNodes.push(child);
    } else {
      cout << "R:" << -1;
    }
    cout << endl;
  }
}

int countNodes(BinaryTreeNode<int> *root, int count = 0) {
  if (root == NULL)
    return count;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return 0;
  }
  int lHeight = height(root->left);
  int rHeight = height(root->right);

  return 1 + max(lHeight, rHeight);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
  if (root == NULL)
    return false;
  if (root->data == x)
    return true;
  return isNodePresent(root->left, x) or isNodePresent(root->right, x);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;
  BinaryTreeNode<int> *right = root->right;
  root->right = root->left;
  root->left = right;
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
}

void inorder(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << ' ';
  inorder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;

  cout << root->data << ' ';
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << ' ';
}

int main() {
  /*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

  root->left = node1;
  root->right = node2;*/

  BinaryTreeNode<int> *root = takeInputLevelWise();
  inorder(root);
  // printLevelWise(root);
  cout << countNodes(root);
  // cout << isNodePresent(root, 3);
}

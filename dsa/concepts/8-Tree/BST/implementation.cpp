#include "BinaryTreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node<T> *next;

  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
};

bool searchInBST(BinaryTreeNode<int> *root, int k) {
  if (root == NULL)
    return false;

  if (root->data == k)
    return true;

  if (k > root->data)
    return searchInBST(root->right, k);

  return searchInBST(root->left, k);
}

BinaryTreeNode<int> *takeInput() {
  int rootData;
  cin >> rootData;
  if (rootData == -1) {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  while (!q.empty()) {
    BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
    int leftChild, rightChild;
    cin >> leftChild;
    if (leftChild != -1) {
      BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
      currentNode->left = leftNode;
      q.push(leftNode);
    }
    cin >> rightChild;
    if (rightChild != -1) {
      BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
      currentNode->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2) {
  if (NULL == root)
    return;

  if (k1 < root->data)
    elementsInRangeK1K2(root->left, k1, k2);

  if (k1 <= root->data && k2 >= root->data)
    cout << root->data << " ";

  if (k2 > root->data)
    elementsInRangeK1K2(root->right, k1, k2);
}

int maximum(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return INT_MIN;

  return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return INT_MAX;

  return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
  // rightMin > root -> data > leftMax

  if (root == NULL)
    return true;

  int leftMax = maximum(root->left);
  int rightMin = minimum(root->right);

  return (root->data <= rightMin) and (root->data > leftMax) and
         isBST(root->right) and isBST(root->left);
}

class isBSTReturn {
public:
  bool isBST;
  int minimum;
  int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int> *root) {
  // we can return three things instead of one to decrease the number of calls
  // we can use pair<pair<int, int>, bool>
  // where bool: isBST
  // pair<int, int> min and max
  // Or we can make a class

  if (root == NULL) {
    isBSTReturn output;
    output.isBST = true;
    output.maximum = INT_MIN;
    output.minimum = INT_MAX;
    return output;
  }

  isBSTReturn leftOutput = isBST2(root->left);
  isBSTReturn rightOutput = isBST2(root->right);

  int minimum = min(root->data, min(rightOutput.minimum, leftOutput.minimum));
  int maximum = max(root->data, max(rightOutput.maximum, leftOutput.maximum));

  bool isBSTFinal = (root->data > leftOutput.maximum) and
                    (root->data <= rightOutput.minimum) and leftOutput.isBST and
                    rightOutput.isBST;

  isBSTReturn output;
  output.minimum = minimum;
  output.maximum = maximum;
  output.isBST = isBSTFinal;

  return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MAX, int max = INT_MIN) {
  if (root == NULL)
    return true;

  if (root->data < min or root->data > max)
    return false;

  bool isLeftOk = isBST3(root->left, min, root->data - 1);
  bool isRightOk = isBST3(root->right, root->data, max);

  return isLeftOk and isRightOk;
}

BinaryTreeNode<int> *tree(int input[], int s, int e) {
  if (s > e)
    return NULL;
  int mid = (s + e) / 2;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);

  root->left = tree(input, s, mid - 1);
  root->right = tree(input, mid + 1, e);
  return root;
}
BinaryTreeNode<int> *constructTree(int *input, int n) {
  return tree(input, 0, n - 1);
}

class Pair {
public:
  Node<int> *head;
  Node<int> *tail;
};

Pair BST(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    Pair ans;
    ans.head = NULL;
    ans.tail = NULL;
    return ans;
  }

  Node<int> *node = new Node<int>(root->data);

  Pair leftans = BST(root->left);
  Pair rightans = BST(root->right);

  Pair ans;

  if (leftans.head == NULL && rightans.head == NULL) {

    ans.head = node;
    ans.tail = node;

  }

  else if (!leftans.head && rightans.head) {
    ans.head = node;
    node->next = rightans.head;

    ans.tail = rightans.tail;
  } else if (leftans.head && rightans.head == NULL) {
    ans.head = leftans.head;
    leftans.tail->next = node;
    ans.tail = node;

  } else {
    ans.head = leftans.head;
    leftans.tail->next = node;
    node->next = rightans.head;
    ans.tail = rightans.tail;
  }

  return ans;
}
Node<int> *constructBST(BinaryTreeNode<int> *root) { return BST(root).head; }

vector<int> *getPath(BinaryTreeNode<int> *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == data) {
    vector<int> *output = new vector<int>;
    output->push_back(root->data);
    return output;
  }

  vector<int> *leftOutput = getPath(root->left, data);

  if (leftOutput != NULL) {
    leftOutput->push_back(root->data);
    return leftOutput;
  }

  vector<int> *rightOutput = getPath(root->right, data);
  if (rightOutput != NULL) {
    rightOutput->push_back(root->data);
    return rightOutput;
  } else {
    return NULL;
  }
}

int main() {
  BinaryTreeNode<int> *root = takeInput();
  int k;
  cin >> k;
  cout << ((searchInBST(root, k)) ? "true" : "false");
  delete root;
}

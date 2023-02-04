#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode<int> *takeInput() {
  int rootNode;
  cout << "Enter data" << endl;
  cin >> rootNode;
  TreeNode<int> *root = new TreeNode<int>(rootNode);

  int n;
  cout << "Enter the num of children of " << rootNode << endl;

  cin >> n;
  for (int i = 0; i < n; i++) {
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }

  return root;
}

void printTree(TreeNode<int> *root) {

  if (root == NULL) {
    // Not a base case.
    return;
  }

  cout << root->data << ": ";
  for (int i = 0; i < root->children.size(); i++) {
    cout << root->children[i]->data << ",";
  }
  cout << endl;

  for (int i = 0; i < root->children.size(); i++) {
    printTree(root->children[i]);
  }
}

int main() {
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);
  // TreeNode<int> *node3 = new TreeNode<int>(4);

  // root->children.push_back(node1);
  // root->children.push_back(node2);
  // root->children.push_back(node3);

  TreeNode<int> *root = takeInput();

  printTree(root);
}

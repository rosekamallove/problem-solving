#include "BinaryTreeNode.h"
#include <type_traits>

class BST {
  BinaryTreeNode<int> *root;

public:
  BST() { root = NULL; }
  ~BST() { delete root; }

  void deleteData(int data) {}
  void insert(int data) {

  }

private:
  bool hasData(int data, BinaryTreeNode<int> *node) {
    if (node == NULL)
      return false;
    if (node->data == data)
      return true;

    if (data < node->data)
      return hasData(data, node->left);
    else
      return hasData(data, node->right);
  }

public:
  bool hasData(int data) { return hasData(data, root); }
};

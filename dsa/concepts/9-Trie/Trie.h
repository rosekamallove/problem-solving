#include "TrieNode.h"
#include <string>

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode('\0'); }

  void insertWord(TrieNode *root, std::string word) {
    if (word.size() == 0) {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    insertWord(child, word.substr(1));
  }

  void insertWord(std::string word) { insertWord(root, word); }

  bool search(TrieNode *root, std::string word) {
    if (root->children[word[0] - 'a'] == NULL)
      return false;

    if (word.size() == 1) {
      return root->children[word[0] - 'a']->isTerminal;
    }

    return search(root->children[word[0] - 'a'], word.substr(1));
  }
  bool search(std::string word) { return search(root, word); }

  void removeWord(TrieNode *root, std::string word) {
    if (word.size() == 0) {
      root->isTerminal = true;
      return;
    }

    TrieNode *child;
    int index = word[0] - 'a';
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      return;
    }
    removeWord(root, word.substr(1));
    if (!child->isTerminal) {
      for (int i = 0; i < 26; i++) {
        if (child->children[i] != NULL) {
          return;
        }
      }
      delete child;
      root->children[index] = NULL;
    }
  }
  void removeWord(std::string word) { removeWord(root, word); }
};

#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
  Node (int x) {
    key = x;
    left = right = NULL;
  }
};

void LevelOrderTraversal(Node* root) {
  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();
    cout << temp->key << endl;
    if (temp->left != NULL)
      q.push(temp->left);
    if (temp->right != NULL)
      q.push(temp->right);
  }
}

int main() {
  Node *root = new Node(10);
  root->left = new Node (11);
  root->left->left = new Node(7);
  root->right = new Node(9);
  root->right->left = new Node(15);
  root->right->right = new Node(8);
  LevelOrderTraversal(root);
  return 0;
}

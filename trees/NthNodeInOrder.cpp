#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

void inOrderTraversal(Node *root, int n, int *counter) {
  if (root == NULL)
    return;
  inOrderTraversal(root->left, n, counter);
  cout << root->data << endl;
  (*counter)++;
  if ((*counter)== n) {
    cout << "nthNode " << root->data << endl;
  }
  inOrderTraversal(root->right, n, counter);
}

int main() {
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  int counter = 0;
  int n = 4;

  inOrderTraversal(root, n, &counter);
  return 0;
}

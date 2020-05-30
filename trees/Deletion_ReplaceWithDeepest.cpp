/*
  Given a binary tree, delete a node from it by making sure that tree shrinks
  from the bottom (i.e. the deleted node is replaced by bottom most and rightmost node)
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
  Node (int x) {
    key = x;
    left = right = NULL;
  }
};

void inorder(Node* temp) {
  if(!temp)
    return;
  inorder(temp->left);
  cout << temp->key << " ";
  inorder(temp->right);
}

void deleteDeepest(struct Node* root, struct Node* d_node) {
  // Do level order traversal until last node
  // This is level order traversal
  queue<struct Node*> q;
  q.push(root);
  struct Node* temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if( temp == d_node) {
      temp = NULL;
      delete (d_node);
      return;
    }
    if (temp->left) {
      if(temp->left == d_node) {
        temp->left = NULL;
        delete (d_node);
        return;
      } else q.push(temp->left);
    }
    if (temp->right) {
      if(temp->right == d_node) {
        temp->right = NULL;
        delete (d_node);
        return;
      } else q.push(temp->right);
    }
  }
}

  Node* deletion(struct Node* root, int key) {
    if (root == NULL) return NULL;
    // if no children
    if(root->left == NULL && root->right == NULL) {
      // tree becomes NULL after deletion
      if(root->key == key)
        return NULL;
      // ekse tree remains
      else return root;
    }
    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    struct Node* key_node = NULL;
  // do a level order traversal to find the deepest node (temp)
  // and node to be deleted (key_node)
  while (!q.empty()) {
    temp = q.front();
    q.pop();

    if (temp->key == key) {
      key_node = temp;
    }
    if (temp->left)
      q.push(temp->left);
    if (temp->right)
      q.push(temp->right);
  }

  if (key_node != NULL) {
    int x = temp->key;
    // temp is deepteset node
    deleteDeepest(root, temp);
    // put deepest node's data in key_node
    key_node->key = x;
  }
  return root;
}

int main() {
  struct Node* root = new Node(10);
  root->left = new Node(11);
  root->left->left = new Node(7);
   root->left->right = new Node(12);
   root->right = new Node(9);
   root->right->left = new Node(15);
   root->right->right = new Node(8);
   cout << "Inorder traversal before deletion : ";
    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;

}

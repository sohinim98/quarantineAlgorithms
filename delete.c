#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insertFront(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int key) {
  struct Node* temp = *head_ref, *prev;

  // if head has to be deleted
  if (temp != NULL && temp->data == key) {
    (*head_ref) = temp->next;
    free(temp);
    return;
  }

  while(temp != NULL && temp->data != key) {
    prev = temp;
    temp=temp->next;
  }
  if (temp == NULL) return;

  prev->next = temp->next;
  free(temp);
}

void printList(struct Node *curr) {
  while (curr != NULL) {
    printf("%d \n", curr->data);
    curr = curr->next;
  }
}

int main() {
  struct Node* head = NULL;

  insertFront(&head, 4);
  insertFront(&head, 3);
  insertFront(&head, 2);
  insertFront(&head, 1);
  printList(head);
  deleteNode(&head, 2);
  printf("After deleting 2 - \n");
  printList(head);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void deletList(struct Node **head_ref) {
  struct Node* curr = (*head_ref);
  struct Node* next;
  while(curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  *head_ref = NULL;
}

void insertFront(struct Node **head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void printList(struct Node *curr) {
  while(curr != NULL) {
    printf("%d \n", curr->data);
    curr=curr->next;
  }
  printf("Done printing\n");
}

int main() {
  struct Node* head = NULL;
  insertFront(&head, 1);
  insertFront(&head, 2);
  insertFront(&head, 3);
  insertFront(&head, 4);
  printf("Before deleting\n");
  printList(head);
  deletList(&head);
  printf("After deleting\n");
  printList(head);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

void insertFront(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void printList(struct Node** head_ref) {
  struct Node* curr = (*head_ref);
  while (curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}

bool search(struct Node* head, int keyToFind) {
  struct Node* curr = head;
  while(curr != NULL) {
    if(curr->data == keyToFind) return true;
    curr = curr->next;
  }
  return false;
}

int main() {
  struct Node* head = NULL;
  insertFront(&head, 1);
  insertFront(&head, 2);
  insertFront(&head, 3);
  insertFront(&head, 4);
  printList(&head);
  printf("Find 0\n");
  search(head, 0) ? printf("found\n") : printf("not found\n");
  printf("Find 3\n");
  search(head, 3) ? printf("found\n") : printf("not found\n");
  
  return 0;
}

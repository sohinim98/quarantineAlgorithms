#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

int countLength(struct Node** head_ref) {
  struct Node* curr = (*head_ref);
  int count = 0;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

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

int main() {
  struct Node* head = NULL;
  insertFront(&head, 1);
  insertFront(&head, 2);
  insertFront(&head, 3);
  insertFront(&head, 4);
  printList(&head);
  int count = countLength(&head);
  printf("Length of linked list is %d\n", count);

  return 0;
}

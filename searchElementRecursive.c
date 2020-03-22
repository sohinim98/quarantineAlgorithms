#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

void printList(struct Node* head) {
  struct Node* curr = head;
  while (curr != NULL) {
    printf("%d \n", curr->data);
    curr = curr->next;
  }
}

void insertList(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

bool searchRec(struct Node* head, int keyToFind) {
  if (head == NULL) return false;
  if (head->data == keyToFind) return true;
  return searchRec(head->next, keyToFind);
}

int main() {
  struct Node* head = NULL;
  insertList(&head, 1);
  insertList(&head, 2);
  insertList(&head, 3);
  insertList(&head, 4);
  printList(head);
  printf("Find 0\n");
  searchRec(head, 0) ? printf("found\n") : printf("not found\n");
  printf("Find 3\n");
  searchRec(head, 3) ? printf("found\n") : printf("not found\n");

  return 0;
}

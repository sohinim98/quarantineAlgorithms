#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void insertFront(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int getNth(struct Node* head, int index) {
  int count = 0;
  struct Node* curr = head;
  while (curr != NULL) {
    if (count == index) return curr->data;
    count++;
    curr = curr->next;
  }
  /* if we get to this line, the caller was asking for a non-existent element
  so we assert fail */
  printf("Please enter a positive index.");
  assert(0);
}

int main() {
  struct Node* head = NULL;
  insertFront(&head, 1);
  insertFront(&head, 2);
  insertFront(&head, 3);
  insertFront(&head, 4);
  printList(head);
  printf("Element at index 2 is %d \n", getNth(head, 2));

  return 0;
}

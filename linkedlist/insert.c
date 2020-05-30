#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */

void insertFront(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */

void insertAfter(struct Node* prev_node, int new_data) {
  // first node, therefore no previous node
  if(prev_node == NULL) {
    printf("The previous node cannot be null");
  }
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end  */

void insertEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;

  // first node
  if(*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  struct Node* curr = *head_ref;

  // get last node
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
  return;
}

/* Print linked list on passing the head */
void printList(struct Node* curr) {
  while(curr != NULL) {
    printf(" %d \n", curr->data);
    curr = curr->next;
  }
}

int main() {
  struct Node* head = NULL;

  insertEnd(&head, 4);
  insertFront(&head, 8);
  insertFront(&head, 12);
  insertEnd(&head, 16);
  insertAfter(head->next, 20);
  printList(head);

  return 0;
}

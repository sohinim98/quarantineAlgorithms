#include <stdio.h>
#include <stdlib.h>

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

void printList(struct Node* head) {
  struct Node* curr = head;
  while (curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}

void printNthFromLast (struct Node* head, int n) {
  int len = 0;
  struct Node* curr = head;

  // calc length of linked list
  while (curr != NULL) {
    len++;
    curr = curr->next;
  }
  if (len < n) return;
  curr = head;
  for (int i = 0; i < len - n + 1; i++)
    curr = curr->next;
  printf("%d \n", curr->data);
  return;
}

int main() {
  struct Node* head = NULL;
  insertFront(&head, 1);
  insertFront(&head, 2);
  insertFront(&head, 3);
  insertFront(&head, 4);
  printList(head);
  printNthFromLast(head, 3);

}

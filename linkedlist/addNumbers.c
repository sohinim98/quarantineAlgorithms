/* You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* newNode(int data) {
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insertFront(struct Node** head_ref, int new_data) {
  struct Node *new_node = newNode(new_data);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ->", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

struct Node* addTwoLists (struct Node* first, struct Node* second) {
  struct Node* res = NULL;
  struct Node *temp, *prev = NULL;
  int carry = 0, sum = 0;

  while (first != NULL || second != NULL) {
    sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
    carry = (sum >= 10) ? 1 : 0;
    sum = sum % 10;
    temp = newNode(sum);
    if (res == NULL)
      res = temp;
    else
      prev->next = temp;
    // for next insertion
    prev = temp;
    if (first)
      first = first->next;
    if (second)
      second = second->next;
  }
  if (carry > 0)
    temp->next = newNode(carry);
    return res;
}

int main() {
  // 342 + 465 = 807
  struct Node *first = NULL;
  insertFront(&first, 3);
  insertFront(&first, 4);
  insertFront(&first, 2);

  printf("First list is ");
  printList(first);

  struct Node *second = NULL;
  insertFront(&second, 4);
  insertFront(&second, 6);
  insertFront(&second, 5);

  printf("Second list is ");
  printList(second);

  struct Node *res = NULL;
  res = addTwoLists(first, second);
  printf("Resultant list is ");
  printList(res);

  return 0;
}

#include <stdio.h>

// first print b
// then do b+a

void printFibonacciNumbers(int n) {
  int a = 0, b = 1;
  if (n < 1)
    return;
  for (int i = 1; i <= n; i++) {
    printf("%d ", b);
    int next = a + b;
    a = b;
    b = next;
  }
  printf("\n");

}

int main() {
  printFibonacciNumbers(7);
  return 0;
}

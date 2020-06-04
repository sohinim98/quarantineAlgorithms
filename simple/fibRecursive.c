#include <stdio.h>
// returns nth fibonacci number
int fibonacci(int n) {
  // base case
  if (n <= 1)
    return n;
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int n = 4;
  printf ("%d", fibonacci(n));
  return 0;
}

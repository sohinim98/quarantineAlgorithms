#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n<=1)
    return 1;
  else return n*factorial(n-1);
}
// driver function
int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  int fact = factorial(n);
  printf("fact of %d is %d\n", n, fact);
  return 0;
}

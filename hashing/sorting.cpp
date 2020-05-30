#include <iostream>
using namespace std;
void sortUsingHash(int a[], int n) {
  int max = *std::max_element(a, a + n);
  int *hash = new int[max+1];

  // filling up hash
  // Note - not all of hash[a[i]] is filled
  for(int i=0; i<n;i++) {
    hash[a[i]] += 1;
  }
  // traversing hash
  for (int i=0; i<=max; i++) {
    if (hash[i]) {
      for (int j=0; j<hash[i]; j++) {
        cout << i << " ";
      }
    }
  }
}
// write driver function first to know what you're passing
int main() {
  int a[] = {4, 1, 5, 2};
  int n = sizeof(a)/sizeof(a[0]);
  sortUsingHash(a, n);
}

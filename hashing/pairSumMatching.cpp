/* Given an array of distinct integersm find if there are
2 pairs (a,b) and (c,d) s.t a+b = c+d
if more than one, print any one.
*/
#include <iostream>
#include <map>
using namespace std;

bool pairFound(int arr[], int n) {
  map<int, pair<int, int> > Hash;
  for (int i=0; i < n-1; i++) {
    for (int j=i+1; j<n; j++) {
      int sum = arr[i] + arr[j];
      if (Hash.find(sum) == Hash.end())
        Hash[sum] = make_pair(i,j);
      else {
        pair <int, int> pp = Hash[sum];
        cout << "(" << arr[pp.first] << "," << arr[pp.second] << ") and (" << arr[i] << "," << arr[j] <<")";
        return true;
      }
    }
  }
  cout << "No pairs found.";
  return false;
}

int main () {
  int arr[] = {3, 4, 7, 1, 2, 9, 8};
  int n = sizeof(arr)/sizeof(arr[0]);
  bool pairExists = pairFound(arr, n);
}

#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * Find Pivot Index:
 *
 * - Given an array of numbers
 * - Find the index such that the sum of numbers to left and right are equal
 * - If no such pivot index exists, return -1 
 * - If multiple pivot indices exists, return the leftmost index
 *
 * e.g. 
 *
 * [7, 3, 1, 10, 7 4]
 *
 * pivot_index = 3
 */

int findPivotIndex(int n, int *arr) {
  int res = -1, left = 0, right = 0;

  for (int i = 0; i < n; i++) {
    right += arr[i];
  }

  for (int i = 0; i < n; i++) {
    right -= arr[i];

    if (i != 0) {
      left += arr[i - 1];
    }

    if (left == right) {
      res = i;
      break;
    }
  }

  return res;
}

int main(void) {
  int n;
  cin >> n;

  int arr[n];
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int res = findPivotIndex(n, arr);
  cout << res << endl;

  return 0;
}

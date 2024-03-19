#include <iostream>
using namespace std;
/*
 * Problem Statement:
 *
 * Number of ones in binary:
 *
 * - Given a number x
 * - Return the number of 1s in the binary representation of x
 */

int getNumBinaryOnes(int x) {
  int res = 0;
  while (x) {
    // Use the and bitwise operator 
    // Use 1 to verify if the rightmost bit is 1
    // If it is 1 then it returns 1, otherwise 0
    res += (x & 1);
    // Shift the bits to the right by 1
    // This truncates the rightmost bitwise
    // We've already processed it, so we move to the next bit
    x >>= 1;
  }
  return res;
}

int main(void) {
  int x;
  cin >> x;

  int res = getNumBinaryOnes(x);
  cout << "Number of ones in binary: " << res << endl;
  return 0;

}

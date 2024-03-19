#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * FizzBuzz 
 *  - Output numbers from 1 to x. 
 *  - If the number is divisible by 3, print 'Fizz'
 *  - If the number is divisible by 5, print 'Buzz'
 */

int main(void) {
  int x;
  cin >> x;

  for (int i = 1; i <= x; i++) {
    bool is_div = false;
    if (i % 3 == 0) {
      cout << "Fizz";
      is_div = true;
    } 

    if (i % 5 == 0) {
      cout << "Buzz";
      is_div = true;
    }

    if (!is_div) cout << i;

    cout << endl;
  }

  return 0;
}

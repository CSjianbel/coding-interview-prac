#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * Smallest Change: 
 *
 * - Given an input X
 * - Write a function to determine the minimum number of coins required to make the exact amount of change
 */

// Philippine coin denoms
// Must be sorted in descending order
int ph_coins[] = {20, 10, 5, 1};

int getMinCoins(int x) {
  int res = 0;

  for (int coin : ph_coins) {
    // Add to res the number of coins in x
    res += (x / coin);
    // remove the value of coins added to x
    x %= coin;
  }

  return res;
}

int main(void) {
  int x;
  cin >> x;

  int res = getMinCoins(x);
  cout << "Min coin change: " << res << endl;

  return 0; 
}

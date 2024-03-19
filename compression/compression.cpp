#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * Compression:
 *
 * - Given a string 
 * - Compress the string by taking note of the char and its number of adjacent repetitions
 * e.g.
 *
 * 'a' => a1
 * 'aaa' => a3
 * 'aaabbb' => a3b3
 * 'aaabccc' => a3b1c3
 */
string compress(string a) {
  string res = "";
  char curr = a[0];
  int rep = 0;

  for (int i = 0; i < (int) a.length(); i++) {
    if (curr == a[i]) rep++;
    if (curr != a[i] || i + 1 == (int) a.length()) {
      res += curr;
      res += ('0' + rep);
      rep = 1;
      curr = a[i];
    }
  }

  return res;
}

int main(void) {
  string a;
  cin >> a;

  string res = compress(a);
  cout << res << endl;
  return 0;
}

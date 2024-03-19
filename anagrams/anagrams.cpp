#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * Anagrams:
 *
 * - Given 2 strings
 * - Check if the two strings are anagrams of one another
 * - Assume that all characters are already lowercased
 */
bool anagrams(string a, string b) {
  if (a.length() != b.length()) return false;

  int chars[26] = {-1};

  for (char c : a) {
    int idx = (int) c - 'a';
    if (chars[idx] == -1) chars[idx] = 0;
    chars[idx]++;
  }

  for (char c : b) {
    int idx = (int) c - 'a';
    if (chars[idx] == -1) return false;
    chars[idx]--;
    if (chars[idx] < 0) return false;
  }

  return true;
}

int main(void) {
  string a, b;
  cin >> a >> b;

  if (anagrams(a, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}

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

  int chars[26] = {0};

  for (char c : a) {
    chars[(int) c - 'a']++;
  }

  for (char c : b) {
    chars[(int) c - 'a']--;
  }

  for (int i = 0; i < 26; i++) {
    if (chars[i] != 0)
      return false;
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

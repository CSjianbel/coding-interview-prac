#include <bits/stdc++.h>
using namespace std;


/*
 * Problem Statement: 
 *
 * kthMostFrequentString:
 *
 * - Given a list of strings
 * - And an integer k 
 * - Return the k-th most frequent string in the list of strings
 *
 * Assumptions:
 *
 * - k <= count(unique_words) 
 * - strings are all lowercased
 * - in the event of a tie, print any
 */
string kthMostFrequentString(vector<string>& words, int k) {
  unordered_map<string,int> map;
  for (string word : words) {
    map[word]++;
  }

  set<int> freqs;

  for (auto a : map) {
    freqs.insert(a.second);
  }

  vector<int> unique_freqs(freqs.begin(), freqs.end());
  sort(unique_freqs.begin(), unique_freqs.end());

  int res_freq = unique_freqs[unique_freqs.size() - k];

  string res;
  for (auto a : map) {
    if (a.second == res_freq) {
      res = a.first;
      break;
    }
  }
  
  return res;
}

int main(void) {
  vector<string> words({
      "foo",
      "foo",
      "hello",
      "foo",
      "computer",
      "monitor",
      "hello"
  });

  int k;
  cin >> k;
  string res = kthMostFrequentString(words, k);
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a) {
  unordered_map<int, int> freq;

  for (int i : a) {
    freq[i]++;
    if (freq[i] == 3) {
      return i;
    }
  }

  return -1;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int i = 0; i < size; i++) {
      cin >> a[i];
    }

    cout << solve(a) << endl;
  }

  return 0;
}

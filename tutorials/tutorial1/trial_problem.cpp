#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int n;

  cin >> n;

  vector<pair<int, int>> pairs(n);

  for (int i = 0; i < n; i++) {
    cin >> pairs[i].first >> pairs[i].second;
  }

  for (auto p : pairs) {
    cout << p.first + p.second << endl;
  }

  return 0;
}

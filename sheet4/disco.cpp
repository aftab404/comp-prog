#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;

  ll lens = s.length();
  ll lent = t.length();

  t = t + '#' + s;

  vector<ll> lsp(t.length(), 0);

  ll i = 1, j = 0;

  ll len = t.length();

  while (i < len) {
    if (t[i] == t[j]) {
      lsp[i] = j + 1;
      i++;
      j++;
    } else if (j > 0) {
      j = lsp[j - 1];
    } else {
      lsp[i] = 0;
      i++;
    }
  }

  ll res = lens + lent - lsp.back();
  cout << res << endl;

  return 0;
}

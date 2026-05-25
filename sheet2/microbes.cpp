#include <bits/stdc++.h>
#include <cmath>
using namespace std;

using ll = long long;

int main() {
  int n;
  int q;
  cin >> n >> q;

  int s = ceil(sqrt(n));
  vector<ll> colonies;
  vector<ll> decomp;
  vector<tuple<char, int, int>> queries;

  int pack_flag = 0;
  ll count = 0;
  while (n--) {
    ll colony;
    cin >> colony;
    colonies.push_back(colony);
    pack_flag++;
    if (colony % 2 != 0)
      count++;
    if (pack_flag == s) {
      decomp.push_back(count);
      pack_flag = 0;
      count = 0;
    }
  }
  decomp.push_back(count);

  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    queries.emplace_back(op, a - 1, b - 1);
  }

  for (auto [op, a, b] : queries) {
    if (op == 'Q') {
      ll res = 0;
      while (a <= b && a % s != 0) {
        if (colonies[a++] % 2 != 0)
          res++;
      }
      while (a + s < b) {
        res += decomp[a / s];
        a += s;
      }
      while (a <= b) {
        if (colonies[a++] % 2 != 0)
          res++;
      }
      cout << res << endl;
    }

    else {
      if (colonies[a] % 2 != 0)
        decomp[a / s]--;
      colonies[a] = b + 1;
      if (colonies[a] % 2 != 0)
        decomp[a / s]++;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<ll, ll>> deals;

  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (a >= b)
      continue;
    else
      deals.push_back({a, b});
  }

  ll borrowed = 0;
  ll in_hand = 0;

  sort(deals.begin(), deals.end(),
       [](pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; });

  for (auto deal : deals) {
    if (in_hand < deal.first) {
      while (in_hand < deal.first) {
        borrowed++;
        in_hand++;
      }
    }
    in_hand -= deal.first;
    in_hand += deal.second;
  }

  cout << borrowed << " " << in_hand - borrowed << endl;

  return 0;
}

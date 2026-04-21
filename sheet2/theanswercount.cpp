#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  int x;

  cin >> n >> x;

  vector<ll> a1;
  vector<ll> a2;

  for (int i = 0; i <= n / 2; i++) {
    ll in;
    cin >> in;
    a1.push_back(in);
  }

  for (int i = n / 2 + 1; i < n; i++) {
    ll in;
    cin >> in;
    a2.push_back(in);
  }

  vector<ll> s1;
  vector<ll> s2;

  return 0;
}

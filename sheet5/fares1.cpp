#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;

const ll MAX_N = 100005;

int main() {
  ll n, b, m, t;
  cin >> n >> b >> m >> t;

  vector<vector<pair<ll, ll>>> graph(MAX_N);
  vector<ll> dist(MAX_N, LLONG_MAX);

  while (b--) {
    ll a, c, d;
    cin >> a >> c >> d;
    graph[a].push_back({c, d});
    graph[c].push_back({a, d});
  }
  while (m--) {
    ll a, c, d;
    cin >> a >> c >> d;
  }

  dist[1] = 0;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto front = pq.top();
    pq.pop();

    ll d = front.first;
    ll v = front.second;

    if (d > dist[v]) {
      continue;
    }
    for (auto p : graph[v]) {
      int u = p.first;
      int w = p.second;
      if (dist[v] + w < dist[u]) {
        dist[u] = dist[v] + w;
        pq.push({dist[u], u});
      }
    }
  }

  cout << dist[n] << endl;

  return 0;
}

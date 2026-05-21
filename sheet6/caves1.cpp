#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<ll> gold;
vector<ll> max_gold;
vector<bool> visited;
deque<int> ts;

void dfs(int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v])
      dfs(v);
  }
  ts.push_front(u);
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.assign(n + 1, {});
  gold.assign(n + 1, 0);
  visited.assign(n + 1, false);
  max_gold.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> gold[i];
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i])
      dfs(i);
  }

  for (int u : ts) {
    max_gold[u] = max(max_gold[u], gold[u]);
    for (int v : adj[u]) {
      max_gold[v] = max(max_gold[v], max_gold[u] + gold[v]);
    }
  }

  ll res = 0;

  for (int i = 1; i <= adj.size(); i++) {
    if (adj[i].size() == 0)
      res = max(res, max_gold[i]);
  }

  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> indegree;
deque<int> cycle;

vector<vector<int>> adj;

void find_cycle(int u) {
  while (adj[u].size() > 0) {
    int v = adj[u].back();
    adj[u].pop_back();
    find_cycle(v);
  }
  cycle.push_front(u);
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.assign(n + 1, vector<int>());
  indegree.assign(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    indegree[b]++;
  }

  if (indegree[1] != adj[1].size() - 1) {
    cout << "impossible" << endl;
    return 0;
  }

  if (indegree[n] != adj[n].size() + 1) {
    cout << "impossible" << endl;
    return 0;
  }

  for (int i = 2; i < n; i++) {
    if (indegree[i] != adj[i].size()) {
      cout << "impossible" << endl;
      return 0;
    }
  }

  find_cycle(1);

  if (cycle.size() != m + 1) {
    cout << "impossible" << endl;
    return 0;
  }

  cout << "possible" << endl;

  return 0;
}

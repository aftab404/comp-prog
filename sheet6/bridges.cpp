#include <bits/stdc++.h>
using namespace std;

int dfs_counter = 0;
const int UNVISITED = -1;
int bridges = 0;
int dfsRoot, rootChildren;

vector<int> dfs_num, dfs_min, dfs_parent;
vector<vector<int>> adj;

void dfs(int u) {
  dfs_min[u] = dfs_num[u] = dfs_counter++;
  for (auto v : adj[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      if (u == dfsRoot)
        rootChildren++;
      dfs(v);
      if (dfs_min[v] > dfs_num[u]) {
        bridges++;
      }
      dfs_min[u] = min(dfs_min[u], dfs_min[v]);
    } else if (v != dfs_parent[u]) {
      dfs_min[u] = min(dfs_min[u], dfs_num[v]);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.assign(n + 1, vector<int>());
  dfs_num.assign(n + 1, UNVISITED);
  dfs_min.assign(n + 1, UNVISITED);
  dfs_parent.assign(n + 1, -1);

  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (dfs_num[i] == UNVISITED) {
      dfsRoot = i;
      rootChildren = 0;
      dfs(i);
    }
  }

  cout << bridges << endl;

  return 0;
}

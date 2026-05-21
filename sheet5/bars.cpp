#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<vector<int>> graph(n + 1);

  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  queue<int> q;

  q.push(s);

  int pubs = 1;
  int depth = 0;

  vector<bool> visited(n + 1, false);
  visited[s] = true;

  while (!q.empty()) {
    if (depth == d) {
      break;
    }

    int size = q.size();

    for (int i = 0; i < size; i++) {
      int curr = q.front();
      q.pop();
      for (int neighbor : graph[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
          pubs++;
        }
      }
    }

    depth++;
  }

  cout << pubs << endl;
  return 0;
}

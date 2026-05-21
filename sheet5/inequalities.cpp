#include <bits/stdc++.h>
using namespace std;

map<string, bool> visited;
map<string, vector<string>> graph;
deque<string> order;
map<string, int> state;

void dfs(string node) {
  visited[node] = true;
  for (string neighbor : graph[node]) {
    if (!visited[neighbor]) {
      state[node] = 1;
      dfs(neighbor);
    }
    if (state[neighbor] == 1) {
      cout << "impossible" << endl;
      exit(0);
    }
  }
  order.push_front(node);
  state[node] = 2;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string a, o, b;
    cin >> a >> o >> b;
    if (o == ">") {
      graph[a].push_back(b);
    } else {
      graph[b].push_back(a);
    }
  }

  for (auto pair : graph) {
    if (!visited[pair.first]) {
      dfs(pair.first);
    }
  }

  cout << "possible" << endl;
  for (string node : order) {
    cout << node << " ";
  }

  return 0;
}

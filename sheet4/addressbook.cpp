#include <bits/stdc++.h>
using namespace std;

struct trie {
  bool inEndOfString = false;
  int count = 0;
  map<char, trie *> edges;
  void insert(const string &s, int i = 0);
  bool contains(const string &s, int i = 0);
  int find_suffix(const string &s, int i = 0);
};

void trie::insert(const string &s, int i) {
  if (i == s.size()) {
    inEndOfString = true;
    count++;
    return;
  }
  if (edges.find(s[i]) == edges.end()) {
    edges[s[i]] = new trie();
  }
  count++;
  edges[s[i]]->insert(s, i + 1);
}

bool trie::contains(const string &s, int i) {
  if (i == s.length())
    return inEndOfString;
  return edges.count(s[i]) > 0 && edges[s[i]]->contains(s, i + 1);
}

int trie::find_suffix(const string &s, int i) {
  if (i == s.size())
    return count;
  if (edges.count(s[i]) == 0)
    return 0;
  return edges[s[i]]->find_suffix(s, i + 1);
}

int main() {

  int n;
  cin >> n;

  vector<pair<string, string>> queries;

  trie t;

  while (n--) {
    string op, name;
    cin >> op >> name;
    pair<string, string> p = {op, name};
    queries.push_back(p);
  }

  for (auto &p : queries) {
    if (p.first == "add") {
      t.insert(p.second);
    } else {
      cout << t.find_suffix(p.second) << endl;
    }
  }

  return 0;
}

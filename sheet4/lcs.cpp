#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
  for (int i = 0; i <= s.length(); ++i)
    dp[i][0] = i;
  for (int j = 0; j <= t.length(); ++j)
    dp[0][j] = j;
  for (int i = 1; i <= s.length(); ++i) {
    for (int j = 1; j <= t.length(); ++j) {
      dp[i][j] = min({dp[i - 1][j - 1] + 2 * (s[i - 1] != t[j - 1]),
                      dp[i - 1][j] + 1, dp[i][j - 1] + 1});
    }
  }

  int ed = dp[s.length()][t.length()];

  int res = -(ed - s.length() - t.length()) / 2;
  cout << res << endl;

  return 0;
}

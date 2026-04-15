#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> res(n + 1, 0);
  vector<int> prefix_sum(n + 1, 0);

  for (int i = 1; i < n; i++) {
    cout << "?" << " " << 1 << " " << i + 1 << endl;
    fflush(stdout);
    cin >> prefix_sum[i + 1];
  }

  int sum_excluding_first;
  cout << "?" << " " << 2 << " " << n << endl;
  fflush(stdout);
  cin >> sum_excluding_first;

  prefix_sum[1] = prefix_sum[n] - sum_excluding_first;

  for (int i = 1; i <= n; i++) {
    res[i] = prefix_sum[i] - prefix_sum[i - 1];
  }

  string final_res = "! ";
  for (int i = 1; i <= n; i++) {
    final_res += to_string(res[i]) + " ";
  }

  cout << final_res << endl;
  return 0;
}

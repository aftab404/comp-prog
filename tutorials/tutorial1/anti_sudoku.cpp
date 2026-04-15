#include <bits/stdc++.h>

using namespace std;

void solve(vector<string> &given) {
  vector<string> res;
  int shift = 0;
  int count = 0;
  for (string row : given) {
    if (row[shift + count * 3] == '1')
      row[shift + count * 3] = '2';
    else
      row[shift + count * 3] = '1';
    res.push_back(row);
    count++;
    if (count % 3 == 0) {
      count = count % 3;
      shift++;
    }
  }

  for (int i = 0; i < 9; i++) {
    cout << res[i] << endl;
  }
}

int main() {
  int n;

  cin >> n;
  while (n--) {
    vector<string> given(9);

    for (int i = 0; i < 9; i++) {
      cin >> given[i];
    }

    solve(given);
  }
  return 0;
}

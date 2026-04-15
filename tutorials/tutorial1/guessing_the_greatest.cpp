#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int l = 1;
  int r = n;

  int global_second_max = 0;
  cout << "? " << l << " " << r;
  fflush(stdout);

  cin >> global_second_max;

  int maxl = 0;
  cout << "? " << l << " " << global_second_max;
  fflush(stdout);
  cin >> maxl;
  if (maxl == global_second_max) {
    r = global_second_max;
    while (l < r) {
      int m = l + (r - l) / 2;

      int sub_max = 0;
      cout << "? " << m << " " << r;
      fflush(stdout);
      cin >> sub_max;

      if (sub_max == global_second_max) {
        l = m;
      } else {
        m = (m - l) / 2;
      }
    }

  } else {
    l = global_second_max;
    while (l < r) {
      int m = l + (r - l) / 2;

      int sub_max = 0;
      cout << "? " << l << " " << m;
      fflush(stdout);
      cin >> sub_max;

      if (sub_max == global_second_max) {
        r = m;
      } else {
        m = (r - m) / 2;
      }
    }
  }

  cout << "! " << l << endl;

  return 0;
}

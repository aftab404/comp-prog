#include <bits/stdc++.h>
#include <string>

using namespace std;

bool divisible(string &in) {
  int evens = 0;
  int zeroes = 0;
  bool div4 = false;
  bool div3 = false;

  int n = in.size();

  int sum = 0;
  for (char c : in) {
    int curr = c - '0';
    if (curr % 2 == 0)
      evens++;
    if (curr == 0)
      zeroes++;
    sum += curr;
  }

  for (int i = 0; i < n; i++) {
    string num = "";
    num += in[i];
    num += '0';
    if (stoi(num) % 4 == 0)
      div4 = true;
  }

  if (sum % 3 == 0)
    div3 = true;

  return evens >= 2 && div4 && div3 && zeroes > 0;
}

int main() {
  int n;
  cin >> n;

  vector<string> in(n);

  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }

  for (string s : in) {
    if (divisible(s))
      cout << "red" << endl;
    else
      cout << "cyan" << endl;
  }
}

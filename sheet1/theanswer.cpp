#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < n - 2; i++) {
		int l = i + 1;
		int r = n - 1;

		while (l < r) {
			ll sum = a[i] + a[l] + a[r];
			if (sum == 42) {
				cout << a[i] << " " << a[l] << " " << a[r] << endl;
				return 0;
			}
			else if (sum < 42) {
				l++;
			}
			else {
				r--;
			}
		}

	}

	cout << "impossible" << endl;

	return 0;
}

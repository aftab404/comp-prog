#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}
		vector<int> b = a;
		sort(b.begin(), b.end());
		int count = 0;
		vector<int> res;

		for(int i = 0; i < n; i++){
			if (count > 2) {
				cout << "impossible" << endl;
				return 0;
			}
			if (a[i] != b[i]){
				count++;
				res.push_back(i+1);
			}
		}

		cout << res[0] << " " << res[1] << endl;
		return 0;
}



#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
using namespace std;
using ll = long long;

int main() {
  int n;
  int x;

  cin >> n >> x;

  vector<ll> a1;
  vector<ll> a2;

  for (int i = 0; i < n / 2; i++) {
    ll in;
    cin >> in;
    a1.push_back(in);
  }

  for (int i = n / 2 ; i < n; i++) {
    ll in;
    cin >> in;
    a2.push_back(in);
  }

  vector<ll> s1;
  vector<ll> s2;

	for(int i = 0; i<pow(2,a1.size()); i++){
			ll sum = 0;
			for(int j = 0; j < a1.size(); j++){
				if(i & (1 << j)) sum += a1[j];
			}
			s1.push_back(sum);
	}

	for(int i = 0; i<pow(2,a2.size()); i++){
			ll sum = 0;
			for(int j = 0; j < a2.size(); j++){
				if(i & (1 << j)) sum += a2[j];
			}
			s2.push_back(sum);
	}

	ll count = 0;

	sort(s2.begin(), s2.end());

	for(ll num1: s1){
		auto rng = equal_range(s2.begin(), s2.end(), x - num1);
		count += distance(rng.first, rng.second);
	}

	cout << count << endl;

  return 0;
}

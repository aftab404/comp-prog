#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	vector<vector<int>> data;

	for(int i = 0; i < 11; i++){
		vector<int> person(11);
		for(int j = 0; j < 11; j++){
			cin >> person[j];
		}
		data.push_back(person);
	}

	vector<int> selections = {0,1,2,3,4,5,6,7,8,9,10};

	int res = 0;

	do {
		int local_res = 0;
		for(int i = 0; i < 11 ; i++){
			local_res += data[i][selections[i]];
		}
		res = max(res,local_res);
	} while (next_permutation(selections.begin(), selections.end()));

	cout << res << endl;

	return 0;

}

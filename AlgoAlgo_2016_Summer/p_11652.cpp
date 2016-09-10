#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
vector<long long> v;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int mi = 0;
	long long result = v[0];
	int cnt = 1;
	int i = 1;
	for (; i < v.size(); i++) {
		if (v[mi] == v[i])	 cnt += 1;
		else
			break;
	}
	while (i < v.size()) {
		int tc = 1;
		int ti = i;
		long long tr = v[i];
		i += 1;
		for (; i < v.size(); i++) {
			if (v[ti] == v[i])	 tc += 1;
			else
				break;
		}
		if (cnt < tc) {
			mi = ti;
			cnt = tc;
			result = tr;
		}
	}

	cout << result << "\n";
	return 0;
}
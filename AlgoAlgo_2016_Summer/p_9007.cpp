#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

int k, n;
bool fun(int a, int b) {
	if (abs(k - a) == abs(k - b))
		return a < b;
	return abs(k - a) < abs(k - b);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int ret = 987654321;
		vector<int> a[4];
		vector<int> b[2];
		cin >> k >> n;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < n; ++j) {
				int t;
				cin >> t;
				a[i].push_back(t);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[0].push_back(a[0][i] + a[1][j]);
				b[1].push_back(a[2][i] + a[3][j]);
			}
		}

		sort(b[1].begin(), b[1].end());

		for (int i = 0; i < b[0].size(); i++) {
			int sum = b[0][i];
			auto p = lower_bound(b[1].begin(), b[1].end(), k - b[0][i]);
			if (p == b[1].end()) {
				--p;
				sum = sum + *p;
				if (fun(sum, ret))
					ret = sum;
			}
			else {
				if (*p + sum == k) {
					ret = k;
					break;
				}
				else {
					if (p == b[1].begin())
						sum = sum + *p;
					else if (fun(sum + *(p), sum + *(p - 1)))
						sum = sum + *(p);
					else
						sum = sum + *(p - 1);

					if (fun(sum, ret))
						ret = sum;
				}
			}
		}
		cout << ret << "\n";

		for (int j = 0; j < 4; ++j)
			a[j].clear();
		for (int j = 0; j < 2; ++j)
			b[j].clear();
	}
	return 0;
}
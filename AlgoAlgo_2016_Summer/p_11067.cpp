#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
vector<int> v[100001];
vector<pair<int, int> > r;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		int pre = 0;
		for (int i = 0; i < 100001; i++) {
			if (v[i].size() > 0) {

				sort(v[i].begin(), v[i].end());

				if (v[i][0] < pre) {
					for (int j = v[i].size() - 1; j >= 0; j--)
						r.push_back(make_pair(i, v[i][j]));
					pre = v[i][0];
				}
				else {
					for (int j = 0; j < v[i].size(); j++)
						r.push_back(make_pair(i, v[i][j]));
					pre = v[i][v[i].size() - 1];
				}
			}
		}
		int m;
		cin >> m;
		while (m--) {
			int num;
			cin >> num;
			num -= 1;
			cout << r[num].first << " " << r[num].second << "\n";
		}

		for (int i = 0; i < 100001; i++) {
			v[i].clear();
			r.clear();
		}
	}
	return 0;
}
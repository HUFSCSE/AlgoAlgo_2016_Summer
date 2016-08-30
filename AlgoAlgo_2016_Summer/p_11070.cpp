#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
pair<int, int> team[1001];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n,m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			team[a].first += c;
			team[a].second += d;
			team[b].first += d;
			team[b].second += c;
		}
		double _max = -1;
		double _min = 100000000;
		for (int i = 1; i <= n; i++) {
			double top = team[i].first*team[i].first;
			double bottom = team[i].first*team[i].first + team[i].second*team[i].second;
			double t = 0;
			if (bottom != 0)
				t = top / bottom;
			_max = max(_max, t);
			_min = min(_min, t);
		}
		cout << (int)(_max * 1000) << "\n";
		cout << (int)(_min * 1000) << "\n";
		for (int i = 1; i <= n; i++)
				team[i] = make_pair(0, 0);
	}
	return 0;
}
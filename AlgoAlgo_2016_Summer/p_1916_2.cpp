#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int, int> > map[1001]; //점,가중치
int dist[1001];
int n, m, a, b;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)dist[i] = 987654321;
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x].push_back(make_pair(y, z));
	}
	cin >> a >> b;
	priority_queue<pair<int, int> > x;//가중치,점
	x.push(make_pair(0, a));
	dist[a] = 0;
	while (!x.empty()) {
		int u = x.top().second;
		x.pop();
		for (int i = 0; i<map[u].size(); ++i) {
			int v = map[u][i].first;

			int cost = map[u][i].second;
			if (dist[v]>dist[u] + cost) {
				dist[v] = dist[u] + cost;
				x.push(make_pair(-dist[v], v));
			}

		}
	}
	cout << dist[b];
	return 0;
}
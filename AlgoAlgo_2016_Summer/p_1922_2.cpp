#include<iostream>	
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int a[1001][1001];
bool check[1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = z;
		a[y][x] = z;
	}
	int sum = 0;
	priority_queue<pair<int, int> > q;
	check[1] = true;
	for (int i = 1; i <= n; i++) {
		if (a[1][i] != 0)
			q.push(make_pair(-a[1][i], i));
	}
	while (!q.empty()) {
		pair<int, int> next = q.top();
		q.pop();
		if (check[next.second] == false) {
			//cout << next.second << " ";
			check[next.second] = true;
			sum += -next.first;
			for (int i = 1; i <= n; i++) {
				if (a[next.second][i] != 0 && check[i] == false)
					q.push(make_pair(-a[next.second][i], i));
			}
		}
	}
	cout << sum << endl;

	return 0;
}
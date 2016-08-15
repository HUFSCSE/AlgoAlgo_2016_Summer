#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[1001][1001];
bool check[1001];
long long d[1001];
int main() {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			arr[i][j] = 100000000;
	for (int i = 0; i < 1001; i++)
		d[i] = 100000000;
	int n, m, s, e;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b,c;
		cin >> a >> b>>c;
		arr[a][b] = min(arr[a][b],c);
	}
	cin >> s >> e;

	d[s] = 0;
	int _min, v;
	for (int i = 1; i <= n; i++) {
		_min = 100000001;
		v = 0;
		for (int j = 1; j <= n; j++)
			if (check[j] == 0 && _min > d[j]) {
				_min = d[j];
				v = j;
			}
		check[v] = true;
		for (int j = 1; j <= n; j++) {
			if (d[j] > d[v] + arr[v][j])
				d[j] = d[v] + arr[v][j];
		}
	}
	cout << d[e] << "\n";
	return 0;
}
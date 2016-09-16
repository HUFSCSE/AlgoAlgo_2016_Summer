#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define cu (1<<n)
#define rt (1<<(n-1))
#define dn (1)
#define M (1<<(n+1))
int p[4][4] = {
	{ 100,70,40,0 },
	{ 70,50,30,0 },
	{ 40,30,20,0 },
	{ 0,0,0,0 }
};
int n, tb[12][12], m[12][12][1 << 13];
int f(int x, int y, int s) {
	if (x == n) return 0;
	if (y == n) return f(x + 1, 0, s);
	if (m[x][y][s])
		return m[x][y][s];
	if (!(s&cu)) {
		if (y + 1 < n && !(s&rt)) {
			m[x][y][s] = max(m[x][y][s], f(x, y + 2, (s << 2)%M)+p[tb[x][y]][tb[x][y + 1]]);
		}
		if (x + 1 < n && !(s&dn)) {
			m[x][y][s] = max(m[x][y][s], f(x, y + 1, ((s|dn) << 1)%M)+p[tb[x][y]][tb[x+1][y]]);
		}
		m[x][y][s] = max(m[x][y][s], f(x, y + 1, (s << 1) % M));
	}
	else
		m[x][y][s] = max(m[x][y][s], f(x, y + 1, (s << 1) % M));
	return m[x][y][s];
}
int main() {
	//O(2^n * n^2)
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			tb[i][j] = (s[j] == 'F' ? 3 : s[j] - 'A');
		}
	}
	cout << f(0,0,0) << "\n";
	return 0;
}
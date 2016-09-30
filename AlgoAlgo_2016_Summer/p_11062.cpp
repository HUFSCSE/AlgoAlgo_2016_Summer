#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<map>
using namespace std;

int L[1001];
int a;
int dp[1001][1001][2];
int fun(int p, int q, int r) {
	if (p > q) return 0;
	int &ret = dp[p][q][r];
	if (ret != -1)return ret;
	if (r) ret = max(fun(p + 1, q, 0) + L[p], fun(p, q - 1, 0) + L[q]);
	else if (!r)ret = min(fun(p + 1, q, 1), fun(p, q - 1, 1));
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int ret;
		memset(dp, -1, sizeof(dp));
		cin >> a;
		for (int i = 1; i <= a; ++i) cin >> L[i];
		cout << fun(1, a, 1) << "\n";
	}
	return 0;  
}
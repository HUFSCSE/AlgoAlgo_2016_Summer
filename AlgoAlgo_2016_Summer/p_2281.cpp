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
#include <string.h>
#include <set>
using namespace std;
const int INF = 987654321;
int arr[1001];
int dp[1111][1111];
int n, m;
int f(int i,int start) {
	if (i >= n + 1) return 0;
	int &ret = dp[i][start];
	if (ret != -1) return ret;
	ret = INF;
	if (start - 1 + arr[i] <= m)
		ret = min(ret, f(i + 1, start + arr[i] + 1));
	ret = min(ret, (m - start + 2)*(m - start + 2) + f(i, 1));
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << f(1, 1) << endl;
	return 0;
}
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
int n;
int arr[50001];
int k;
int dp[50001][3];
int sum[50001];
int f(int i, int selected) {
	if (selected == 3) return 0;
	if (i >= n + 1) return 0;
	int &ret = dp[i][selected];
	if (ret != -1) return ret;
	ret = 0;
	if (i + k - 1 <= n)
		ret = max(ret, sum[i + k - 1] - sum[i - 1] + f(i + k, selected + 1));
	ret = max(ret, f(i + 1, selected));
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> k;
	cout << f(1, 0);
	return 0;
}
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
int r[100][301];
int dp[100][301];
int t[100][301];
int arr[100];
void f(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp = -1;
			int kk = -1;
			for (int k = 0; k <= j; k++) {
				if (temp < dp[i - 1][k] + r[i][j - k]) {
					temp = max(temp, dp[i - 1][k] + r[i][j - k]);
					kk = j - k;
				}
			}
			dp[i][j] = temp;
			t[i][j] = kk;
		}
	}
}
int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < n; j++)
			cin >> r[j][t];
	}
	f(n - 1, m);
	cout << dp[n - 1][m] << endl;

	int tx = m;
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = t[i][tx];
		tx -= arr[i];
	}
	for (int j = 0; j < n; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}
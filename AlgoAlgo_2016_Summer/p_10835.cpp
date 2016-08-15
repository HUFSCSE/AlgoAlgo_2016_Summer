#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int a[2000];
int b[2000];
int dp[2002][2002];
int n;
int go(int i, int j) {
	if (i == n || j == n) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i] > b[j]) return dp[i][j] = b[j] + go(i, j + 1);
	return dp[i][j] = max(go(i + 1, j + 1), go(i + 1, j));
}
int main() {
	for (int i = 0; i < 2002; i++)
		for (int j = 0; j < 2002; j++)
			dp[i][j] = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << go(0, 0) << endl;
	return 0;
}
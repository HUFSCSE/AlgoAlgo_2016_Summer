#include<iostream>
#include<algorithm>
using namespace std;
int MIN = -100000000;
int input[301];
int dp[301][3];
int f(int n, int b) {
	if (n == 0) return 0;
	if (n < 0 || b >= 3) return MIN;
	if (dp[n][b] != 0) return dp[n][b];
	return dp[n][b] = max( f(n-1,b+1) , f(n-2,1)    )+input[n];
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d",&input[i]);
	cout << f(n,1) << "\n";
	return 0;
}

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
int arr[501];
int _sum[501][501];
int s[501];
int n;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(s, 0, sizeof(s));
		memset(_sum, 0, sizeof(_sum));

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			s[i] = s[i - 1] + arr[i];
		}
		for (int i = 1, j = 2; i < n && j <= n; i++, j++)
			_sum[i][j] = arr[i] + arr[j];
		for (int t = 3; t <= n; t++) {
			for (int i = 1, j = t; i < n && j <= n; i++, j++) {
				int m = 987654321;
				for (int k = i; k < j; k++) {
					m = min(m, _sum[i][k] + _sum[k + 1][j] + s[j] - s[i - 1]);
				}
				_sum[i][j] = m;
			}
		}
		printf("%d\n", _sum[1][n]);
	}
	return 0;
}
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
int n, k, i, j, x, y, w, h, X, Y;
int paper[1005][1005], area[105];
int main() {
	scanf("%d", &n);

	for (k = 1; k <= n; k++) {
		scanf("%d %d %d %d", &x, &y, &w, &h);
		X = x + w; Y = y + h;

		for (i = x; i<X; i++)
			for (j = y; j<Y; j++)
				paper[i][j] = k;
	}

	for (i = 0; i <= 1000; i++)
		for (j = 0; j <= 1000; j++)
			area[paper[i][j]]++;

	for (k = 1; k <= n; k++)
		printf("%d\n", area[k]);
	return 0;
}
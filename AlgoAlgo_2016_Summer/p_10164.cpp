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
int n, m, k;
int path(int y, int x) {
	int i, j;
	int a[22][22];
	for (i = 1; i <= y; i++)
		for (j = 1; j <= x; j++)
			a[i][j] = 0;
	a[1][1] = 1;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			a[i][j + 1] += a[i][j];
			a[i + 1][j] += a[i][j];
		}
	}
	return a[y][x];
}
void process(void)
{
	int x, y;
	if (k == 0)
		printf( "%d\n", path(n, m));
	else {
		x = (k - 1) % m + 1;
		y = (k - 1) / m + 1;
		printf("%d\n", path(x, y)*path(m - x + 1, n - y + 1));
	}
}
int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	process();
	return 0;
}
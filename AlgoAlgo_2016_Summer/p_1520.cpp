#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int n, m;
int maze[502][502];
int d[502][502];
int go(int i, int j) {
	if (i == n && j == m)
		return 1;
	if (d[i][j] != -1)
		return d[i][j];
	int a=0, b=0, c=0, dd=0;
	int tx, ty;
	tx = i-1;
	ty = j;
	if (i > 0 && maze[tx][ty] < maze[i][j])
		a = go(i - 1, j);
	tx = i+1;
	ty = j;
	if (i <= n && maze[tx][ty] < maze[i][j])
		b = go(i + 1, j);
	tx = i;
	ty = j-1;
	if (j > 0 && maze[tx][ty] < maze[i][j])
		c = go(i , j-1);
	tx = i;
	ty = j+1;
	if (j <= m && maze[tx][ty] < maze[i][j])
		dd = go(i , j +1);
	return d[i][j] = a + b + c + dd;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];
	cout << go(1, 1) << endl;
	return 0;
}
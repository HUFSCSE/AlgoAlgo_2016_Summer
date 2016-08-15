#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int maze[1002][1002];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			maze[i][j] = maze[i][j] + max(maze[i - 1][j], maze[i][j - 1]);
	cout << maze[n][m] << endl;
	return 0;
}
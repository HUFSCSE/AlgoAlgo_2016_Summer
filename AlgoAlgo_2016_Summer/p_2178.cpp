#include<iostream>	
#include<queue>	
using namespace std;
struct Point {
	int x;
	int y;
	int count;
};
int maze[102][102];
bool check[102][102];
int tx[4] = {1, -1, 0, 0 }; //го ╩С ©Л аб
int ty[4] = {0, 0, 1, -1 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d",&maze[i][j]);
	queue<Point> q;
	q.push(Point{ 1, 1,1 });
	while (!q.empty()) {
		Point p = q.front();
		q.pop();
		if (maze[p.x][p.y] != 0 &&
			check[p.x][p.y] == false) {
			check[p.x][p.y] = true;
			if (p.x == n && p.y == m) {
				cout << p.count << endl;
				return 0;
			}
			for (int i = 0; i < 4;i++)
				q.push(Point{p.x+tx[i],p.y+ty[i],p.count+1});
		}
	}
	return 0;
}
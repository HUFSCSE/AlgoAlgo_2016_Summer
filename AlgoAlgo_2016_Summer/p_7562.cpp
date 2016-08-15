#include<iostream>	
#include<queue>	
using namespace std;
struct Point {
	int x;
	int y;
	int count;
};
bool check[302][302];
int tx[8] = { -1,-2,-2,-1,1,2,2,1 }; 
int ty[8] = { -2,-1,1,2,-2,-1,1,2 };
int main() {
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		int stx, sty;
		int edx, edy;
		cin >> stx >> sty;
		cin>> edx >> edy;
		queue<Point> q;
		q.push(Point{ stx, sty,0 });
		while (!q.empty()) {
			Point p = q.front();
			q.pop();
			if (p.x >= 0 && p.y >= 0 && p.x<m && p.y<m) {
				if ( check[p.x][p.y] == false) {
					check[p.x][p.y] = true;
					if (p.x == edx && p.y == edy) {
						cout << p.count << endl;
					}
					else {
						for (int i = 0; i < 8; i++)
							q.push(Point{ p.x + tx[i],p.y + ty[i],p.count + 1 });
					}
				}
			}
		}
		for (int i = 0; i < 302; i++) 
			for (int j = 0; j < 302; j++) 
				check[i][j] = 0;
	}
	return 0;
}
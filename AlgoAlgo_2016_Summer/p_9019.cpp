#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int a[10000];
char path[10000];
int check[10000];
int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		queue<int> q;
		q.push(n);
		check[n] = true;
		while (!q.empty()) {
			int now = q.front();
			int next;
			q.pop();
			//2*now
			next = (2 * now) % 10000;
			if (check[next] == false) {
				q.push(next);
				a[next] = now;
				check[next] = true;
				path[next] = 'D';
			}
			//now -1
			next = now - 1;
			if (next < 0)
				next = 9999;
			if (check[next] == false) {
				q.push(next);
				a[next] = now;
				check[next] = true;
				path[next] = 'S';
			}
			//now ROT L
			next = (now % 1000) * 10 + now / 1000;
			if (check[next] == false) {
				q.push(next);
				a[next] = now;
				check[next] = true;
				path[next] = 'L';
			}
			//now ROT R
			next = (now / 10) + (now % 10) * 1000;
			if (check[next] == false) {
				q.push(next);
				a[next] = now;
				check[next] = true;
				path[next] = 'R';
			}
		}
		string r = "";
		while (m != n) {
			r += path[m];
			m = a[m];
		}
		reverse(r.begin(), r.end());
		cout << r << "\n";
		for (int i = 0; i < 10000; i++) {
			a[i] = 0;
			path[i] = 0;
			check[i] = 0;
		}
	}
	return 0;
}
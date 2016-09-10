#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
struct Store {
	long long x, y;
	Store() {	}
	Store(long long tx, long long ty) { x = tx, y = ty; }
	Store operator-(const Store& B) { return Store(x - B.x, y - B.y); }
} p[200001], piv;
long long dist(Store p1, Store p2) {
	long long d1 = (long long)(p1.x - p2.x);
	long long d2 = (long long)(p1.y - p2.y);
	return d1*d1 + d2*d2;
}
long long dot(Store A, Store B) { return A.x * B.x + A.y*B.y; }
long long cross(Store A, Store B) { return A.x * B.y - A.y*B.x; }
bool compare1(Store A, Store B) { return A.y == B.y ? A.x < B.x : A.y < B.y; }
bool compare2(Store A, Store B) { return cross(A - piv, B - piv) > 0; }
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		sort(p, p + n, compare1);
		piv = p[0];
		sort(p + 1, p + n, compare2);
		vector<Store> st(200001);
		st[0] = piv;
		st[1] = p[1];
		int top = 2;
		for (int i = 2; i < n; i++) {
			bool check = false;
			while (top >= 2) {
				long long c = cross(st[top - 1] - st[top - 2], p[i] - st[top - 1]);
				long long d = dot(st[top - 1] - st[top - 2], p[i] - st[top - 1]);
				if (c > 0) break;
				else if (c == 0 && d < 0) {
					check = true;
					break;
				}
				top--;
			}
			if (!check)
				st[top++] = p[i];
		}
		int x = 0, y = 0;
		long long ans = 0;
		int j = 1;
		for (int i = 0; i < st.size(); i++) {
			while (dist(st[i], st[j]) < dist(st[i], st[(j + 1) % st.size()])) {
				j = (j + 1) % st.size();
			}
			long long d = dist(st[i], st[j]);
			if (ans < d) {
				ans = d;
				x = i;
				y = j;
			}
		}
		printf("%d %d %d %d\n", st[x].x, st[x].y, st[y].x, st[y].y);
	}
	return 0;
}
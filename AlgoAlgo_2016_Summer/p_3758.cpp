#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
struct acm {
	int score[101];
	int cnt = 0;
	int Time = 0;
	int sum = 0;
};
int main() {
	int T;
	cin >> T;
	while (T--) 
	{
		vector<acm> c(101);
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		for (int i = 1; i <= m; i++) {
			int id, pn, s;
			cin >> id >> pn >> s;
			c[id].Time = i;
			c[id].cnt += 1;
			if (c[id].score[pn] < s) {
				int t = c[id].score[pn];
				c[id].score[pn] = s;
				c[id].sum += s - t;
			}
		}
		int cnt = 1;
		for (int i = 1; i <= n; i++)
			if (i != t)
				if (c[i].sum > c[t].sum)
					cnt += 1;
				else if (c[i].sum == c[t].sum)
					if (c[i].cnt < c[t].cnt)
						cnt += 1;
					else if (c[i].cnt == c[t].cnt)
						if (c[i].Time < c[t].Time)
							cnt += 1;						
		cout << cnt << endl;
	}
	return 0;
}
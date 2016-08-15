#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[1001][1001];
bool c_dfs[1001];
bool c_bfs[1001];
int main() {
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	//dfs
	stack<int> st;
	queue<int> q;
	st.push(s);
	c_dfs[st.top()] = true;
	q.push(st.top());
	while (!st.empty()) {
		bool c = false;
		for (int i = 0; i <= n; i++)
			if (c_dfs[i] == false && arr[st.top()][i] == 1) {
				st.push(i);
				q.push(i);
				c_dfs[i] = true;
				c = true;
				break;
			}
		if(!c)
			st.pop();
	}
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
	//bfs
	q.push(s);
	c_bfs[q.front()] = true;
	printf("%d ", q.front());
	while (!q.empty()) {
		for (int i = 0; i <= n; i++)
			if (c_bfs[i] == false && arr[q.front()][i] == 1) {
				printf("%d ", i);
				q.push(i);
				c_bfs[i] = true;
			}
		q.pop();
	}
	printf("\n");
	return 0;
}
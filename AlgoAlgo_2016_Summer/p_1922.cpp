#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
using namespace std;

int n, m, res;
vector<pair<int, int>> v[MAX];
int visit[MAX];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	priority_queue<pair<int, int>> q;

	visit[1] = 1;
	for (int i = 0; i<v[1].size(); i++)
		q.push(make_pair(-v[1][i].second, v[1][i].first));
	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();

		int cost = -p.first;
		int node = p.second;

		if (visit[node])
			continue;
		visit[node] = true;
		res += cost;
		for (int i = 0; i<v[node].size(); i++)
			q.push(make_pair(-v[node][i].second, v[node][i].first));
	}
	printf("%d\n", res);
	return 0;
}
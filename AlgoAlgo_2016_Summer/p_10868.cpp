#include <cstdio>
#include <cmath>
#include<iostream>
#include<algorithm>
#include <vector>
#define M 1000000001
using namespace std;
int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
		return 0;
	}
	int mid = (start + end) / 2;
	init(a, tree, 2 * node, start, mid);
	init(a, tree, 2 * node +1, mid + 1, end);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int get_min(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left <= start && right >= end) {
		return tree[node];
	}
	if (left > end || right < start) {
		return M;
	}
	return min(get_min(tree, node * 2, start, (start + end) / 2, left, right) , get_min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	for (int i = 0; i < tree_size; i++)
		tree[i] = M;
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	init(a, tree, 1, 0, n - 1);
	while (m--) {
		int t2, t3;
		scanf("%d %d", &t2, &t3);
		printf("%d\n", get_min(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
	}
	return 0;
}
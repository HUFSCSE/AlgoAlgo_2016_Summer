#include<iostream>
#include<queue>
using namespace std;
bool check[100001];
int main() {
	queue<pair<int,int> > q;
	pair<int, int> top;
	int n, k;
	cin >> n >> k;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		top = q.front();
		if (check[top.first] == true) {
			q.pop();
			continue;
		}
		check[top.first] = true;
		q.pop();
		if (top.first == k) 	break;
		if (top.first - 1 >= 0) q.push(make_pair(top.first - 1, top.second + 1));
		if (top.first + 1 <= 100000) q.push(make_pair(top.first + 1, top.second + 1));
		if (top.first * 2 <= 100000) q.push(make_pair(top.first *2, top.second + 1));
	}
	cout << top.second << endl;
	return 0;
}
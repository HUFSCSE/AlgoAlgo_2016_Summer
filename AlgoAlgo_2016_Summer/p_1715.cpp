#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		int a;
		scanf("%d", &a);
		q.push(-a);
	}
	int total = 0;
	while (!q.empty()) {
		int a = q.top();
		q.pop();
		if (q.empty())
			break;
		int b = q.top();
		q.pop();
		int c = a + b;
		q.push(c);
		total -= c;
	}
	cout << total << endl;
	return 0;
}
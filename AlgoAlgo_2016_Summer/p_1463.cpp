#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[1000001];
bool check[1000001];
int main() {
	for (int i = 0; i < 1000001; i++)
		arr[i] = 100000000;
	int n;
	cin >> n;
	queue<int> q;
	q.push(n);
	arr[n] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front == 1)
			break;
		if (check[front] == false) {
			check[front] = true;
			if (front % 3 == 0) {
				arr[front / 3] = min(arr[front/3],arr[front] + 1);
				q.push(front / 3);
			}
			if (front % 2 == 0) {
				arr[front / 2] = min(arr[front / 2], arr[front] + 1);
				q.push(front / 2);
			}
			arr[front - 1] = min(arr[front - 1], arr[front] + 1);
			q.push(front -1);
		}
	}
	cout << arr[1] << endl;
	return 0;
}
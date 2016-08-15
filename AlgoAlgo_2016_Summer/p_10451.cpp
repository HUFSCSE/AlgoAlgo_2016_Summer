#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[1001];
bool c[1001];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		stack<int> s;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!c[i]) s.push(i), c[i]=true, cnt+=1;
			while (!s.empty()) {
				int t = arr[s.top()];
				if (!c[t]) s.push(t),c[t]=true;
				else s.pop();
			}
		}
		cout << cnt << endl;
		for (int i = 1; i <= n; i++)
			arr[i]=0,c[i]=0;
	}
	return 0;
}
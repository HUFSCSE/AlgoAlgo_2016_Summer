#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool cc = false;
		for (int i = 2; i <= 64; i++) {
			int t = n;
			vector<char> v;
			while (t != 0) {
				v.push_back(t%i);
				t /= i;
			}
			int l = 0, r = v.size() - 1;
			bool c = true;
			while (l < r) {
				if (v[l] != v[r]) {
					c = false;
					break;
				}
				l += 1;
				r -= 1;
			}
			if (c) {
				cc = c;
				break;
			}
		}
		if (cc)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
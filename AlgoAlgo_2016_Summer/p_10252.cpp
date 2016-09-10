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
		int n, m;
		cin >> n >> m;
		cout << 1 << endl;
		if (n % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) 
					for (int j = 0; j < m; j++) 
						printf("(%d,%d)\n", i, j);
				else 
					for (int j = m-1; j > -1; j--)
						printf("(%d,%d)\n", i, j);
			}
		}
		else {
			for (int i = 0; i < m; i++) 
						printf("(%d,%d)\n", 0, i);
			bool t = true;
			for (int j = m - 1; j >= 0; j--) {
				if (t) {
					for (int i = 1; i < n; i++)
						printf("(%d,%d)\n", i, j);
					t = !t;
				}
				else {
					for (int i = n - 1; i > 0; i--)
						printf("(%d,%d)\n", i, j);
					t = !t;
				}
			}
		}
	}
	return 0;
}
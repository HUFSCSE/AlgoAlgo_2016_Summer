#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include <functional>
#include<utility>
#include "MinMaxHeap.h"
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		MinMaxHeap<int> h;

		int m;
		cin >> m;
		int in = 0;
		int de = 0;
		while (m--) {
			char a;
			int n;
			cin >> a >> n;
			if (a == 'I') {
				h.push(n);
				in += 1;
			}
			else {
				if (in > de) {
					de += 1;
					if (n == 1) {
						h.deleteMax();
					}
					else {
						h.deleteMin();
					}
				}
			}
		}
		if (de >= in)
			cout << "EMPTY\n";
		else {
			cout << h.getMax() << " " << h.getMin() << "\n";
		}
	}
	return 0;
}
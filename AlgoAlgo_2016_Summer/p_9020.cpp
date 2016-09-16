#include <iostream>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
const int MAX = 10000;
bool check[MAX + 1]; // true: 지워짐, false: 지워지지 않음
int main() {
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	int n;
	cin >> n;
	set<int> s;
	for (int i = 1; i <= 10000; i++) {
		if (check[i] == false) {
			//cout << i << '\n';
			s.insert(i);
		}
	}
	while (n--) {
		int t;
		cin >> t;
		int a, b, c;
		c = 1000000;
		for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
			if (s.find(t - *it) != s.end()) {
				if (abs((t - *it) - *it) < c)
					c= abs((t - *it) - *it),a = min((t - *it), *it), b = max((t - *it), *it);
			}
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
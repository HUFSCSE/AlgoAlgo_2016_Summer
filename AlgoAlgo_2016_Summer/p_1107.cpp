#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int num;
int n;
bool check[10];
int possible(int c) {
	if (c == 0) {
		if (check[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (check[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	cin >> num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		check[t] = true;
	}
	if (num == 100) {
		cout << 0 << endl;
	}
	else {
		int _min = abs(num - 100);
		for (int i = 0; i <= 1000000; i++) {
			int c = i;
			int len = possible(c);
			if (len > 0) {
				int press = abs(c - num);
				_min = min(_min, len + press);
			}
		}
		cout << _min << endl;
	}
	return 0;
}
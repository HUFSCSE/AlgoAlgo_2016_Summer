#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;

char z[101];
int main() {
	int n;
	cin >> n;
	while (n--) {
		int ret = 0;
		int t, b, p = 0, q = 0;
		string d;
		cin >> t >> b;
		for (int i = b; i >= 1; i--) {
			char x;
			cin >> x;
			d += x;
		}
		p = stoi(d);
		d.clear();
		for (int i = b; i >= 1; i--) {
			char x;
			cin >> x;
			d += x;
		}
		q = stoi(d);

		for (int i = 0; i<t; ++i)
			cin >> z[i];
		for (int k = 0; k<t; k++) {
			int a, d = b, e = k;
			string c;
			while (d--) {
				c += z[e];
				e = (e + 1) % t;
			}
			a = stoi(c);
			if (a >= p&&a <= q)
				ret++;
		}
		cout << ret << endl;
	}
	return 0;
}
#include<iostream>

using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int a, b, c;
	a = 1; b = 1; c = 1;
	int y = 1;
	while (1) {
		if (e == a && s == b && m == c)
			break;
		a += 1;
		a %= 16;
		if (a == 0)
			a += 1;
		b += 1;
		b %= 29;
		if (b == 0)
			b += 1;
		c += 1;
		c %= 20;
		if (c == 0)
			c += 1;

		y += 1;
	}
	cout << y << endl;
	return 0;
}
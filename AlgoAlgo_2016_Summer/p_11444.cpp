#include<iostream>

using namespace std;
struct matrix {
	unsigned long long data[2][2];
};
matrix mul(matrix a, matrix b) {
	matrix c;
	c.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
	c.data[0][1] = a.data[0][0] * b.data[1][0] + a.data[0][1] * b.data[1][1];

	c.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
	c.data[1][1] = a.data[1][0] * b.data[1][0] + a.data[1][1] * b.data[1][1];

	c.data[0][0] %= 1000000007;
	c.data[0][1] %= 1000000007;
	c.data[1][0] %= 1000000007;
	c.data[1][1] %= 1000000007;
	return c;
}
matrix divide_and_conquer(matrix a, unsigned long long n	) {
	if (n > 1) {
		a = divide_and_conquer(a, n / 2);
		a = mul(a, a);

		if (n % 2 != 0) {
			matrix t;
			t.data[0][0] = 1; t.data[0][1] = 1;
			t.data[1][0] = 1; t.data[1][1] = 0;
			a = mul(a, t);
		}
	}
	return a;
}
int main() {
	unsigned long long n;
	cin >> n;
	matrix a;
	a.data[0][0] = 1; a.data[0][1] = 1;
	a.data[1][0] = 1; a.data[1][1] = 0;

	a = divide_and_conquer(a, n);

	cout << a.data[0][1] << endl;

	return 0;
}
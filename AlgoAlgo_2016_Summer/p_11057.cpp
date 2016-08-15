#include<iostream>
using namespace std;
int a[1001][10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
		a[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				a[i][j] += a[i - 1][k];
				a[i][j] %= 10007;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++)
		total += a[n][i];
	total %= 10007;
	cout << total << endl;

	return 0;
}
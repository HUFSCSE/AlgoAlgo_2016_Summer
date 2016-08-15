#include<iostream>
using namespace std;

int T[1001];
int main() {
	int n;
	cin >> n;
	T[0] = 1;
	T[1] = 1;
	T[2] = 3;
	for (int i = 3; i <= n; i++) {
		T[i] = T[i - 1] + T[i - 2]*2;
		T[i] %= 10007;
	}
	cout << T[n] << endl;
	return 0;
}
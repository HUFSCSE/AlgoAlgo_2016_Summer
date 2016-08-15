#include<iostream>
using namespace std;
int fibo[46];
int main() {
	fibo[1] = 1;
	fibo[2] = 1;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	cout << fibo[n] << endl;
	return 0;
}
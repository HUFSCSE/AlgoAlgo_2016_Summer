#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int v[8];
int n;
int f() {
	int t = 0;
	for (int i = 0; i < n - 1; i++)
		t += abs(v[i] - v[i + 1]);
	return t;
}
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	sort(v, v + n);
	int m = -1;
	do {
		m = max(m, f());
	} while (next_permutation(v, v+n));
	cout << m << endl;
	return 0;
}
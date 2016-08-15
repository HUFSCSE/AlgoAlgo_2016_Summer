#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int &u, int &v) {
	return u < v;
}
int main() {
	vector<int>  v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";
	return 0;
}
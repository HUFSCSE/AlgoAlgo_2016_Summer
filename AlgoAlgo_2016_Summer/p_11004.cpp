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
	int n,k;
	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	nth_element(v.begin(), v.begin()+(k-1), v.end(), cmp);
	printf("%d\n", v[k - 1]);
	return 0;
}
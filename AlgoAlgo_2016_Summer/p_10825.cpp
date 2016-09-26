#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <set>
using namespace std;
typedef struct Studnet {
	int k;
	int e;
	int m;
	string s;
} S;
bool cmp(const S &a, const S &b) {
	if (a.k == b.k) {
		if (a.e == b.e) {
			if (a.m == b.m)
				return a.s < b.s;
			return a.m > b.m;
		}
		return a.e < b.e;
	}
	return a.k > b.k;
}
int main() {
	int n;
	cin >> n;
	S s[100000];
	for (int i = 0; i < n; i++)
		cin >> s[i].s >> s[i].k >> s[i].e >> s[i].m;
	sort(s, s + n,cmp);
	for (int i = 0; i < n; i++)
		cout << s[i].s << "\n";
	return 0;
}
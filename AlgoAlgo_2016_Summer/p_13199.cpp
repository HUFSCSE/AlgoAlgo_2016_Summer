#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;

int main() {
	int p, m, c, o;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &p, &m, &c, &o);
		int a, b;
		a = (m / p) + ((m / p)*o) / c;
		b = (m / p);
		int d = (m / p)*o;
		while ( (d/c) > 0) {
			b += d / c;
			d = (d%c) + (d / c)*o;
		}
		cout << abs(b - a) << "\n";
	}
	return 0;
}
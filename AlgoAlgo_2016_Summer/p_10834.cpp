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

int main() {
	int n;
	cin >> n;
	int a, b, c=0;
	int pre = 0;
	int r = 1;
	while (n--) {
		cin >> a >> b >> c;
		if (c == 1)
			pre = 1 - pre;
		r = (r / a)*b;
	}
	cout << pre << " " << r << endl;
	return 0;
}
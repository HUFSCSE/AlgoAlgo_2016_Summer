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
int a, b, c;
int main() {
	int n;
	cin >> n;
	a = 300;
	b = 60;
	c = 10;
	int r[3];
	r[0] = n / a;
	if (r[0] != 0)
		n = n%a;
	r[1] = n / b;
	if (r[1] != 0)
		n = n%b;
	r[2] = n / c;
	if (r[2] != 0)
		n = n%c;
	if (n != 0)
		cout << -1 << endl;
	else
		cout << r[0] << " " << r[1] << " " << r[2];
	return 0;
}
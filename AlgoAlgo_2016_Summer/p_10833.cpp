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
	int sum = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		sum += b%a;
	}
	cout << sum << endl;
	return 0;
}
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
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[10];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int cnt = 0;
	while (m > 0) {
		int i;
		for (i = n - 1; i >= 0; i--)
			if (m - arr[i] >= 0)
				break;
		cnt += 1;
		m = m - arr[i];
	}
	cout << cnt << endl;
	return 0;
}
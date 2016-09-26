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
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int arr[1000];
		memset(arr, 0, sizeof(arr));
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		double avg = (double)sum / n;
		sort(arr, arr + n);
		int k = 0;
		while (1) {
			if (k == n)
				break;
			if (avg<arr[k])
				break;
			k++;
		}
		double ratio = n - k;
		printf("%.3lf%%\n", (ratio / n) * 100);
	}
	return 0;
}
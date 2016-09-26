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
int arr[1000001];
int brr[1000001];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(brr, 0, sizeof(brr));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] > brr[i + 1]) 
				brr[i] = arr[i];
			else 
				brr[i] = brr[i+1];
		}
		long long sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == brr[i]) {
				sum += arr[i] * cnt;
				cnt = 0;
			}
			else {
				cnt += 1;
				sum -= arr[i];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
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
int arr[10];
int brr[10];
bool same(int n) {
	int s = arr[0];
	bool c = true;
	for (int i = 1; i < n; i++)
		if (s != arr[i]) c = false;
	return c;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		memset(arr, 0, sizeof(0));
		memset(brr, 0, sizeof(0));
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			if (arr[i] % 2 != 0)	 arr[i] += 1;
		for (int i = 0; i < n; i++)
			brr[(i + 1) % n] = arr[i] / 2;
		bool c = same(n);
		int cnt = 0;
		while (!c) {
			for (int i = 0; i < n; i++)
				arr[i] = arr[i]/2 + brr[i];
			for (int i = 0; i < n; i++)
				if (arr[i] % 2 != 0)	 arr[i] += 1;
			for (int i = 0; i < n; i++)
				brr[(i + 1) % n] = arr[i] / 2;
			cnt += 1;
			c = same(n);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
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
struct str {
	int size;
	int sum;
	string s;
};
bool cmp(const str &a, const str &b) {
	if (a.size == b.size) {
		if (a.sum == b.sum)
			return a.s < b.s;
		return a.sum < b.sum;
	}
	return a.size < b.size;
}
int main() {
	int n;
	cin >> n;
	str arr[1000];
	for (int i = 0; i < n; i++)
		cin >> arr[i].s;
	for (int i = 0; i < n; i++)
		arr[i].size = arr[i].s.size();
	for (int i = 0; i < n; i++) {
		arr[i].sum = 0;
		for (int j = 0; j < arr[i].size; j++) {
			if (arr[i].s[j] >= '0' && arr[i].s[j] <= '9')
				arr[i].sum += arr[i].s[j] - '0';
		}
	}
	sort(arr, arr + n,cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].s << endl;
	return 0;
}
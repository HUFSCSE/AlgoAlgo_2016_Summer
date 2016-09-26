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
int arr[101];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) 
		cin >> arr[i];
	set<int> v;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
	//	for (set<int>::iterator it = v.begin(); it != v.end(); it++)
	//		cout << *it << " ";
	//	cout << endl;
		if (v.find(arr[i]) != v.end()) {
			continue;
		}
		if (v.empty() || (v.size()<n && v.find(arr[i]) == v.end())) {
			v.insert(arr[i]);
			continue; 
		}
		set<int> tt;
		for (int j = i + 1, size = 0; j < k && size < n - 1; j++) {
			if (v.find(arr[j]) != v.end()) {
				tt.insert(arr[j]);
				size += 1;
			}
		}
		if (tt.size() == 0) {
			set<int>::iterator it = v.begin();
			v.erase(*it);
			v.insert(arr[i]);
			cnt += 1;
		}
		else {
			set<int>::iterator it2;
			for (set<int>::iterator it = v.begin(); it != v.end(); it++) {
				if (tt.find(*it) == tt.end()) {
					it2 = it;
					break;
				}
			}
			v.erase(it2);
			v.insert(arr[i]);
			cnt += 1;
		}
		tt.clear();
	}
	cout << cnt << '\n';
	return 0;
}